#include "cmat_tree.h"
#include "tree.h"

#include <err.h>
#include <stdlib.h>
#include <string.h>

tree get_decl_by_name(const char* str) {
	tree id = get_identifier(str, strlen(str));
	tree decl = get_decl(id);
	if (decl == NULL) {
		errx(EXIT_FAILURE, "Declaration not found: %s", str);
	}
	return decl;
}

int is_matrix_float(tree type)
{
	return (TREE_CODE(type) == REAL_TYPE && type->common.is_lang1);
}

int is_matrix_array(tree type)
{
	if (TREE_CODE(type) != ARRAY_TYPE) {
		return 0;
	}

	tree t = TREE_TYPE(type);
	if (is_matrix_float(t)) {
		return 1;
	}
	if (TREE_CODE(t) != ARRAY_TYPE) {
		return 0;
	}

	tree t2 = TREE_TYPE(t);
	if (is_matrix_float(t2)) {
		return 1;
	}
	return 0;
}

int get_dim(tree type)
{
	if (TREE_CODE(type) != ARRAY_TYPE) {
		return 0;
	}
	tree t = TREE_TYPE(type);
	if (is_matrix_float(t)) {
		return 1;
	}
	if (TREE_CODE(t) != ARRAY_TYPE) {
		return 0;
	}
	tree t2 = TREE_TYPE(t);
	if (is_matrix_float(t2)) {
		return 2;
	}
	return -1;
}

tree cmat_build_type()
{
	tree t = new_node(REAL_TYPE, NULL);
	t->common.is_lang1 = 1;
	return t;
};

tree cmat_build_matrix_array(int r, int c)
{
	tree new_type = cmat_build_type();
	tree new_array = new_node(ARRAY_TYPE, new_type);
	TYPE_SIZE(new_array) = c;
	tree new_matrix = new_node(ARRAY_TYPE, new_array);
	TYPE_SIZE(new_matrix) = r;
	return new_matrix;
}

tree cmat_build_first_extraction(int r, int c)
{
	tree new_matrix = cmat_build_matrix_array(r, c);
	new_matrix->common.is_lang1 = 1;
	return new_matrix;
}

int is_first_extraction(tree type)
{
	return TREE_CODE(type) == ARRAY_TYPE && type->common.is_lang1;
}

int is_range(tree node)
{
	return TREE_CODE(node) == TREE_LIST && node->common.is_lang1;
}

tree cmat_build_range(tree start, tree end)
{
	if (start == NULL || end == NULL) {
		errx(EXIT_FAILURE, "Invalid range");
	}
	if (TREE_CODE(start) != INTEGER_CST || TREE_CODE(end) != INTEGER_CST) {
		errx(EXIT_FAILURE, "Invalid range: start and end must be integer");
	}
	if (INT_VALUE(start) > INT_VALUE(end)) {
		errx(EXIT_FAILURE, "Invalid range: start must be less than end");
	}
	tree list_s = new_node(TREE_LIST, start);
	tree list_e = new_node(TREE_LIST, end);
	tree t = chain_append(list_s, list_e);
	t->common.is_lang1 = 1;
	return t;
}

int get_range_len(tree range)
{
	if (!is_range(range)) {
		errx(EXIT_FAILURE, "Invalid range");
	}
	tree start = TREE_TYPE(range);
	tree end = TREE_TYPE(TREE_CHAIN(range));
	return INT_VALUE(end) - INT_VALUE(start) + 1;
}

int is_range_valid(tree range, int len)
{
	if (!is_range(range)) {
		errx(EXIT_FAILURE, "Invalid range");
	}
	tree start = TREE_TYPE(range);
	tree end = TREE_TYPE(TREE_CHAIN(range));
	return INT_VALUE(start) >= 0 && INT_VALUE(end) < (uint)len;
}

int get_total_len(tree extractor_list, int len)
{
	int total = 0;
	tree iter = extractor_list;
	while (iter != NULL) {
		tree extr = TREE_TYPE(iter);
		if (extr == NULL) {
			total += len;
		} else if (is_range(extr) && is_range_valid(extr, len)) {
			total += get_range_len(extr);
		} else if (TREE_CODE(extr) == INTEGER_CST && INT_VALUE(extr) < (uint)len) {
			total += 1;
		} else {
			errx(EXIT_FAILURE, "Invalid extractor: must an integer or range within matrix dimensions");
		}
		iter = TREE_CHAIN(iter);
	}
	return total;
}

tree build_arg_list_copy(int r_in, int c_in, int c_out, int start, int end, int off, tree out, tree in)
{
	tree arg_list = NULL;
	tree arg;
	arg = new_node(TREE_LIST, new_integer(r_in));
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, new_integer(c_in));
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, new_integer(c_out));
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, new_integer(start));
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, new_integer(end));
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, new_integer(off));
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, out);
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, in);
	arg_list = chain_append(arg_list, arg);
	return arg_list;
}

tree cmat_build_array_ref(tree array, tree extractor_list)
{
	if (array == NULL || extractor_list == NULL) {
		errx(EXIT_FAILURE, "Invalid array ref");
	}
	if (TREE_CODE(extractor_list) != TREE_LIST) {
		errx(EXIT_FAILURE, "Invalid extractor list");
	}
	tree first = TREE_TYPE(extractor_list);

	// Check if regular array ref
	if (first != NULL && !is_range(first) && TREE_CHAIN(extractor_list) == NULL) {
		return build_array_ref(array, first);
	}

	tree type = TREE_TYPE(array);
	print_current_context();
	// Check if array is a matrix
	int dim = get_dim(type);
	if (dim <= 0) {
		errx(EXIT_FAILURE, "Cannot apply extractor to non-matrix");
	}

	int array_r = dim == 2 ? TYPE_SIZE(type) : 1;
	int array_c = dim == 2 ? TYPE_SIZE(TREE_TYPE(type)) : TYPE_SIZE(type);

	int total_len = get_total_len(extractor_list, array_r);

	tree expr = NULL;
	if (!is_first_extraction(type)) {
		int anon_r = total_len;
		int anon_c = array_c;

		tree new_matrix = cmat_build_first_extraction(anon_r, anon_c);
		tree anon_decl = new_node(VARIABLE_DECL, new_matrix);
		emit_decl(anon_decl);

		tree copy_row_ident = get_decl_by_name("mat_copy_row");

		int off = 0;
		for (tree iter = extractor_list; iter != NULL; iter = TREE_CHAIN(iter)) {
			tree extr = TREE_TYPE(iter);
			tree arg_list = NULL;
			if (extr == NULL) {
				arg_list = build_arg_list_copy(array_r, array_c, anon_c, 0, array_r, off, new_matrix,
							       array);
				off += array_r;
			} else if (is_range(extr)) {
				int start = INT_VALUE(TREE_TYPE(extr));
				int end = INT_VALUE(TREE_TYPE(TREE_CHAIN(extr)));
				arg_list =
					build_arg_list_copy(array_r, array_c, anon_c, start, end, 0, new_matrix, array);
				off += end - start + 1;
			} else if (TREE_CODE(extr) == INTEGER_CST) {
				int val = INT_VALUE(extr);
				arg_list = build_arg_list_copy(array_r, array_c, anon_c, val, val + 1, 0, new_matrix,
							       array);
				off += 1;
			} else {
				errx(EXIT_FAILURE,
				     "Invalid extractor: must an integer or range within matrix dimensions");
			}
			if (expr == NULL) {
				expr = build_expr(CALL_EXPR, copy_row_ident, arg_list);
			} else {
				expr = build_expr(COMPOUND_EXPR, expr, build_expr(CALL_EXPR, copy_row_ident, arg_list));
			}
		}
		expr = build_expr(COMPOUND_EXPR, expr, new_matrix);
	} else {
		int anon_r = array_r;
		int anon_c = total_len;

		tree new_matrix = cmat_build_first_extraction(anon_r, anon_c);
		tree anon_decl = new_node(VARIABLE_DECL, new_matrix);
		emit_decl(anon_decl);

		tree copy_col_ident = get_decl_by_name("mat_copy_col");

		int off = 0;
		for (tree iter = extractor_list; iter != NULL; iter = TREE_CHAIN(iter)) {
			tree extr = TREE_TYPE(iter);
			tree arg_list = NULL;
			if (extr == NULL) {
				arg_list = build_arg_list_copy(array_r, array_c, anon_c, 0, array_c, off, new_matrix,
							       array);
				off += array_c;
			} else if (is_range(extr)) {
				int start = INT_VALUE(TREE_TYPE(extr));
				int end = INT_VALUE(TREE_TYPE(TREE_CHAIN(extr)));
				arg_list =
					build_arg_list_copy(array_r, array_c, anon_c, start, end, 0, new_matrix, array);
				off += end - start + 1;
			} else if (TREE_CODE(extr) == INTEGER_CST) {
				int val = INT_VALUE(extr);
				arg_list = build_arg_list_copy(array_r, array_c, anon_c, val, val + 1, 0, new_matrix,
							       array);
				off += 1;
			} else {
				errx(EXIT_FAILURE,
				     "Invalid extractor: must an integer or range within matrix dimensions");
			}
			if (expr == NULL) {
				expr = build_expr(CALL_EXPR, copy_col_ident, arg_list);
			} else {
				expr = build_expr(COMPOUND_EXPR, expr, build_expr(CALL_EXPR, copy_col_ident, arg_list));
			}
		}
		expr = build_expr(COMPOUND_EXPR, expr, new_matrix);
	}
	return expr;
}

tree build_arg_list_trans(int r, int c, tree out, tree in)
{
	tree arg_list = NULL;
	tree arg;
	arg = new_node(TREE_LIST, new_integer(r));
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, new_integer(c));
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, out);
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, in);
	arg_list = chain_append(arg_list, arg);
	return arg_list;
}

tree cmat_build_unary_expr(enum tree_code code, tree expr)
{
	if (!is_matrix_array(TREE_TYPE(expr))) {
		return build_unary_expr(code, expr);
	}
	tree type = TREE_TYPE(expr);
	int dim = get_dim(TREE_TYPE(expr));
	int row = dim == 2 ? TYPE_SIZE(type) : 1;
	int col = dim == 2 ? TYPE_SIZE(TREE_TYPE(type)) : TYPE_SIZE(type);
	switch (code) {
	case BIN_NOT_EXPR: {
		tree mat = cmat_build_matrix_array(row, col);
		tree ident = get_decl_by_name("mat_transpose");
		tree anon = new_node(VARIABLE_DECL, mat);
		emit_decl(anon);

		tree arg_list = build_arg_list_trans(row, col, anon, expr);
		tree call = build_expr(CALL_EXPR, ident, arg_list);
		return build_expr(COMPOUND_EXPR, call, anon);
	}
	default:
		return build_unary_expr(code, expr);
	}
}

int is_matrix_same_size(tree left, tree right)
{
	if (!is_matrix_array(TREE_TYPE(left)) || !is_matrix_array(TREE_TYPE(right))) {
		return 0;
	}
	tree left_type = TREE_TYPE(left);
	tree right_type = TREE_TYPE(right);

	int left_dim = get_dim(left_type);
	int right_dim = get_dim(right_type);
	if (left_dim != right_dim) {
		return 0;
	}
	if (left_dim == 1) {
		return TYPE_SIZE(left_type) == TYPE_SIZE(right_type);
	}
	return TYPE_SIZE(left_type) == TYPE_SIZE(right_type) &&
	       TYPE_SIZE(TREE_TYPE(left_type)) == TYPE_SIZE(TREE_TYPE(right_type));
}

tree build_get_arg_list_sum(int r, int c, tree out, tree left, tree right)
{
	tree arg_list = NULL;
	tree arg;
	arg = new_node(TREE_LIST, new_integer(r));
	arg_list = arg;
	arg = new_node(TREE_LIST, new_integer(c));
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, out);
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, left);
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, right);
	arg_list = chain_append(arg_list, arg);
	return arg_list;
}

tree build_get_arg_list_mul(int r1, int c1, int r2, int c2, tree out, tree left, tree right)
{
	tree arg_list = NULL;
	tree arg;
	arg = new_node(TREE_LIST, new_integer(r1));
	arg_list = arg;
	arg = new_node(TREE_LIST, new_integer(c1));
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, new_integer(r2));
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, new_integer(c2));
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, out);
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, left);
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, right);
	arg_list = chain_append(arg_list, arg);
	return arg_list;
}

tree cmat_build_expr(enum tree_code code, tree left, tree right)
{
	if (!is_matrix_array(TREE_TYPE(left)) || !is_matrix_array(TREE_TYPE(right))) {
		return build_expr(code, left, right);
	}
	tree ltype = TREE_TYPE(left);
	int ldim = get_dim(TREE_TYPE(left));
	int lrow = ldim == 2 ? TYPE_SIZE(ltype) : 1;
	int lcol = ldim == 2 ? TYPE_SIZE(TREE_TYPE(ltype)) : TYPE_SIZE(ltype);
	tree rtype = TREE_TYPE(right);
	int rdim = get_dim(TREE_TYPE(right));
	int rrow = rdim == 2 ? TYPE_SIZE(rtype) : 1;
	int rcol = rdim == 2 ? TYPE_SIZE(TREE_TYPE(rtype)) : TYPE_SIZE(rtype);
	switch (code) {
	case ADD_EXPR: {
		if (!is_matrix_same_size(left, right)) {
			errx(EXIT_FAILURE, "Matrix addition requires matrices of the same size");
		}
		tree matrix = cmat_build_matrix_array(lrow, lcol);
		tree anon = new_node(VARIABLE_DECL, matrix);
		emit_decl(anon);
		tree ident = get_decl_by_name("mat_sum");
		tree arg_list = build_get_arg_list_sum(lrow, lcol, anon, left, right);
		tree call = build_expr(CALL_EXPR, ident, arg_list);
		tree expr = build_expr(COMPOUND_EXPR, call, anon);
		return expr;
	}
	case SUB_EXPR: {
		if (!is_matrix_same_size(left, right)) {
			errx(EXIT_FAILURE, "Matrix subtraction requires matrices of the same size");
		}
		tree matrix = cmat_build_matrix_array(lrow, lcol);
		tree anon = new_node(VARIABLE_DECL, matrix);
		emit_decl(anon);
		tree ident = get_decl_by_name("mat_sub");
		tree arg_list = build_get_arg_list_sum(lrow, lcol, anon, left, right);
		tree call = build_expr(CALL_EXPR, ident, arg_list);
		tree expr = build_expr(COMPOUND_EXPR, call, anon);
		return expr;
	}
	case MUL_EXPR: {
		if (lcol != rrow) {
			errx(EXIT_FAILURE,
			     "Matrix multiplication requires left matrix columns to equal right matrix rows");
		}
		tree matrix = cmat_build_matrix_array(lrow, rcol);
		tree anon = new_node(VARIABLE_DECL, matrix);
		emit_decl(anon);
		tree ident = get_decl_by_name("mat_mul");
		tree arg_list = build_get_arg_list_mul(lrow, lcol, rrow, rcol, anon, left, right);
		tree call = build_expr(CALL_EXPR, ident, arg_list);
		tree expr = build_expr(COMPOUND_EXPR, call, anon);
		return expr;
	}
	case ASSIGN_EXPR: {
		if (!is_matrix_same_size(left, right)) {
			errx(EXIT_FAILURE, "Matrix assignment requires matrices of the same size");
		}
		tree matrix = cmat_build_matrix_array(lrow, lcol);
		tree ident = get_decl_by_name("mat_copy");
		tree arg_list = build_get_arg_list_sum(lrow, lcol, matrix, left, right);
		tree call = build_expr(CALL_EXPR, ident, arg_list);
		tree expr = build_expr(COMPOUND_EXPR, call, matrix);
		return expr;
	}
	default:
		return build_expr(code, left, right);
	}
}

tree cmat_build_print_mat(tree matrix)
{
	tree type = TREE_TYPE(matrix);
	int dim = get_dim(type);
	int row = dim == 2 ? TYPE_SIZE(type) : 1;
	int col = dim == 2 ? TYPE_SIZE(TREE_TYPE(type)) : TYPE_SIZE(type);
	tree ident = get_decl_by_name("mat_print");
	tree arg_list = NULL;
	tree arg;
	arg = new_node(TREE_LIST, new_integer(row));
	arg_list = arg;
	arg = new_node(TREE_LIST, new_integer(col));
	arg_list = chain_append(arg_list, arg);
	arg = new_node(TREE_LIST, matrix);
	arg_list = chain_append(arg_list, arg);
	return build_expr(CALL_EXPR, ident, arg_list);
}
