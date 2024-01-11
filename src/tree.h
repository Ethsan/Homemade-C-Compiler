#pragma once

#include <stdint.h>
#include <sys/types.h>

#define MAX_IDENTIFIER_LEN 256

typedef union tree_node *tree;

#define TREE_CODE_ENUM                         \
	X(NONE)                                \
	/* tree_identifier */                  \
	X(IDENTIFIER_NODE)                     \
                                               \
	/* tree_block */                       \
	X(BLOCK_NODE)                          \
                                               \
	X(TREE_LIST)                           \
                                               \
	/* Constants */                        \
	/* tree_integer */                     \
	X(INTEGER_CST)                         \
	/* tree_real */                        \
	X(REAL_CST)                            \
	/* tree_string */                      \
	X(STRING_CST)                          \
                                               \
	X(CONST_QUAL)                          \
	X(VOLATILE_QUAL)                       \
                                               \
	/* Declarations (tree_decl)*/          \
	X(VARIABLE_DECL)                       \
	X(FUNCTION_DECL)                       \
	X(ENUM_DECL)                           \
	X(TYPE_DECL)                           \
	X(PARM_DECL)                           \
	X(LABEL_DECL)                          \
	X(ABSTRACT_DECL)                       \
                                               \
	/* Types (tree_type)*/                 \
	X(VOID_TYPE)                           \
	X(INT_TYPE)                            \
	X(REAL_TYPE)                           \
	X(ENUM_TYPE)                           \
	X(STRUCT_TYPE)                         \
	X(CHAR_TYPE)                           \
	X(PTR_TYPE)                            \
	X(ARRAY_TYPE)                          \
	X(FUNCTION_TYPE)                       \
                                               \
	/* Statements */                       \
	X(IF_STMT)                             \
	X(FOR_STMT)                            \
	X(WHILE_STMT)                          \
	X(DO_WHILE_STMT)                       \
	X(EMPTY_STMT)                          \
                                               \
	/* Operand 0: label */                 \
	X(LABEL_STMT)                          \
	/* Operand 0: label */                 \
	X(GOTO_STMT)                           \
                                               \
	X(BREAK_STMT)                          \
	X(CONTINUE_STMT)                       \
                                               \
	/* Operand 0: value to return */       \
	X(RETURN_STMT)                         \
                                               \
	/* References */                       \
	/* Operand 0: variable to reference */ \
	X(INDIRECT_REF)                        \
	/* Operand 0: variable to reference \
 * Operand 1: component to reference */  \
	X(MEMBER_REF)                          \
                                               \
	/* Expressions */                      \
                                               \
	X(COMPOUND_EXPR)                       \
	/* Operand 0: value to assign \
 * Operand 1: value to assign to */        \
	X(ASSIGN_EXPR)                         \
                                               \
	/* Operand 0: variable to reference */ \
	X(ADDR_EXPR)                           \
                                               \
	/* Operand 0: function to call \
 * Operand 1: chain of arguments */       \
	X(CALL_EXPR)                           \
                                               \
	/* Operand 0: assignment target \
 * Operand 1: value to increment/decrement by */      \
	X(POST_INCR_EXPR)                      \
	X(POST_DECR_EXPR)                      \
	X(PRE_INCR_EXPR)                       \
	X(PRE_DECR_EXPR)                       \
                                               \
	/* Operand 0: expression */            \
	X(PLUS_EXPR)                           \
	X(MINUS_EXPR)                          \
                                               \
	/* Operand 0: left operand \
 * Operand 1: right operand */           \
	X(MUL_EXPR)                            \
	X(ADD_EXPR)                            \
	X(SUB_EXPR)                            \
	X(DIV_EXPR)                            \
	X(MOD_EXPR)                            \
                                               \
	X(LSHIFT_EXPR)                         \
	X(RSHIFT_EXPR)                         \
	X(BIN_AND_EXPR)                        \
	X(BIN_OR_EXPR)                         \
	X(BIN_XOR_EXPR)                        \
	X(BIN_NOT_EXPR)                        \
                                               \
	X(LOG_AND_EXPR)                        \
	X(LOG_OR_EXPR)                         \
	X(LOG_NOT_EXPR)                        \
	X(TRUTH_EXPR)                          \
                                               \
	X(GE_EXPR)                             \
	X(LE_EXPR)                             \
	X(GT_EXPR)                             \
	X(LT_EXPR)                             \
	X(EQ_EXPR)                             \
	X(NE_EXPR)                             \
                                               \
	/* Operand 0: condition \
 * Operand 1: true value \
 * Operand 2: false value */              \
	X(COND_EXPR)                           \
                                               \
	/* Operand 0: expression to cast \
 * Operand 1: type to cast to */     \
	X(CONV_EXPR)

#define X(a) a,
enum tree_code { TREE_CODE_ENUM };
#undef X

const char *tree_code_name(enum tree_code code);

#define TREE_CODE(node) ((node)->common.code)
#define TREE_TYPE(node) ((node)->common.type)
#define TREE_CHAIN(node) ((node)->common.chain)
#define TREE_CONSTANT(node) ((node)->common.is_constant)

#define TREE_SET_CONSTANT(node) ((node)->common.is_constant = 1)
#define TREE_IS_CONSTANT(node) ((node)->common.is_constant)

struct tree_common {
	enum tree_code code;

	tree chain;
	tree type;
	tree _alloc_chain;

	uint has_side_effects : 1;
	uint is_constant : 1;
	uint is_zero : 1;
	uint is_const : 1;
	uint is_volatile : 1;
	uint is_extern : 1;
	uint is_static : 1;
	uint is_signed : 1;
};

#define ID_NAME(node) ((node)->identifier.name)
#define ID_LEN(node) ((node)->identifier.len)

struct tree_identifier {
	struct tree_common common;

	char *name;
	int len;
};

#define INT_SIZE(node) ((node)->integer.size)
#define INT_VALUE(node) ((node)->integer.value)

struct tree_integer {
	struct tree_common common;

	int size;
	uint64_t value;
};

#define REAL_SIZE(node) ((node)->real.size)
#define REAL_VALUE(node) ((node)->real.value)

struct tree_real {
	struct tree_common common;

	int size;
	double value;
};

#define STRING_LEN(node) ((node)->string.len)
#define STRING_VALUE(node) ((node)->string.value)

struct tree_string {
	struct tree_common common;

	int len;
	char *value;
};

#define DECL_NAME(node) ((node)->decl.name)
#define DECL_UID(node) ((node)->decl.uid)

#define DECL_PARM_LIST(node) ((node)->decl.parm_list)
#define DECL_BODY(node) ((node)->decl.body)

struct tree_decl {
	struct tree_common common;

	unsigned int uid;
	tree name;

	// for functions
	tree parm_list;
	tree body;
};

#define TYPE_SIZE(node) ((node)->type.size)
#define TYPE_PARM_LIST(node) ((node)->type.parm_list)

struct tree_type {
	struct tree_common common;

	union {
		// for arrays
		int size;
		// for functions
		tree parm_list;
	};
};

#define EXPR_OPERAND(node, idx) ((node)->expr.operands[idx])
#define EXPR_VALUE(node) ((node)->expr.value)
#define EXPR_STEP(node) ((node)->expr.step)

struct tree_expr {
	struct tree_common common;

	tree operands[4];

	// if constant
	tree value;
	// for incr and decr
	uint64_t step;
};

#define BLOCK_VARS(node) ((node)->block.vars)
#define BLOCK_TYPES(node) ((node)->block.types)

#define BLOCK_SUBBLOCKS(node) ((node)->block.subblocks)
#define BLOCK_SUPERBLOCK(node) ((node)->block.superblock)

#define BLOCK_BODY(node) ((node)->block.body)

struct tree_block {
	struct tree_common common;

	tree vars;
	tree types;

	tree subblocks;
	tree superblock;

	tree body;
};

#define LIST_VALUE(node) ((node)->list.value)

struct tree_list {
	struct tree_common common;

	tree value;
};

#define IF_COND(node) ((node)->if_stmt.cond)
#define IF_YES(node) ((node)->if_stmt.yes)
#define IF_NO(node) ((node)->if_stmt.no)

struct tree_if {
	struct tree_common common;
	tree cond;
	tree yes;
	tree no;
};

#define ITER_INIT(node) ((node)->iter.init)
#define ITER_COND(node) ((node)->iter.cond)
#define ITER_INCR(node) ((node)->iter.incr)
#define ITER_BODY(node) ((node)->iter.body)

struct tree_iter {
	struct tree_common common;
	tree init;
	tree cond;
	tree incr;
	tree body;
};

union tree_node {
	struct tree_common common;
	struct tree_identifier identifier;
	struct tree_integer integer;
	struct tree_real real;
	struct tree_string string;
	struct tree_decl decl;
	struct tree_type type;
	struct tree_expr expr;
	struct tree_block block;
	struct tree_list list;
	struct tree_if if_stmt;
	struct tree_iter iter;
};

tree new_node(enum tree_code code, tree type);

tree chain_append(tree chain, tree node);

tree get_identifier(const char *name, int len);

tree parse_integer(const char *value, int len);

tree parse_real(const char *value, int len);

tree parse_string(const char *value, int len);

tree parse_char(const char *value, int len);

void start_block(void);

tree end_block(tree body);

void start_function(tree decl);

tree end_function(tree body);

tree get_decl(tree id);

tree emit_decl(tree decl);

int is_constant(tree node);

tree build_unary_expr(enum tree_code code, tree node);

tree build_expr(enum tree_code code, tree lhs, tree rhs);

tree build_cast(tree expr, tree type);

tree build_sizeof(tree type);

tree build_cond_expr(tree cond, tree yes, tree no);

tree build_if(tree cond, tree yes, tree no);

void start_for(tree init, tree cond, tree incr);

tree end_for(tree body);

void start_while(tree cond);

tree end_while(tree body);

void start_do_while();

tree end_do_while(tree body, tree cond);

tree build_break(void);

tree build_continue(void);

tree build_return(tree value);

tree build_label(tree label, tree stmt);

tree build_case(tree expr, tree stmt);

tree build_default(tree stmt);

tree build_goto(tree label);

tree build_call(tree func, tree args);

tree build_decl(tree abstract_decl, tree type);

tree build_abstract_decl(tree name);

tree build_init_decl(tree abstract_decl, tree init);

tree build_array_decl(tree abstract_decl, tree size);

tree build_pointer_type(tree type);

tree build_pointer_decl(tree abstract_decl, tree type);

tree build_function_decl(tree abstract_decl, tree parm_list);

tree build_parm_decl(tree abstract_decl, tree type);

void print_current_context(void);
