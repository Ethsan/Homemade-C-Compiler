#pragma once
#include "location.h"

typedef union tree tree;

enum tree_type {
	CONSTANT,
	FUNCTION,
	IDENTIFIER,
	OPERATOR,
	IFELSE,
	LOOP,
	SWITCH,
	STRUCT,
	TYPEDEF,
	TYPE,
	ENUM,
	DECLARATION,
	INITIALIZER,
	STATEMENT,
	EXPRESSION,
	PROGRAM,
};

struct tree_common {
	enum tree_type type;

	tree *parent;
	tree *left;
	tree *right;
	tree *next;
	tree *prev;
	
	struct location loc;
};

union tree {
	struct tree_common common;
};

tree *tree_new(enum tree_type type, struct location loc);

tree *tree_new_constant(struct location loc, int value);

tree *tree_new_function(struct location loc, tree *name, tree *body);

tree *tree_new_identifier(struct location loc, const char *name);

tree *tree_new_operator(struct location loc, int op, tree *left, tree *right);

tree *tree_new_ifelse(struct location loc, tree *cond, tree *if_true, tree *if_false);

tree *tree_new_loop(struct location loc, tree *cond, tree *body);

tree *tree_new_switch(struct location loc, tree *cond, tree *body);

tree *tree_new_struct(struct location loc, tree *name, tree *body);

tree *tree_new_typedef(struct location loc, tree *name, tree *type);

tree *tree_new_type(struct location loc, tree *name, tree *type);

tree *tree_new_enum(struct location loc, tree *name, tree *body);

tree *tree_new_declaration(struct location loc, tree *name, tree *type, tree *init);

tree *tree_new_initializer(struct location loc, tree *name, tree *init);

tree *tree_new_statement(struct location loc, tree *expr);

tree *tree_new_expression(struct location loc, tree *expr);

tree *tree_new_program(struct location loc, tree *expr);
