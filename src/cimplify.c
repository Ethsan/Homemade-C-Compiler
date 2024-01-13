#include "tree.h"
#include "cimple.h"

#include <err.h>
#include <stdlib.h>

// Use a program counter to generate unique ID for operation
uint pc = 0;

// Use a stack to keep track of temporaries
struct {
	uint uids[1000];
	int off;
} stack;

uint push_named_reg(uint uid)
{
	int idx = stack.off++;
	stack.uids[idx] = uid;
	return idx;
}

uint push_anon_reg(void)
{
	return push_named_reg(UINT32_MAX);
}

void pop_reg()
{
	stack.off--;
}

uint get_named_reg(uint uid)
{
	for (int i = stack.off - 1; i >= 0; i--) {
		if (stack.uids[i] == uid)
			return i;
	}
	return UINT32_MAX;
}

union s {
	uint32_t u;
	float f;
};

void cimplify_block(struct cimple_function *func, tree block);

void cimplify_expr(struct cimple_function *func, tree expr, uint ret);

void cimplify_if(struct cimple_function *func, tree stmt);

void cimplify_while(struct cimple_function *func, tree stmt);

void cimplify_for(struct cimple_function *func, tree stmt);

void cimplify_do_while(struct cimple_function *func, tree stmt);

void cimplify_return(struct cimple_function *func, tree stmt)
{
	if (TREE_CODE(stmt) != RETURN_STMT)
		errx(EXIT_FAILURE, "cimplify_return: not a return statement");

	tree expr = EXPR_OPERAND(stmt, 0);
	if (expr == NULL) {
		struct cimple_instr instr = {
			.op = OP_RETURN,
			.uid = pc++,
			.scope_1 = CIMPLE_CONST,
			.arg1 = 0,
		};
		cimple_push_instr(func, instr);
		return;
	}
	uint reg = push_anon_reg();
	cimplify_expr(func, expr, reg);
	struct cimple_instr instr = {
		.op = OP_RETURN,
		.uid = pc++,
		.scope_1 = CIMPLE_LOCAL,
		.arg1 = reg,
	};
	cimple_push_instr(func, instr);
	pop_reg();
}

void cimplify_stmt(struct cimple_function *func, tree stmt)
{
	switch (TREE_CODE(stmt)) {
	case BLOCK_NODE:
		cimplify_block(func, stmt);
		break;
	case IF_STMT:
		cimplify_if(func, stmt);
		break;
	case WHILE_STMT:
		cimplify_while(func, stmt);
		break;
	case FOR_STMT:
		cimplify_for(func, stmt);
		break;
	case DO_WHILE_STMT:
		cimplify_do_while(func, stmt);
		break;
	case RETURN_STMT:
		cimplify_return(func, stmt);
		break;
	default:
		cimplify_expr(func, stmt, UINT32_MAX);
		break;
	}
}

void cimplify_rel(struct cimple_function *func, enum cimple_op op, tree left, tree right, uint ret)
{
	int is_float = is_real(TREE_TYPE(left));

	uint reg_left = push_anon_reg();
	uint reg_right = push_anon_reg();
	cimplify_expr(func, left, reg_left);
	cimplify_expr(func, right, reg_right);
	struct cimple_instr instr1 = {
		.op = OP_ASSIGN,
		.uid = pc++,
		.scope_ret = CIMPLE_LOCAL,
		.ret = ret,
		.scope_1 = CIMPLE_CONST,
		.arg1 = 1,
	};
	int uid = pc++;
	struct cimple_instr instr2 = {
		.op = op,
		.uid = uid,
		.scope_ret = CIMPLE_UID,
		.ret = uid + 2, // Jump to instr4
		.scope_1 = CIMPLE_LOCAL,
		.arg1 = reg_left,
		.scope_2 = CIMPLE_LOCAL,
		.arg2 = reg_right,

		.is_float = is_float,
	};
	struct cimple_instr instr3 = {
		.op = OP_ASSIGN,
		.uid = pc++,
		.scope_ret = CIMPLE_LOCAL,
		.ret = ret,
		.scope_1 = CIMPLE_CONST,
		.arg1 = 0,
	};
	cimple_push_instr(func, instr1);
	cimple_push_instr(func, instr2);
	cimple_push_instr(func, instr3);
	pop_reg();
	pop_reg();
}

void cimplify_log(struct cimple_function *func, enum cimple_op op, tree left, tree right, uint ret)
{
	cimplify_expr(func, left, ret);
	struct cimple_instr instr1 = {
		.op = OP_CONVERT_BOOL,
		.uid = pc++,
		.scope_ret = CIMPLE_LOCAL,
		.ret = ret,
		.scope_1 = CIMPLE_LOCAL,
		.arg1 = ret,
	};
	uint reg = push_anon_reg();
	cimplify_expr(func, right, reg);
	struct cimple_instr instr2 = {
		.op = OP_CONVERT_BOOL,
		.uid = pc++,
		.scope_ret = CIMPLE_LOCAL,
		.ret = reg,
		.scope_1 = CIMPLE_LOCAL,
		.arg1 = reg,
	};
	struct cimple_instr instr3 = {
		.op = op,
		.uid = pc++,
		.scope_ret = CIMPLE_LOCAL,
		.ret = ret,
		.scope_1 = CIMPLE_LOCAL,
		.arg1 = ret,
		.scope_2 = CIMPLE_LOCAL,
		.arg2 = reg,
	};
	cimple_push_instr(func, instr1);
	cimple_push_instr(func, instr2);
	cimple_push_instr(func, instr3);
	pop_reg();
}

void cimplify_assign_expr(struct cimple_function *func, tree to, uint from)
{
	int is_float = is_real(TREE_TYPE(to));

	switch (TREE_CODE(to)) {
	case VARIABLE_DECL: {
		struct cimple_instr instr = {
			.op = OP_ASSIGN,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = get_named_reg(DECL_UID(to)),
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = from,
			.is_float = is_float,
		};
		cimple_push_instr(func, instr);
		break;
	}
	case INDIRECT_REF: {
		uint reg = push_anon_reg();
		cimplify_expr(func, EXPR_OPERAND(to, 0), reg);
		struct cimple_instr instr = {
			.op = OP_ST,
			.uid = pc++,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = reg,
			.scope_2 = CIMPLE_LOCAL,
			.arg2 = from,
			.is_float = is_float,
		};
		cimple_push_instr(func, instr);
		pop_reg();
		break;
	}
	default:
		errx(EXIT_FAILURE, "cimplify_assign: unknown assignment");
	}
}

void cimplify_expr(struct cimple_function *func, tree expr, uint ret)
{
	if (expr == NULL)
		return;
	tree type = TREE_TYPE(expr);
	int is_float = is_real(type);

	switch (TREE_CODE(expr)) {
	case INTEGER_CST: {
		struct cimple_instr instr = {
			.op = OP_ASSIGN,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_2 = CIMPLE_CONST,
			.arg2 = INT_VALUE(expr),
		};
		cimple_push_instr(func, instr);
		break;
	}
	case REAL_CST: {
		struct cimple_instr instr = {
			.op = OP_ASSIGN,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_2 = CIMPLE_CONST,
			.arg2 = REAL_VALUE(expr),
			.is_float = 1,
		};
		cimple_push_instr(func, instr);
		break;
	}
	case PLUS_EXPR:
		cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
		break;
	case MINUS_EXPR: {
		cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
		struct cimple_instr instr = {
			.op = OP_NEG,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = ret,
		};
		cimple_push_instr(func, instr);
		break;
	}
	case ADD_EXPR: {
		cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
		uint reg = push_anon_reg();
		cimplify_expr(func, EXPR_OPERAND(expr, 1), reg);
		struct cimple_instr instr = {
			.op = OP_ADD,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = reg,
			.scope_2 = CIMPLE_LOCAL,
			.arg2 = reg,

			.is_float = 1,
		};
		cimple_push_instr(func, instr);
		pop_reg();
		break;
	}
	case SUB_EXPR: {
		cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
		uint reg = push_anon_reg();
		cimplify_expr(func, EXPR_OPERAND(expr, 1), reg);
		struct cimple_instr instr = {
			.op = OP_SUB,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = ret,
			.scope_2 = CIMPLE_LOCAL,
			.arg2 = reg,

			.is_float = 1,
		};
		cimple_push_instr(func, instr);
		pop_reg();
		break;
	}
	case MUL_EXPR: {
		cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
		uint reg = push_anon_reg();
		cimplify_expr(func, EXPR_OPERAND(expr, 1), reg);
		struct cimple_instr instr = {
			.op = OP_MUL,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = ret,
			.scope_2 = CIMPLE_LOCAL,
			.arg2 = reg,

			.is_float = 1,
		};
		cimple_push_instr(func, instr);
		pop_reg();
		break;
	}
	case DIV_EXPR: {
		cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
		uint reg = push_anon_reg();
		cimplify_expr(func, EXPR_OPERAND(expr, 1), reg);
		struct cimple_instr instr = {
			.op = OP_DIV,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = ret,
			.scope_2 = CIMPLE_LOCAL,
			.arg2 = reg,

			.is_float = 1,
		};
		cimple_push_instr(func, instr);
		pop_reg();
		break;
	}
	case MOD_EXPR: {
		cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
		uint reg = push_anon_reg();
		cimplify_expr(func, EXPR_OPERAND(expr, 1), reg);
		struct cimple_instr instr = {
			.op = OP_MOD,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = ret,
			.scope_2 = CIMPLE_LOCAL,
			.arg2 = reg,
		};
		cimple_push_instr(func, instr);
		pop_reg();
		break;
	}
	case EQ_EXPR: {
		if (is_float) {
			cimplify_rel(func, OP_EQ_EQ, EXPR_OPERAND(expr, 0), EXPR_OPERAND(expr, 1), ret);
		} else {
			cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
			uint reg = push_anon_reg();
			cimplify_expr(func, EXPR_OPERAND(expr, 1), reg);
			struct cimple_instr instr = {
				.op = OP_XOR,
				.uid = pc++,
				.scope_ret = CIMPLE_LOCAL,
				.ret = ret,
				.scope_1 = CIMPLE_LOCAL,
				.arg1 = reg,
			};
			struct cimple_instr instr2 = {
				.op = OP_CONVERT_BOOL,
				.uid = pc++,
				.scope_ret = CIMPLE_LOCAL,
				.ret = ret,
				.scope_1 = CIMPLE_LOCAL,
				.arg1 = ret,
			};
			cimple_push_instr(func, instr);
			cimple_push_instr(func, instr2);
			pop_reg();
		}
		break;
	}
	case NE_EXPR: {
		if (is_float) {
			cimplify_rel(func, OP_NOT_EQ, EXPR_OPERAND(expr, 0), EXPR_OPERAND(expr, 1), ret);
		} else {
			cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
			uint reg = push_anon_reg();
			cimplify_expr(func, EXPR_OPERAND(expr, 1), reg);
			struct cimple_instr instr = {
				.op = OP_XOR,
				.uid = pc++,
				.scope_ret = CIMPLE_LOCAL,
				.ret = ret,
				.scope_1 = CIMPLE_LOCAL,
				.arg1 = reg,
			};
			struct cimple_instr instr2 = {
				.op = OP_CONVERT_BOOL,
				.uid = pc++,
				.scope_ret = CIMPLE_LOCAL,
				.ret = ret,
				.scope_1 = CIMPLE_LOCAL,
				.arg1 = ret,
			};
			struct cimple_instr instr3 = {
				.op = OP_NOT,
				.uid = pc++,
				.scope_ret = CIMPLE_LOCAL,
				.ret = ret,
				.scope_1 = CIMPLE_LOCAL,
				.arg1 = ret,
			};
			cimple_push_instr(func, instr);
			cimple_push_instr(func, instr2);
			cimple_push_instr(func, instr3);
			pop_reg();
		}
		break;
	}
	case LT_EXPR:
		cimplify_rel(func, OP_LESS, EXPR_OPERAND(expr, 0), EXPR_OPERAND(expr, 1), ret);
		break;
	case LE_EXPR:
		cimplify_rel(func, OP_LESS_EQ, EXPR_OPERAND(expr, 0), EXPR_OPERAND(expr, 1), ret);
		break;
	case GT_EXPR:
		cimplify_rel(func, OP_GREATER, EXPR_OPERAND(expr, 0), EXPR_OPERAND(expr, 1), ret);
		break;
	case GE_EXPR:
		cimplify_rel(func, OP_GREATER_EQ, EXPR_OPERAND(expr, 0), EXPR_OPERAND(expr, 1), ret);
		break;
	case LOG_AND_EXPR:
		cimplify_log(func, OP_AND, EXPR_OPERAND(expr, 0), EXPR_OPERAND(expr, 1), ret);
		break;
	case LOG_OR_EXPR:
		cimplify_log(func, OP_OR, EXPR_OPERAND(expr, 0), EXPR_OPERAND(expr, 1), ret);
		break;
	case LOG_NOT_EXPR:
		cimplify_log(func, OP_NOT, EXPR_OPERAND(expr, 0), EXPR_OPERAND(expr, 1), ret);
		break;
	case TRUTH_EXPR:
		cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
		struct cimple_instr instr = {
			.op = OP_CONVERT_BOOL,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = ret,
		};
		cimple_push_instr(func, instr);
		break;
	case PRE_INCR_EXPR: {
		uint reg = push_anon_reg();
		struct cimple_instr instr = {
			.op = OP_ADD,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = reg,
			.scope_2 = CIMPLE_CONST,
			.arg2 = EXPR_STEP(expr),
		};
		cimple_push_instr(func, instr);
		cimplify_assign_expr(func, EXPR_OPERAND(expr, 0), ret);
		pop_reg();
		break;
	}
	case PRE_DECR_EXPR: {
		uint reg = push_anon_reg();
		struct cimple_instr instr = {
			.op = OP_SUB,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = reg,
			.scope_2 = CIMPLE_CONST,
			.arg2 = EXPR_STEP(expr),
		};
		cimple_push_instr(func, instr);
		cimplify_assign_expr(func, EXPR_OPERAND(expr, 0), ret);
		pop_reg();
		break;
	}
	case POST_INCR_EXPR: {
		uint reg = push_anon_reg();
		cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
		struct cimple_instr instr = {
			.op = OP_ADD,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = reg,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = ret,
			.scope_2 = CIMPLE_CONST,
			.arg2 = EXPR_STEP(expr),
		};
		cimple_push_instr(func, instr);
		cimplify_assign_expr(func, EXPR_OPERAND(expr, 0), reg);
		pop_reg();
		break;
	}
	case POST_DECR_EXPR: {
		uint reg = push_anon_reg();
		cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
		struct cimple_instr instr = {
			.op = OP_SUB,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = reg,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = ret,
			.scope_2 = CIMPLE_CONST,
			.arg2 = EXPR_STEP(expr),
		};
		cimple_push_instr(func, instr);
		cimplify_assign_expr(func, EXPR_OPERAND(expr, 0), reg);
		pop_reg();
		break;
	}
	case INDIRECT_REF: {
		uint reg = push_anon_reg();
		cimplify_expr(func, EXPR_OPERAND(expr, 0), reg);
		struct cimple_instr instr = {
			.op = OP_LD,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = reg,
			.is_float = is_float,
		};
		cimple_push_instr(func, instr);
		pop_reg();
		break;
	}
	case COMPOUND_EXPR: {
		cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
		cimplify_expr(func, EXPR_OPERAND(expr, 1), ret);
		break;
	}
	case COND_EXPR:
		cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
		struct cimple_instr cond = {
			.op = OP_EQ_EQ,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = 0, // Not defined yet
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = ret,
			.scope_2 = CIMPLE_CONST,
			.arg2 = 0,
		};

		int idx_cond = cimple_push_instr(func, cond);
		cimplify_expr(func, EXPR_OPERAND(expr, 1), ret);
		struct cimple_instr jmp = {
			.op = OP_GOTO,
			.uid = pc++,
			.scope_1 = CIMPLE_CONST,
			.arg1 = 0, // Not defined yet
		};
		int idx_jmp = cimple_push_instr(func, jmp);
		func->instrs[idx_cond].ret = pc;
		cimplify_expr(func, EXPR_OPERAND(expr, 2), ret);
		func->instrs[idx_jmp].arg1 = pc;
		break;
	case CONV_EXPR: {
		cimplify_expr(func, EXPR_OPERAND(expr, 0), ret);
		struct cimple_instr instr = {
			.op = is_float ? OP_CONVERT_TO_FLOAT : OP_CONVERT_TO_INT,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = ret,
		};
		cimple_push_instr(func, instr);
		break;
	}
	case ASSIGN_EXPR: {
		uint reg = push_anon_reg();
		cimplify_expr(func, EXPR_OPERAND(expr, 1), reg);
		cimplify_assign_expr(func, EXPR_OPERAND(expr, 0), reg);
		pop_reg();
		break;
	}
	case CALL_EXPR: {
		int depth = 0;
		tree parm_list = EXPR_OPERAND(expr, 1);
		for (tree iter = parm_list; iter != NULL; iter = TREE_CHAIN(iter)) {
			depth++;
		}
		uint regs[depth];
		int i = 0;
		for (tree iter = parm_list; iter != NULL; iter = TREE_CHAIN(iter)) {
			regs[i] = push_anon_reg();
			cimplify_expr(func, TREE_TYPE(iter), regs[i]);
			i++;
		}
		for (int i = depth - 1; i >= 0; i--) {
			struct cimple_instr instr = {
				.op = OP_PARAM,
				.uid = pc++,
				.scope_1 = CIMPLE_LOCAL,
				.arg1 = regs[i],
			};
			cimple_push_instr(func, instr);
			pop_reg();
		}
		tree decl = EXPR_OPERAND(expr, 0);
		if (TREE_CODE(decl) != FUNCTION_DECL)
			errx(EXIT_FAILURE, "cimplify_expr: not a function");
		struct cimple_instr instr = {
			.op = OP_CALL,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = ret,
			.scope_1 = CIMPLE_UID,
			.arg1 = DECL_UID(decl),
		};
		cimple_push_instr(decl, instr);
		pop_reg();
		break;
	}
	}
}

void cimplify_while(struct cimple_function *func, tree stmt)
{
	if (TREE_CODE(stmt) != WHILE_STMT)
		errx(EXIT_FAILURE, "cimplify_while: not a while statement");

	tree cond = ITER_COND(stmt);
	tree body = ITER_BODY(stmt);
	int start = pc;

	int cond_reg = push_anon_reg();
	cimplify_expr(func, cond, cond_reg);
	struct cimple_instr cond_instr = {
		.op = OP_EQ_EQ,
		.uid = pc++,
		.scope_1 = CIMPLE_LOCAL,
		.arg1 = cond_reg,
		.scope_2 = CIMPLE_CONST,
		.arg2 = 0, // Constant 0
		.scope_ret = CIMPLE_UID,
		.ret = 0, // Not defined yet
	};
	pop_reg();
	int cond_idx = cimple_push_instr(func, cond_instr);

	cimplify_stmt(func, body);
	struct cimple_instr jmp = {
		.op = OP_GOTO,
		.uid = pc++,
		.scope_1 = CIMPLE_CONST,
		.arg1 = start,
	};
	cimple_push_instr(func, jmp);
	func->instrs[cond_idx].ret = pc;
}

void cimplify_do_while(struct cimple_function *func, tree stmt)
{
	if (TREE_CODE(stmt) != DO_WHILE_STMT)
		errx(EXIT_FAILURE, "cimplify_do_while: not a do while statement");
	tree cond = ITER_COND(stmt);
	tree body = ITER_BODY(stmt);

	int start = pc;
	cimplify_stmt(func, body);
	int cond_reg = push_anon_reg();
	cimplify_expr(func, cond, cond_reg);
	struct cimple_instr cond_instr = {
		.op = OP_NOT_EQ,
		.uid = pc++,
		.scope_1 = CIMPLE_LOCAL,
		.arg1 = cond_reg,
		.scope_2 = CIMPLE_CONST,
		.arg2 = 0, // Constant 0
		.scope_ret = CIMPLE_UID,
		.ret = start,
	};
	pop_reg();
	cimple_push_instr(func, cond_instr);
}

void cimplify_for(struct cimple_function *func, tree stmt)
{
	if (TREE_CODE(stmt) != FOR_STMT)
		errx(EXIT_FAILURE, "cimplify_for: not a for statement");

	tree init = ITER_INIT(stmt);
	tree cond = ITER_COND(stmt);
	tree incr = ITER_INCR(stmt);
	tree body = ITER_BODY(stmt);

	cimplify_stmt(func, init);

	int start = pc;
	int cond_reg = push_anon_reg();
	cimplify_expr(func, cond, cond_reg);
	struct cimple_instr cond_instr = {
		.op = OP_EQ_EQ,
		.uid = pc++,
		.scope_1 = CIMPLE_LOCAL,
		.arg1 = cond_reg,
		.scope_2 = CIMPLE_CONST,
		.arg2 = 0, // Constant 0
		.scope_ret = CIMPLE_UID,
		.ret = 0, // Not defined yet
	};
	pop_reg();
	int cond_idx = cimple_push_instr(func, cond_instr);
	cimplify_stmt(func, body);
	cimplify_stmt(func, incr);
	struct cimple_instr jmp = {
		.op = OP_GOTO,
		.uid = pc++,
		.scope_1 = CIMPLE_CONST,
		.arg1 = start,
	};
	cimple_push_instr(func, jmp);
	func->instrs[cond_idx].ret = pc;
}

void cimplify_if(struct cimple_function *func, tree stmt)
{
	if (TREE_CODE(stmt) != IF_STMT)
		errx(EXIT_FAILURE, "cimplify_if: not an if statement");

	tree cond = IF_COND(stmt);
	tree then = IF_YES(stmt);
	tree els = IF_NO(stmt);

	uint reg_cond = push_anon_reg();
	cimplify_expr(func, cond, reg_cond);
	struct cimple_instr cond_instr = {
		.op = OP_EQ_EQ,
		.uid = pc++,
		.scope_1 = CIMPLE_LOCAL,
		.arg1 = reg_cond,
		.scope_2 = CIMPLE_CONST,
		.arg2 = 0, // Constant 0
		.scope_ret = CIMPLE_UID,
		.ret = 0, // Not defined yet
	};
	pop_reg();

	int cond_idx = cimple_push_instr(func, cond_instr);
	cimplify_stmt(func, then);
	func->instrs[cond_idx].ret = pc;

	if (els != NULL) {
		struct cimple_instr jmp_instr = {
			.op = OP_GOTO,
			.uid = pc++,
			.scope_1 = CIMPLE_UID,
			.arg1 = 0, // Not defined yet
		};
		int jmp_idx = cimple_push_instr(func, jmp_instr);
		cimplify_stmt(func, els);
		func->instrs[jmp_idx].ret = pc;
	}
}

tree get_scalar_rec(tree list)
{
	if (TREE_CODE(list) == TREE_LIST)
		return get_scalar_rec(TREE_TYPE(list));
	return list;
}

void fill_init(union s *init, tree type, tree init_expr)
{
	if (TREE_CODE(type) == INT_TYPE) {
		tree val = get_scalar_rec(init_expr);
		if (TREE_CODE(val) != INTEGER_CST)
			errx(EXIT_FAILURE, "fill_init: not an integer");
		init->u = INT_VALUE(init_expr);
		return;
	}
	if (TREE_CODE(type) == REAL_TYPE) {
		tree val = get_scalar_rec(init_expr);
		if (TREE_CODE(val) != REAL_CST)
			errx(EXIT_FAILURE, "fill_init: not a real");
		init->f = REAL_VALUE(init_expr);
	}
	if (TREE_CODE(type) != ARRAY_TYPE) {
		errx(EXIT_FAILURE, "fill_init: unknown type");
	}

	// Handle multi-dimensional arrays
	tree subtype = TREE_TYPE(type);
	int size = get_sizeof(type) / get_sizeof(subtype);
	int i = 0;
	tree iter;
	for (iter = init_expr; iter != NULL; iter = TREE_CHAIN(iter)) {
		tree elem = TREE_TYPE(iter);
		if (TREE_CODE(elem) != TREE_LIST)
			break;
		if (i >= size)
			return;
		fill_init(init + i * size, subtype, elem);
		i++;
	}

	tree base = get_base_type(type);
	int len = get_sizeof(type) / get_sizeof(base);

	int j = i * size;
	for (; iter != NULL; iter = TREE_CHAIN(iter)) {
		tree elem = TREE_TYPE(iter);
		if (j >= len)
			return;
		fill_init(init + j, base, elem);
		j++;
	}

	for (; j < len; j++) {
		init[j].u = 0;
	}
}

void cimplify_object_decl(struct cimple_function *func, tree var)
{
	struct cimple_instr alloc = {
		.op = OP_ALLOC,
		.uid = pc++,

		.scope_ret = CIMPLE_LOCAL,
		.ret = get_named_reg(DECL_UID(var)),
		.scope_1 = CIMPLE_CONST,
		.arg1 = get_sizeof(TREE_TYPE(var)),
	};
	cimple_push_instr(func, alloc);

	tree type = TREE_TYPE(var);
	tree base = get_base_type(type);
	int is_float = is_real(base);
	int size = get_sizeof(type) / get_sizeof(base);

	union s *init = malloc(size * sizeof(union s));
	fill_init(init, type, DECL_BODY(var));

	uint reg_addr = push_anon_reg();
	struct cimple_instr temp = {
		.op = OP_ASSIGN,
		.uid = pc++,
		.scope_ret = CIMPLE_LOCAL,
		.ret = reg_addr,
		.scope_1 = CIMPLE_LOCAL,
		.arg1 = get_named_reg(DECL_UID(var)),

		.is_float = 0,
	};
	cimple_push_instr(func, temp);

	for (int i = 0; i < size; i++) {
		// Store value
		struct cimple_instr store = {
			.op = OP_ST,
			.uid = pc++,

			.scope_1 = CIMPLE_LOCAL,
			.arg1 = reg_addr,
			.scope_2 = CIMPLE_CONST,
			.arg2 = init[i].u,

			.is_float = is_float,
		};
		cimple_push_instr(func, store);
		// Increment address
		struct cimple_instr inc = {
			.op = OP_ADD,
			.uid = pc++,
			.scope_ret = CIMPLE_LOCAL,
			.ret = reg_addr,
			.scope_1 = CIMPLE_LOCAL,
			.arg1 = reg_addr,
			.scope_2 = CIMPLE_CONST,
			.arg2 = get_sizeof(base),
			.is_float = 0,
		};
		cimple_push_instr(func, inc);
	}

	pop_reg();
	free(init);
}

void cimplify_var_decl(struct cimple_function *func, tree var)
{
	if (TREE_CODE(var) != VARIABLE_DECL)
		errx(EXIT_FAILURE, "cimplify_var_decl: not a variable");

	int is_float = is_real(TREE_TYPE(var));
	struct cimple_instr init = {
		.op = OP_ASSIGN,
		.uid = pc++,
		.scope_ret = CIMPLE_LOCAL,
		.ret = push_named_reg(DECL_UID(var)),
		.scope_2 = CIMPLE_CONST,
		.arg2 = 0,
		.is_float = is_float,
	};
	cimple_push_instr(func, init);
}

void cimplify_block(struct cimple_function *func, tree block)
{
	if (TREE_CODE(block) != BLOCK_NODE)
		errx(EXIT_FAILURE, "cimplify_block: not a block");

	// Initialize all variables to 0
	for (tree var = BLOCK_VARS(block); var != NULL; var = TREE_CHAIN(var)) {
		if (TREE_CODE(var) != VARIABLE_DECL)
			continue;
		cimplify_var_decl(func, var);
	}
	// Allocate space for objects and initialize them
	for (tree var = BLOCK_VARS(block); var != NULL; var = TREE_CHAIN(var)) {
		tree type = TREE_TYPE(var);
		if (TREE_CODE(type) != ARRAY_TYPE)
			continue;
		cimplify_object_decl(func, var);
	}
	// Generate code for all statements
	for (tree stmt = BLOCK_BODY(block); stmt != NULL; stmt = TREE_CHAIN(stmt)) {
		cimplify_stmt(func, stmt);
	}

	// Free all objects and registers
	for (tree var = BLOCK_VARS(block); var != NULL; var = TREE_CHAIN(var)) {
		tree type = TREE_TYPE(var);
		pop_reg();

		if (TREE_CODE(type) != ARRAY_TYPE)
			continue;
		struct cimple_instr free = {
			.op = OP_FREE,
			.uid = pc++,
			.scope_1 = CIMPLE_CONST,
			.arg1 = get_sizeof(type),
		};
		cimple_push_instr(func, free);
	}
}

void cimplify_function(struct cimple_program *prog, tree func)
{
	if (TREE_CODE(func) != FUNCTION_DECL)
		errx(EXIT_FAILURE, "cimplify_function: not a function");
	if (DECL_BODY(func) == NULL)
		errx(EXIT_FAILURE, "cimplify_function: function has no definition");

	pc = 0;
	stack.off = 0;

	struct cimple_function *cfunc = cimple_new_function(prog);
	tree block = DECL_BODY(func);

	cimplify_block(cfunc, block);

	struct cimple_instr ret = {
		.op = OP_RETURN,
		.uid = pc++,

		.scope_1 = CIMPLE_CONST,
		.arg1 = 0,
	};

	cimple_push_instr(cfunc, ret);
}

struct cimple_program *cimplify(tree root)
{
	struct cimple_program *prog = cimple_new_program();

	for (tree var = BLOCK_VARS(root); var != NULL; var = TREE_CHAIN(var)) {
		if (TREE_CODE(var) != VARIABLE_DECL)
			continue;
		if (TREE_CODE(var) == FUNCTION_DECL)
			cimplify_function(prog, var);
	}

	return prog;
}
