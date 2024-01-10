#pragma once

#include <stdint.h>
#include <sys/types.h>

#define MAX_IDENTIFIER_LEN 256

typedef union tree_node *tree;

enum tree_code {

	NONE,
	/* tree_identifier */
	IDENTIFIER_NODE,

	/* tree_block */
	BLOCK_NODE,

	TREE_LIST,

	/* Constants */
	/* tree_integer */
	INTEGER_CST,
	/* tree_real */
	REAL_CST,
	/* tree_string */
	STRING_CST,

	CONST_QUAL,
	VOLATILE_QUAL,

	/* Declarations (tree_decl)*/
	VARIABLE_DECL,
	FUNCTION_DECL,
	ENUM_DECL,
	TYPE_DECL,
	PARM_DECL,
	LABEL_DECL,

	/* Types (tree_type)*/
	VOID_TYPE,
	INT_TYPE,
	REAL_TYPE,
	ENUM_TYPE,
	STRUCT_TYPE,
	CHAR_TYPE,
	PTR_TYPE,
	ARRAY_TYPE,
	FUNCTION_TYPE,

	/* Statements */
	IF_STMT,
	FOR_STMT,
	WHILE_STMT,
	DO_WHILE_STMT,
	EMPTY_STMT,

	/* Operand 0: label */
	LABEL_STMT,
	/* Operand 0: label */
	GOTO_STMT,

	BREAK_STMT,
	CONTINUE_STMT,

	/* Operand 0: value to return */
	RETURN_STMT,

	/* References */
	/* Operand 0: variable to reference */
	INDIRECT_REF,
	/* Operand 0: variable to reference
	 * Operand 1: component to reference */
	MEMBER_REF,

	/* Expressions */

	COMPOUND_EXPR,
	/* Operand 0: value to assign
	 * Operand 1: value to assign to */
	ASSIGN_EXPR,

	/* Operand 0: variable to reference */
	ADDR_EXPR,

	/* Operand 0: function to call
	 * Operand 1: chain of arguments */
	CALL_EXPR,

	/* Operand 0: assignment target
	 * Operand 1: value to increment/decrement by */
	POST_INCR_EXPR,
	POST_DECR_EXPR,
	PRE_INCR_EXPR,
	PRE_DECR_EXPR,

	/* Operand 0: expression */
	PLUS_EXPR,
	MINUS_EXPR,

	/* Operand 0: left operand
	 * Operand 1: right operand */
	MUL_EXPR,
	ADD_EXPR,
	SUB_EXPR,
	DIV_EXPR,
	MOD_EXPR,

	LSHIFT_EXPR,
	RSHIFT_EXPR,
	BIN_AND_EXPR,
	BIN_OR_EXPR,
	BIN_XOR_EXPR,
	BIN_NOT_EXPR,

	LOG_AND_EXPR,
	LOG_OR_EXPR,
	LOG_NOT_EXPR,
	TRUTH_EXPR,

	GE_EXPR,
	LE_EXPR,
	GT_EXPR,
	LT_EXPR,
	EQ_EXPR,
	NE_EXPR,

	/* Operand 0: condition
	 * Operand 1: true value
	 * Operand 2: false value */
	COND_EXPR,

	/* Operand 0: expression to cast
	 * Operand 1: type to cast to */
	CONV_EXPR,
};

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

struct tree_expr {
	struct tree_common common;

	tree operands[4];

	// for incr and decr
	uint64_t value;
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

tree type_append(tree node, tree type);

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

