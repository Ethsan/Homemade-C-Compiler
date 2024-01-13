#include "tree.h"
#include "parser.tab.h"

#include <stdarg.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <err.h>
#include <stdnoreturn.h>
#include <string.h>

#define TABLE_SIZE 1009
#define PRIME 31

#define INT_TYPE_SIZE 4
#define PTR_TYPE_SIZE 4
#define LONG_TYPE_SIZE 8

#define FLOAT_TYPE_SIZE 4

#define X(node)    \
	case node: \
		return #node;
const char *tree_code_name(enum tree_code code)
{
	switch (code) {
		TREE_CODE_ENUM
	default:
		return "unexpected";
	}
}
#undef X

int is_expr(enum tree_code code)
{
	switch (code) {
	case ADDR_EXPR:
	case INDIRECT_REF:
	case PLUS_EXPR:
	case MINUS_EXPR:
	case BIN_NOT_EXPR:
	case LOG_NOT_EXPR:
	case MUL_EXPR:
	case DIV_EXPR:
	case MOD_EXPR:
	case ADD_EXPR:
	case SUB_EXPR:
	case LSHIFT_EXPR:
	case RSHIFT_EXPR:
	case LT_EXPR:
	case LE_EXPR:
	case GT_EXPR:
	case GE_EXPR:
	case EQ_EXPR:
	case NE_EXPR:
	case BIN_AND_EXPR:
	case BIN_XOR_EXPR:
	case BIN_OR_EXPR:
	case LOG_AND_EXPR:
	case LOG_OR_EXPR:
	case COND_EXPR:
	case ASSIGN_EXPR:
	case COMPOUND_EXPR:
	case RETURN_STMT:
		return 1;
	default:
		return 0;
	}
}

void print_indent(int indent)
{
	for (int i = 0; i < indent; i++)
		printf("  ");
}

void print_type(tree type)
{
	if (type == NULL) {
		printf("NULL");
		return;
	}
	switch (TREE_CODE(type)) {
	case VOID_TYPE:
		printf("void");
		break;
	case INT_TYPE:
		printf("int");
		break;
	case REAL_TYPE:
		printf("float");
		break;
	case ARRAY_TYPE:
		printf("array (%d) of ", TYPE_SIZE(type));
		print_type(TREE_TYPE(type));
		break;
	case FUNCTION_TYPE:
		printf("function returning ");
		print_type(TREE_TYPE(type));
		break;
	case STRUCT_TYPE:
		printf("struct");
		break;
	case PTR_TYPE:
		printf("pointer to ");
		print_type(TREE_TYPE(type));
		break;
	case IDENTIFIER_NODE:
		printf("%.*s", ID_LEN(type), ID_NAME(type));
		break;
	default:
		printf("Not a type %s", tree_code_name(TREE_CODE(type)));
	}
}

void print_ast(tree node, int indent, int is_chain)
{
	if (node == NULL)
		return;

	print_indent(indent);
	printf("%s", tree_code_name(TREE_CODE(node)));

	if (TREE_CODE(node) == IDENTIFIER_NODE) {
		printf(": %.*s", ID_LEN(node), ID_NAME(node));
	}
	if (TREE_CODE(node) == VARIABLE_DECL || TREE_CODE(node) == FUNCTION_DECL || TREE_CODE(node) == PARM_DECL) {
		printf(": %u", DECL_UID(node));
	}

	printf(" (");
	if (TREE_CODE(node) == TREE_LIST) {
		printf(": %s", tree_code_name(TREE_CODE(TREE_TYPE(node))));
	} else {
		print_type(TREE_TYPE(node));
	}
	printf(")");
	printf("\n");

	if (is_expr(TREE_CODE(node))) {
		for (int i = 0; i < 4; i++) {
			if (EXPR_OPERAND(node, i) != NULL) {
				print_ast(EXPR_OPERAND(node, i), indent + 1, 0);
			}
		}
	}

	if (TREE_CODE(node) == VARIABLE_DECL || TREE_CODE(node) == FUNCTION_DECL || TREE_CODE(node) == PARM_DECL) {
		print_ast(DECL_NAME(node), indent + 1, 1);
	}

	if (TREE_CODE(node) == BLOCK_NODE) {
		tree vars = BLOCK_VARS(node);
		print_indent(indent);
		printf("Variables:\n");
		print_ast(vars, indent + 1, 1);
		print_indent(indent);
		printf("Body:\n");
		print_ast(BLOCK_BODY(node), indent + 1, 1);
	}

	if (TREE_CODE(node) == FUNCTION_DECL) {
		print_ast(DECL_NAME(node), indent + 1, 1);
		print_ast(DECL_PARM_LIST(node), indent + 1, 1);
		print_ast(DECL_BODY(node), indent + 1, 1);
	}

	if (is_chain)
		print_ast(TREE_CHAIN(node), indent, 1);
}

tree identifier_table[TABLE_SIZE] = { 0 };

tree get_identifier(const char *name, int len)
{
	// Compute hash
	int hash = 0;
	for (int i = 0; i < len; i++) {
		hash = (PRIME * hash + name[i]) % TABLE_SIZE;
	}

	// Search in table
	for (tree current = identifier_table[hash]; current != NULL; current = TREE_CHAIN(current)) {
		char *current_name = ID_NAME(current);
		int current_len = ID_LEN(current);
		if (current_len == len && strncmp(name, current_name, len) == 0)
			return current;
	}

	// Add to table
	tree identifier = new_node(IDENTIFIER_NODE, NULL);
	ID_NAME(identifier) = strndup(name, len + 1);
	ID_LEN(identifier) = len;
	TREE_CHAIN(identifier) = identifier_table[hash];
	identifier_table[hash] = identifier;

	return identifier;
}

union tree_node base = { .common = { .code = BLOCK_NODE } };

tree current_context = &base;

tree iter_context = NULL;

void print_current_context(void)
{
	printf("Current context:\n");
	print_ast(current_context, 0, 1);
}

void start_context(void)
{
	current_context = new_node(BLOCK_NODE, NULL);
}

uint uid_offset = 1;

tree current_function = NULL;

static tree get_decl_in(tree id, tree block)
{
	// Search in block
	for (tree decl = BLOCK_VARS(block); decl != NULL; decl = TREE_CHAIN(decl)) {
		if (DECL_NAME(decl) == id)
			return decl;
	}
	return NULL;
}

tree get_decl(tree id)
{
	// Search from current context to global context
	for (tree current = current_context; current != NULL; current = BLOCK_SUPERBLOCK(current)) {
		tree decl = get_decl_in(id, current);
		if (decl != NULL)
			return decl;
	}
	return NULL;
}

int is_code_decl(enum tree_code code)
{
	return code == VARIABLE_DECL || code == FUNCTION_DECL || code == PARM_DECL;
}

tree emit_decl(tree decl)
{
	if (decl == NULL)
		errx(EXIT_FAILURE, "unexpected: NULL declaration");
	if (DECL_UID(decl) != 0)
		errx(EXIT_FAILURE, "unexpected: declaration already emitted !!");
	if (!is_code_decl(TREE_CODE(decl)))
		errx(EXIT_FAILURE, "unexpected: declaration is not a variable or a function");

	tree id = decl->decl.name;

	// Check if already defined
	if (get_decl_in(id, current_context) != NULL)
		errx(EXIT_FAILURE, "redefinition of '%.*s'", ID_LEN(id), ID_NAME(id));

	// Check if init is valid

	// Add to current context
	TREE_CHAIN(decl) = BLOCK_VARS(current_context);
	BLOCK_VARS(current_context) = decl;

	DECL_UID(decl) = uid_offset++;

	return decl;
}

void start_block(void)
{
	tree block = new_node(BLOCK_NODE, NULL);

	BLOCK_SUPERBLOCK(block) = current_context;

	if (BLOCK_SUBBLOCKS(current_context) == NULL)
		BLOCK_SUBBLOCKS(current_context) = block;
	else
		chain_append(BLOCK_SUBBLOCKS(current_context), block);

	current_context = block;
}

tree end_block(tree body)
{
	tree block = current_context;
	current_context = BLOCK_SUPERBLOCK(block);
	BLOCK_BODY(block) = body;
	return block;
}

// We can't have an array, a function or a struct as a return type
int valid_return_type(tree type)
{
	if (type == NULL)
		return 0;
	if (TREE_CODE(type) == ARRAY_TYPE)
		return 0;
	return 1;
}

void start_function(tree decl)
{
	if (current_function != NULL)
		errx(EXIT_FAILURE, "unexpected: nested functions are not allowed");

	if (TREE_CODE(decl) != FUNCTION_DECL)
		errx(EXIT_FAILURE, "the declaration is not a function");

	// Check return type is valid
	tree ret = TREE_TYPE(decl);
	if (!valid_return_type(ret)) {
		printf("Return type: ");
		print_type(ret);
		errx(EXIT_FAILURE, "invalid return type");
	}

	emit_decl(decl);
	current_function = decl;
	start_block();

	// Check if parameters are valid and add them to the block
	int i = 0;
	for (tree iter = DECL_PARM_LIST(decl); iter != NULL; iter = TREE_CHAIN(iter)) {
		tree parm = TREE_TYPE(iter);
		if (TREE_CODE(parm) != PARM_DECL)
			errx(EXIT_FAILURE, "unexpected: non-parameter in parameter list");

		if (DECL_NAME(parm) == NULL)
			errx(EXIT_FAILURE, "Parameter without name");

		emit_decl(parm);
		DECL_OFFSET(parm) = i++;
	}
}

tree end_function(tree body)
{
	if (current_function == NULL)
		errx(EXIT_FAILURE, "unexpected: end of function outside a function");

	tree block = end_block(body);
	DECL_BODY(current_function) = block;

	tree function = current_function;
	current_function = NULL;

	return function;
}

tree chain_append(tree chain, tree node)
{
	tree current = chain;
	while (TREE_CHAIN(current) != NULL)
		current = TREE_CHAIN(current);
	TREE_CHAIN(current) = node;

	return chain;
}

tree type_append(tree node, tree type)
{
	if (node == NULL)
		return type;

	tree current = node;
	while (TREE_TYPE(current) != NULL)
		current = TREE_TYPE(current);

	TREE_TYPE(current) = type;
	return node;
}

tree last_allocated_node;

tree new_node(enum tree_code code, tree type)
{
	tree node;
	node = malloc(sizeof(union tree_node));
	if (node == NULL)
		err(EXIT_FAILURE, "malloc");

	memset(node, 0, sizeof(union tree_node));
	TREE_CODE(node) = code;
	TREE_TYPE(node) = type;

	node->common._alloc_chain = last_allocated_node;
	last_allocated_node = node;

	return node;
}

tree free_tree(tree node)
{
	if (node == NULL)
		return NULL;

	tree chain = node->common._alloc_chain;
	free(node);
	return chain;
}

tree new_integer(uint64_t value)
{
	tree type = new_node(INT_TYPE, NULL);
	tree node = new_node(INTEGER_CST, type);
	TREE_SET_CONSTANT(node);

	INT_VALUE(node) = value;

	return node;
}

// For now suffix is ignored
tree parse_integer(const char *value, int len)
{
	tree type = new_node(INT_TYPE, NULL);
	tree node = new_node(INTEGER_CST, type);
	TREE_SET_CONSTANT(node);

	char *tmp = strndup(value, len + 1);
	INT_VALUE(node) = strtol(tmp, NULL, 10);

	free(tmp);
	return node;
}

// For now suffix is ignored
tree parse_real(const char *value, int len)
{
	tree type = new_node(REAL_TYPE, NULL);
	tree node = new_node(REAL_CST, type);
	TREE_SET_CONSTANT(node);

	char *tmp = strndup(value, len + 1);
	REAL_VALUE(node) = strtof(tmp, NULL);

	free(tmp);
	return node;
}

int is_same_type(tree type1, tree type2)
{
	if (type1 == NULL || type2 == NULL)
		return 0;

	if (TREE_CODE(type1) != TREE_CODE(type2))
		return 0;

	switch (TREE_CODE(type1)) {
	case INT_TYPE:
	case REAL_TYPE:
	case VOID_TYPE:
		return 1;
	case ARRAY_TYPE:
		if (TYPE_SIZE(type1) != TYPE_SIZE(type2))
			return 0;
		return is_same_type(TREE_TYPE(type1), TREE_TYPE(type2));
	case PTR_TYPE:
		return is_same_type(TREE_TYPE(type1), TREE_TYPE(type2));
	case FUNCTION_TYPE:
		return is_same_type(TREE_TYPE(type1), TREE_TYPE(type2));
	case STRUCT_TYPE:
		return type1 == type2;
	default:
		errx(EXIT_FAILURE, "unexpected: unknown type");
	}
}

int is_ptr(tree type)
{
	return TREE_CODE(type) == PTR_TYPE || TREE_CODE(type) == ARRAY_TYPE;
}

int is_integer(tree type)
{
	return TREE_CODE(type) == INT_TYPE;
}

int is_real(tree type)
{
	return TREE_CODE(type) == REAL_TYPE;
}

int is_compatible(tree type1, tree type2)
{
	if (type1 == NULL || type2 == NULL)
		return 0;

	if (is_integer(type1) && is_integer(type2))
		return 1;
	if (is_real(type1) && is_real(type2))
		return 1;
	if (is_ptr(type1) && is_ptr(type2))
		return 1;

	if (is_integer(type1) || is_integer(type2)) {
		if (is_ptr(type1) || is_ptr(type2))
			return 1;
		if (is_real(type1) || is_real(type2))
			return 1;

		errx(EXIT_FAILURE, "unexpected: should not be reached");
	}
	if (is_ptr(type1) || is_ptr(type2)) {
		if (is_integer(type1) || is_integer(type2))
			return 1;
		if (is_real(type1) || is_real(type2))
			return 0;

		errx(EXIT_FAILURE, "unexpected: should not be reached");
	}

	// Should not be reached
	if (is_real(type1) || is_real(type2)) {
		if (is_integer(type1) || is_integer(type2))
			return 1;
		if (is_ptr(type1) || is_ptr(type2))
			return 0;
		errx(EXIT_FAILURE, "unexpected: should not be reached");
	}

	return 0;
}

int is_constant(tree node)
{
	return TREE_IS_CONSTANT(node);
}

static char *sanitize(const char *str, int len)
{
	// Allocate enough space for the worst case
	char *tmp = malloc(len + 1);
	if (tmp == NULL)
		err(EXIT_FAILURE, "malloc");

	// Sanitize string
	int i_tmp, i_str;
	for (i_tmp = 0, i_str = 0; i_str < len; i_tmp++, i_str++) {
		if (str[i_str] == '\\') {
			switch (str[i_str + 1]) {
			case 'n':
				tmp[i_tmp] = '\n';
				break;
			case 't':
				tmp[i_tmp] = '\t';
				break;
			case 'r':
				tmp[i_tmp] = '\r';
				break;
			case '\\':
				tmp[i_tmp] = '\\';
				break;
			case '\'':
				tmp[i_tmp] = '\'';
				break;
			case '"':
				tmp[i_tmp] = '"';
				break;
			case '0': {
				// TODO error handling and fixit
				char *endptr;
				tmp[i_tmp] = strtol(str + i_str + 1, &endptr, 8);
				i_str += endptr - (str + i_str + 1);
				break;
			}
			case 'x': {
				// TODO error handling
				char *endptr;
				tmp[i_tmp] = strtol(str + i_str + 2, &endptr, 16);
				i_str += endptr - (str + i_str + 2);
				break;
			}
			default:
				tmp[i_tmp] = str[i_str + 1];
			}
			i_str++;
		} else {
			tmp[i_tmp] = str[i_str];
		}
	}

	// Add null terminator and zero the rest
	memset(tmp + i_tmp, 0, len - i_tmp + 1);

	return tmp;
}

// For now suffix is ignored
tree parse_string(const char *str, int len)
{
	// Remove L prefix and ignore it
	if (str[0] == 'L') {
		str++;
		len--;
	}

	if (str[0] != '"' || str[len - 1] != '"')
		errx(EXIT_FAILURE, "unexpected: invalid string");

	str += 1;
	len -= 2;

	char *tmp = sanitize(str, len);
	int tmp_len = strlen(tmp);

	tree type = new_node(ARRAY_TYPE, new_node(INT_TYPE, NULL));
	TYPE_SIZE(type) = tmp_len + 1;

	tree node = new_node(STRING_CST, type);
	STRING_VALUE(node) = tmp;
	STRING_LEN(node) = tmp_len + 1;

	TREE_SET_CONSTANT(node);

	return node;
}

// For now suffix is ignored
tree parse_char(const char *str, int len)
{
	// Remove L prefix and ignore it
	if (str[0] == 'L') {
		str++;
		len--;
	}

	if (str[0] != '\'' || str[len - 1] != '\'')
		errx(EXIT_FAILURE, "unexpected: invalid char");

	str += 1;
	len -= 2;

	// Get new string without escape sequences
	char *tmp = sanitize(str, len);
	int tmp_len = strlen(tmp);

	if (tmp_len != 1)
		errx(EXIT_FAILURE, "multi-character character constant");

	tree type = new_node(INT_TYPE, NULL);
	tree node = new_node(INTEGER_CST, type);
	INT_VALUE(node) = tmp[0];
	TREE_SET_CONSTANT(node);

	return node;
}

tree build_deref(tree expr)
{
	// Do simple type checks
	tree type = TREE_TYPE(expr);
	if (TREE_CODE(type) != PTR_TYPE && TREE_CODE(type) != ARRAY_TYPE)
		errx(EXIT_FAILURE, "dereferencing non-pointer type");

	tree node = new_node(INDIRECT_REF, TREE_TYPE(type));
	EXPR_OPERAND(node, 0) = expr;

	if (TREE_IS_CONSTANT(expr))
		TREE_SET_CONSTANT(node);

	return node;
}

tree build_call(tree expr, tree arg_list)
{
	// Do simple type checks
	tree type = TREE_TYPE(expr);
	if (TREE_CODE(type) != FUNCTION_TYPE)
		errx(EXIT_FAILURE, "calling non-function type");

	// Type check arguments
	tree parm_list = TYPE_PARM_LIST(type);
	while (parm_list != NULL && arg_list != NULL) {
		tree parm = TREE_TYPE(parm_list);
		tree arg = TREE_TYPE(arg_list);

		if (!is_compatible(TREE_TYPE(parm), TREE_TYPE(arg)))
			errx(EXIT_FAILURE, "incompatible type in argument passing");

		parm_list = TREE_CHAIN(parm_list);
		arg_list = TREE_CHAIN(arg_list);
	}
	if (parm_list != NULL || arg_list != NULL)
		errx(EXIT_FAILURE, "wrong number of arguments");

	tree node = new_node(CALL_EXPR, TREE_TYPE(type));
	EXPR_OPERAND(node, 0) = expr;
	EXPR_OPERAND(node, 1) = arg_list;

	return node;
}

uint64_t get_sizeof(tree type)
{
	if (type == NULL)
		return 0;
	switch (TREE_CODE(type)) {
	case VOID_TYPE:
		return 0;
	case INT_TYPE:
	case REAL_TYPE:
		return 4;
	case STRUCT_TYPE:
		errx(EXIT_FAILURE, "unexpected: unknown type");
	case ARRAY_TYPE:
		return TYPE_SIZE(type) * get_sizeof(TREE_TYPE(type));
	case FUNCTION_TYPE:
	case PTR_TYPE:
		return PTR_TYPE_SIZE;
	default:
		errx(EXIT_FAILURE, "unexpected: unknown type");
	}
}

tree get_base_type(tree type)
{
	if (type == NULL)
		return NULL;
	switch (TREE_CODE(type)) {
	case VOID_TYPE:
	case INT_TYPE:
	case REAL_TYPE:
	case STRUCT_TYPE:
		return type;
	case ARRAY_TYPE:
		return get_base_type(TREE_TYPE(type));
	case FUNCTION_TYPE:
		return new_node(PTR_TYPE, TREE_TYPE(type));
	case PTR_TYPE:
		return get_base_type(TREE_TYPE(type));
	default:
		errx(EXIT_FAILURE, "unexpected: unknown type");
	}
}

tree build_incr_expr(enum tree_code code, tree expr)
{
	tree type = TREE_TYPE(expr);

	tree node = new_node(code, type);
	EXPR_OPERAND(node, 0) = expr;
	if (is_ptr(type))
		EXPR_STEP(node) = get_sizeof(TREE_TYPE(type));
	else if (is_integer(type) || is_real(type))
		EXPR_STEP(node) = 1;
	else
		errx(EXIT_FAILURE, "unexpected: incrementing non-pointer type");

	if (TREE_IS_CONSTANT(expr))
		TREE_SET_CONSTANT(node);

	return node;
}

tree build_unary_expr(enum tree_code code, tree expr)
{
	tree node;

	switch (code) {
	case ADDR_EXPR:
		node = new_node(ADDR_EXPR, new_node(PTR_TYPE, TREE_TYPE(expr)));
		break;
	case INDIRECT_REF:
		return build_deref(expr);
	case PLUS_EXPR:
		return expr;
	case MINUS_EXPR:
		node = new_node(MINUS_EXPR, TREE_TYPE(expr));
		break;
	case BIN_NOT_EXPR:
		node = new_node(BIN_NOT_EXPR, TREE_TYPE(expr));
		break;
	case LOG_NOT_EXPR:
		node = new_node(LOG_NOT_EXPR, TREE_TYPE(expr));
		break;
	case PRE_INCR_EXPR:
	case POST_INCR_EXPR:
	case PRE_DECR_EXPR:
	case POST_DECR_EXPR:

		return build_incr_expr(code, expr);
	default:
		errx(EXIT_FAILURE, "unexpected: unknown unary expression");
	}
	EXPR_OPERAND(node, 0) = expr;

	if (TREE_IS_CONSTANT(expr))
		TREE_SET_CONSTANT(node);

	return node;
}

tree build_cast(tree type, tree expr)
{
	// TODO check if cast is valid
	tree node = new_node(CONV_EXPR, type);
	EXPR_OPERAND(node, 0) = expr;

	if (TREE_IS_CONSTANT(expr))
		TREE_SET_CONSTANT(node);

	return node;
}

tree implicit_cast(tree type, tree expr)
{
	if (is_same_type(TREE_TYPE(expr), type))
		return expr;

	return build_cast(type, expr);
}

// Only for arithmetic types
tree build_mult_expr(enum tree_code code, tree left, tree right)
{
	tree ltype = TREE_TYPE(left);
	tree rtype = TREE_TYPE(right);
	if (!is_integer(ltype) && !is_real(ltype))
		errx(EXIT_FAILURE, "multiplying non-integer type");

	if (!is_integer(rtype) && !is_real(rtype))
		errx(EXIT_FAILURE, "multiplying non-integer type");

	if (is_real(ltype) || is_real(rtype)) {
		left = implicit_cast(new_node(REAL_TYPE, NULL), left);
		right = implicit_cast(new_node(REAL_TYPE, NULL), right);
	}

	tree node = new_node(code, TREE_TYPE(left));
	EXPR_OPERAND(node, 0) = left;
	EXPR_OPERAND(node, 1) = right;
	if (TREE_IS_CONSTANT(left) && TREE_IS_CONSTANT(right))
		TREE_SET_CONSTANT(node);

	return node;
}

// Work for arithmetic and pointer types
tree build_add_expr(enum tree_code code, tree left, tree right)
{
	tree ltype = TREE_TYPE(left);
	tree rtype = TREE_TYPE(right);

	// TODO rewrite this mess
	switch (code) {
	case ADD_EXPR:
		if (is_ptr(ltype) && is_ptr(rtype))
			errx(EXIT_FAILURE, "adding pointers is not allowed");

		if (is_ptr(ltype) && is_integer(rtype)) {
			tree value = new_integer(get_sizeof(TREE_TYPE(ltype)));
			tree mult = build_mult_expr(MUL_EXPR, right, value);

			tree node = new_node(ADD_EXPR, TREE_TYPE(left));
			EXPR_OPERAND(node, 0) = left;
			EXPR_OPERAND(node, 1) = mult;
			if (TREE_IS_CONSTANT(left) && TREE_IS_CONSTANT(right))
				TREE_SET_CONSTANT(node);
			return node;
		}
		if (is_integer(ltype) && is_ptr(rtype)) {
			tree value = new_integer(get_sizeof(TREE_TYPE(rtype)));
			tree mult = build_mult_expr(MUL_EXPR, left, value);

			tree node = new_node(ADD_EXPR, TREE_TYPE(right));
			EXPR_OPERAND(node, 0) = mult;
			EXPR_OPERAND(node, 1) = right;
			if (TREE_IS_CONSTANT(left) && TREE_IS_CONSTANT(right))
				TREE_SET_CONSTANT(node);
			return node;
		}
		break;
	case SUB_EXPR:
		if (is_ptr(ltype) && is_ptr(rtype)) {
			tree lcast = build_cast(new_node(INT_TYPE, NULL), left);
			tree rcast = build_cast(new_node(INT_TYPE, NULL), right);

			tree node = new_node(SUB_EXPR, new_node(INT_TYPE, NULL));
			EXPR_OPERAND(node, 0) = lcast;
			EXPR_OPERAND(node, 1) = rcast;
			if (TREE_IS_CONSTANT(left) && TREE_IS_CONSTANT(right))
				TREE_SET_CONSTANT(node);
			return node;
		}
		if (is_ptr(ltype) && is_integer(rtype)) {
			tree value = new_integer(get_sizeof(TREE_TYPE(ltype)));
			tree mult = build_mult_expr(MUL_EXPR, right, value);

			tree node = new_node(SUB_EXPR, TREE_TYPE(left));
			EXPR_OPERAND(node, 0) = left;
			EXPR_OPERAND(node, 1) = mult;
			if (TREE_IS_CONSTANT(left) && TREE_IS_CONSTANT(right))
				TREE_SET_CONSTANT(node);
			return node;
		}
		if (is_integer(ltype) && is_ptr(rtype))
			errx(EXIT_FAILURE, "subtracting pointer from integer is not allowed");
		break;
	default:
		errx(EXIT_FAILURE, "unexpected: unknown add expression");
	}

	// Pointer have been handled, now we can do arithmetic
	if (is_ptr(ltype) || is_ptr(rtype))
		errx(EXIT_FAILURE, "Operation between pointer and float is not allowed");

	if (is_real(ltype) || is_real(rtype)) {
		left = implicit_cast(new_node(REAL_TYPE, NULL), left);
		right = implicit_cast(new_node(REAL_TYPE, NULL), right);
	}

	tree node = new_node(code, TREE_TYPE(left));
	EXPR_OPERAND(node, 0) = left;
	EXPR_OPERAND(node, 1) = right;

	if (TREE_IS_CONSTANT(left) && TREE_IS_CONSTANT(right))
		TREE_SET_CONSTANT(node);
	return node;
}

tree build_shift_expr(enum tree_code code, tree left, tree right)
{
	tree ltype = TREE_TYPE(left);
	tree rtype = TREE_TYPE(right);

	if (!is_integer(ltype))
		errx(EXIT_FAILURE, "shifting a non-integer type");
	if (!is_integer(rtype))
		errx(EXIT_FAILURE, "shifting by a non-integer type");

	tree node = new_node(code, ltype);
	EXPR_OPERAND(node, 0) = left;
	EXPR_OPERAND(node, 1) = right;

	if (TREE_IS_CONSTANT(left) && TREE_IS_CONSTANT(right))
		TREE_SET_CONSTANT(node);

	return node;
}

tree build_rel_expr(enum tree_code code, tree left, tree right)
{
	tree ltype = TREE_TYPE(left);
	tree rtype = TREE_TYPE(right);

	if (is_real(ltype) || is_real(rtype)) {
		if (is_ptr(ltype) || is_ptr(rtype))
			errx(EXIT_FAILURE, "comparing pointer with float is not allowed");

		left = implicit_cast(new_node(REAL_TYPE, NULL), left);
		right = implicit_cast(new_node(REAL_TYPE, NULL), right);
	}

	tree node = new_node(code, new_node(INT_TYPE, NULL));
	EXPR_OPERAND(node, 0) = left;
	EXPR_OPERAND(node, 1) = right;

	if (TREE_IS_CONSTANT(left) && TREE_IS_CONSTANT(right))
		TREE_SET_CONSTANT(node);

	return node;
}

tree build_bit_expr(enum tree_code code, tree left, tree right)
{
	tree ltype = TREE_TYPE(left);
	tree rtype = TREE_TYPE(right);

	if (!is_integer(ltype))
		errx(EXIT_FAILURE, "bit operation on non-integer type");
	if (!is_integer(rtype))
		errx(EXIT_FAILURE, "bit operation on non-integer type");

	tree node = new_node(code, ltype);
	EXPR_OPERAND(node, 0) = left;
	EXPR_OPERAND(node, 1) = right;

	if (TREE_IS_CONSTANT(left) && TREE_IS_CONSTANT(right))
		TREE_SET_CONSTANT(node);

	return node;
}

tree build_log_expr(enum tree_code code, tree left, tree right)
{
	left = implicit_cast(new_node(INT_TYPE, NULL), left);
	right = implicit_cast(new_node(INT_TYPE, NULL), right);

	tree node = new_node(code, new_node(INT_TYPE, NULL));
	EXPR_OPERAND(node, 0) = left;
	EXPR_OPERAND(node, 1) = right;

	if (TREE_IS_CONSTANT(left) && TREE_IS_CONSTANT(right))
		TREE_SET_CONSTANT(node);

	return node;
}

tree build_cond_expr(tree cond, tree then, tree els)
{
	cond = implicit_cast(new_node(INT_TYPE, NULL), cond);
	tree then_type = TREE_TYPE(then);
	tree else_type = TREE_TYPE(els);

	if (is_real(then_type) || is_real(else_type)) {
		if (is_ptr(then_type) || is_ptr(else_type))
			errx(EXIT_FAILURE, "Pointer and float are incompatible types in conditional expression");
		then = implicit_cast(new_node(REAL_TYPE, NULL), then);
		els = implicit_cast(new_node(REAL_TYPE, NULL), els);
	}

	tree node = new_node(COND_EXPR, TREE_TYPE(then));
	EXPR_OPERAND(node, 0) = cond;
	EXPR_OPERAND(node, 1) = then;
	EXPR_OPERAND(node, 2) = els;

	if (TREE_IS_CONSTANT(cond)) {
		; // TODO
	}

	return node;
}

tree build_assign_expr(enum tree_code code, tree left, tree right)
{
	tree ltype = TREE_TYPE(left);
	tree rtype = TREE_TYPE(right);

	if (!is_compatible(ltype, rtype))
		errx(EXIT_FAILURE, "incompatible types in assignment");

	right = implicit_cast(ltype, right);

	tree node = new_node(code, ltype);
	EXPR_OPERAND(node, 0) = left;
	EXPR_OPERAND(node, 1) = right;

	if (TREE_IS_CONSTANT(right))
		TREE_SET_CONSTANT(node);

	return node;
}

tree build_compound_expr(tree left, tree right)
{
	tree node = new_node(COMPOUND_EXPR, TREE_TYPE(right));
	EXPR_OPERAND(node, 0) = left;
	EXPR_OPERAND(node, 1) = right;

	if (TREE_IS_CONSTANT(right))
		TREE_SET_CONSTANT(node);

	return node;
}

tree build_expr(enum tree_code code, tree left, tree right)
{
	switch (code) {
	case ADDR_EXPR:
	case INDIRECT_REF:
	case PLUS_EXPR:
	case MINUS_EXPR:
	case BIN_NOT_EXPR:
	case LOG_NOT_EXPR:
		return build_unary_expr(code, left);
	case MUL_EXPR:
	case DIV_EXPR:
	case MOD_EXPR:
		return build_mult_expr(code, left, right);
	case ADD_EXPR:
	case SUB_EXPR:
		return build_add_expr(code, left, right);
	case LSHIFT_EXPR:
	case RSHIFT_EXPR:
		return build_shift_expr(code, left, right);
	case LT_EXPR:
	case LE_EXPR:
	case GT_EXPR:
	case GE_EXPR:
	case EQ_EXPR:
	case NE_EXPR:
		return build_rel_expr(code, left, right);
	case BIN_AND_EXPR:
	case BIN_XOR_EXPR:
	case BIN_OR_EXPR:
		return build_bit_expr(code, left, right);
	case LOG_AND_EXPR:
	case LOG_OR_EXPR:
		return build_log_expr(code, left, right);
	case ASSIGN_EXPR:
		return build_assign_expr(code, left, right);
	case COMPOUND_EXPR:
		return build_compound_expr(left, right);
	default:
		errx(EXIT_FAILURE, "unexpected: unknown expression");
	}
}

tree build_if(tree cond, tree yes, tree no)
{
	tree node = new_node(IF_STMT, NULL);
	EXPR_OPERAND(node, 0) = cond;
	EXPR_OPERAND(node, 1) = yes;
	EXPR_OPERAND(node, 2) = no;

	return node;
}

void start_for(tree init, tree cond, tree incr)
{
	tree node = new_node(FOR_STMT, NULL);
	ITER_INIT(node) = init;
	ITER_COND(node) = cond;
	ITER_INCR(node) = incr;

	tree list = new_node(TREE_LIST, node);
	iter_context = chain_append(list, iter_context);
}

tree end_for(tree body)
{
	if (iter_context == NULL)
		errx(EXIT_FAILURE, "unexpected: end of for outside a for");

	tree node = TREE_TYPE(iter_context);
	if (TREE_CODE(node) != FOR_STMT)
		errx(EXIT_FAILURE, "unexpected: end of for outside a for");

	ITER_BODY(node) = body;
	iter_context = TREE_CHAIN(iter_context);

	return node;
}

void start_while(tree cond)
{
	tree node = new_node(WHILE_STMT, NULL);
	ITER_COND(node) = cond;
}

tree end_while(tree body)
{
	if (iter_context == NULL)
		errx(EXIT_FAILURE, "unexpected: end of while outside a while");

	tree node = TREE_TYPE(iter_context);
	if (TREE_CODE(node) != WHILE_STMT)
		errx(EXIT_FAILURE, "unexpected: end of while outside a while");

	ITER_BODY(node) = body;
	iter_context = TREE_CHAIN(iter_context);
	return node;
}

void start_do_while()
{
	tree node = new_node(DO_WHILE_STMT, NULL);
	iter_context = chain_append(node, iter_context);
}

tree end_do_while(tree cond, tree body)
{
	if (iter_context == NULL)
		errx(EXIT_FAILURE, "unexpected: end of do-while outside a do-while");

	tree node = TREE_TYPE(iter_context);
	if (TREE_CODE(node) != DO_WHILE_STMT)
		errx(EXIT_FAILURE, "unexpected: end of do-while outside a do-while");

	ITER_COND(node) = cond;
	ITER_BODY(node) = body;
	iter_context = TREE_CHAIN(iter_context);
	return node;
}

tree build_continue(void)
{
	if (iter_context == NULL)
		errx(EXIT_FAILURE, "Continue outside a loop");
	tree node = new_node(CONTINUE_STMT, NULL);
	return node;
}

tree build_break(void)
{
	if (iter_context == NULL)
		errx(EXIT_FAILURE, "Break outside a loop");
	tree node = new_node(BREAK_STMT, NULL);
	return node;
}

tree build_return(tree expr)
{
	if (current_function == NULL)
		errx(EXIT_FAILURE, "unexpected: return outside a function");

	tree type = TREE_TYPE(current_function);
	if (expr != NULL)
		expr = implicit_cast(type, expr);

	tree node = new_node(RETURN_STMT, NULL);
	EXPR_OPERAND(node, 0) = expr;
	return node;
}

tree build_goto(tree identifier)
{
	(void)identifier;
	errx(EXIT_FAILURE, "Goto is not implemented");
}

tree build_label(tree identifier, tree stmt)
{
	(void)identifier;
	(void)stmt;
	errx(EXIT_FAILURE, "Label is not implemented");
}

tree build_case(tree expr, tree stmt)
{
	(void)expr;
	(void)stmt;
	errx(EXIT_FAILURE, "Case is not implemented");
}

tree build_default(tree stmt)
{
	(void)stmt;
	errx(EXIT_FAILURE, "Default is not implemented");
}

tree build_sizeof(tree type)
{
	tree node = new_node(INTEGER_CST, new_node(INT_TYPE, NULL));
	INT_VALUE(node) = get_sizeof(type);
	TREE_SET_CONSTANT(node);
	return node;
}

// For now operation are not supported
tree evaluate(tree expr)
{
	if (!is_constant(expr))
		errx(EXIT_FAILURE, "Can't evaluate non-constant expression");

	switch (TREE_CODE(expr)) {
	case STRING_CST:
	case REAL_CST:
	case INTEGER_CST:
		return expr;
	default:
		errx(EXIT_FAILURE, "Can't evaluate expression");
	}
}

tree build_abstract_decl(tree name)
{
	tree node = new_node(VARIABLE_DECL, NULL);
	DECL_NAME(node) = name;

	return node;
}

tree build_init_decl(tree abstract, tree init)
{
	if (abstract == NULL)
		errx(EXIT_FAILURE, "Unexpected: abstract declaration is NULL");

	DECL_BODY(abstract) = init;

	return abstract;
}

tree build_array_decl(tree abstract, tree size)
{
	if (size == NULL)
		errx(EXIT_FAILURE, "Array size must be specified");
	if (TREE_CODE(size) != INTEGER_CST)
		errx(EXIT_FAILURE, "Array size must be an integer constant");

	tree array = new_node(ARRAY_TYPE, NULL);
	TYPE_SIZE(array) = INT_VALUE(size);

	tree type = type_append(TREE_TYPE(abstract), array);
	TREE_TYPE(abstract) = type;

	return abstract;
}

tree build_function_decl(tree abstract, tree parm_list)
{
	if (abstract == NULL)
		errx(EXIT_FAILURE, "Unexpected: abstract declaration is NULL");

	// TODO check parameter list
	if (TREE_CODE(abstract) == VARIABLE_DECL && TREE_TYPE(abstract) == NULL) {
		TREE_CODE(abstract) = FUNCTION_DECL;
		DECL_PARM_LIST(abstract) = parm_list;
		return abstract;
	}

	tree function = new_node(FUNCTION_TYPE, NULL);
	TYPE_PARM_LIST(function) = parm_list;

	tree type = type_append(TREE_TYPE(abstract), function);
	TREE_TYPE(abstract) = type;

	return abstract;
}

tree build_pointer_type(tree type)
{
	return new_node(PTR_TYPE, type);
}

tree build_pointer_decl(tree abstract, tree type)
{
	if (abstract == NULL)
		errx(EXIT_FAILURE, "%s Unexpected: abstract declaration is NULL", __func__);

	// For pointer the logic is a little different
	type = type_append(type, TREE_TYPE(abstract));
	TREE_TYPE(abstract) = type;

	return abstract;
}

tree build_parm_decl(tree abstract, tree type)
{
	if (abstract == NULL)
		abstract = new_node(PARM_DECL, NULL);

	TREE_CODE(abstract) = PARM_DECL;

	type = type_append(TREE_TYPE(abstract), type);
	TREE_TYPE(abstract) = type;

	return abstract;
}

tree build_decl(tree abstract, tree type)
{
	if (abstract == NULL)
		errx(EXIT_FAILURE, "Unexpected: abstract declaration is NULL");

	type = type_append(TREE_TYPE(abstract), type);
	TREE_TYPE(abstract) = type;

	return abstract;
}
