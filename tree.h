#pragma once

#include <stdint.h>

typedef union tree_node tree;

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
	FLOAT_CST,
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
	FLOAT_TYPE,
	ENUM_TYPE,
	CHAR_TYPE,
	PTR_TYPE,
	ARRAY_TYPE,
	
	/* Statements */
	IF_STMT,
	FOR_STMT,
	WHILE_STMT,
	DOWHILE_STMT,
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
	COMPONENT_REF,

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
	NOT_EXPR,
	NEG_EXPR,

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

struct tree_common {
	enum tree_code code;

	tree *chain;
	tree *type;

	int has_side_effects : 1;
	int is_constant : 1;
	int is_zero : 1;
	int is_const : 1;
	int is_volatile : 1;
	int is_extern : 1;
	int is_static : 1;
	int is_signed : 1;
};

struct tree_identifier {
	struct tree_common common;

	char *name;
	int length;
};

struct tree_integer {
	struct tree_common common;

	int size;
	uint64_t value;
};

struct tree_real {
	struct tree_common common;

	int size;
	double value;
};

struct tree_string {
	struct tree_common common;

	int length;
	char *value;
};

struct tree_decl {
	struct tree_common common;

	unsigned int uid;
	tree *name;
};

struct tree_type {
	struct tree_common common;

	unsigned int uid;
	tree *name;
};

struct tree_expr {
	struct tree_common common;

	tree *operand[4];
};

struct tree_block {
	struct tree_common common;

	tree *decls;
	tree *types;

	tree *subblocks;
	tree *superblock;

	tree *body;
};

struct tree_list {
	struct tree_common common;

	tree *node;
};

struct tree_if {
	struct tree_common common;
	tree *cond;
	tree *true;
	tree *false;
};

struct tree_for {
	struct tree_common common;
	tree *init;
	tree *cond;
	tree *step;
	tree *body;
};

struct tree_while {
	struct tree_common common;
	tree *cond;
	tree *body;
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
	struct tree_for for_stmt;
	struct tree_while while_stmt;
};

tree *node_void_type;

tree *node_char_type;
tree *node_short_type;
tree *node_int_type;
tree *node_long_type;
tree *node_long_long_type;

tree *node_float_type;
tree *node_double_type;
tree *node_long_double_type;

tree *new_node(enum tree_code code, tree *type);

void start_unit(void);

tree *end_unit(void);

void chain_append(tree *chain, tree *node);

void chain_prepend(tree *chain, tree *node);

void type_append(tree *node, tree *type);

tree *get_identifier(char *name, int len);

tree *get_integer_constant(char *value, int len);

tree *get_char_constant(char *value, int len);

tree *get_real_constant(char *value, int len);

tree *get_string(char *value, int len);

void start_block(void);

tree *end_block(void);

tree *get_decl(tree *name);

tree *new_decl(enum tree_code code, tree *name, tree *type);

tree *new_function_decl(tree *name, tree *type, tree *args, tree *body);

tree *new_variable_decl(tree *name, tree *type, tree *value);

void start_enum(tree *name);

tree *end_enum(void);

tree *build_expr(enum tree_code code, tree *operand0, tree *operand1, tree *operand2, tree *operand3);
