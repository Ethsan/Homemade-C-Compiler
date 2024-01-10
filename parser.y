%{
#include "tree.h"

#include <stdio.h>

void yyerror(const char * msg);

extern int yylex(void);

#define ERROR(msg) do { \
	yyerror(msg); \
	YYERROR; \
} while (0)
%}

%locations

%define parse.error verbose

%union {
	tree tree;
	enum tree_code code;
	int misc;
}

%token <tree> IDENTIFIER
%token <tree> INTEGER_CONSTANT
%token <tree> FLOATING_CONSTANT
%token <tree> ENUMERATION_CONSTANT
%token <tree> CHARACTER_CONSTANT
%token <tree> STRING_LITERAL
%token <tree> TYPE_NAME

%token AUTO DOUBLE INT STRUCT BREAK ELSE 
%token LONG SWITCH CASE ENUM REGISTER TYPEDEF CHAR
%token EXTERN RETURN UNION CONST FLOAT SHORT UNSIGNED
%token CONTINUE FOR SIGNED VOID DEFAULT GOTO SIZEOF
%token VOLATILE DO IF STATIC WHILE
%token LBRACKET RBRACKET LPAREN RPAREN LBRACE RBRACE 
%token COMMA DOT ARROW INCREMENT DECREMENT AND STAR
%token PLUS MINUS TILDE EXCLAMATION SLASH PERCENT
%token LSHIFT RSHIFT LESS_THAN GREATER_THAN
%token LESS_THAN_EQUAL GREATER_THAN_EQUAL EQUAL 
%token NOT_EQUAL EQUAL_EQUAL STAR_EQUAL SLASH_EQUAL
%token PERCENT_EQUAL PLUS_EQUAL MINUS_EQUAL LSHIFT_EQUAL
%token RSHIFT_EQUAL AND_EQUAL XOR_EQUAL OR_EQUAL
%token PLUS_PLUS MINUS_MINUS COLON QUESTION OR_OR AND_AND
%token OR XOR ELLIPSIS SEMICOLON

%type <tree> primary_expression
%type <tree> postfix_expression
%type <tree> unary_expression
%type <tree> cast_expression
%type <tree> multiplicative_expression
%type <tree> additive_expression
%type <tree> shift_expression
%type <tree> relational_expression
%type <tree> equality_expression
%type <tree> AND_expression
%type <tree> exclusive_OR_expresion
%type <tree> inclusive_OR_expression
%type <tree> logical_AND_expression
%type <tree> logical_OR_expression
%type <tree> conditional_expression
%type <tree> assignement_expression
%type <tree> expression
%type <tree> constant_expression
%type <tree> declaration
%type <tree> declaration_specifiers
%type <tree> init_declarator_list
%type <tree> init_declarator
%type <misc> storage_class_specifier
%type <tree> type_specifier
%type <tree> struct_or_union_specifier
%type <tree> struct_or_union
%type <tree> struct_declaration_list
%type <tree> struct_declaration
%type <tree> struct_declarator_list
%type <tree> struct_declarator
%type <tree> enum_specifier
%type <tree> enumerator_list
%type <tree> enumerator
%type <tree> type_qualifier
%type <tree> declarator
%type <tree> direct_declarator
%type <tree> pointer
%type <tree> type_qualifier_list
%type <tree> parameter_type_list
%type <tree> parameter_list
%type <tree> parameter_declaration
%type <tree> type_name
%type <tree> abstract_declarator
%type <tree> direct_abstract_declarator
%type <tree> constant
%type <tree> specifier_qualifier_list
%type <tree> identifier_list
%type <tree> initializer
%type <tree> initializer_list
%type <tree> statement
%type <tree> labeled_statement
%type <tree> compound_statement
%type <tree> declaration_list
%type <tree> statement_list
%type <tree> expression_statement
%type <tree> selection_statement
%type <tree> iteration_statement
%type <tree> jump_statement
%type <tree> external_declaration
%type <tree> function_definition
%type <tree> argument_expression_list

%type <code> assignement_operator
%type <code> unary_operator

%right THEN ELSE

%start translation_unit

%%
/* 1. Expressions */

/*	 1.1. Primary expressions */

primary_expression
	: IDENTIFIER {
		$$ = get_decl($1);
	}
	| constant
	| STRING_LITERAL
	| LPAREN expression RPAREN {
		$$ = $2;
	}
	;

/*	1.2. Postfix expressions */

postfix_expression
	: primary_expression
	| postfix_expression LBRACKET expression RBRACKET {
		$$ = build_unary_expr(INDIRECT_REF, build_expr(ADD_EXPR, $1, $3));
	}
	| postfix_expression LPAREN RPAREN {
		$$ = build_expr(CALL_EXPR, $1, NULL);
	}
	| postfix_expression LPAREN argument_expression_list RPAREN {
		$$ = build_expr(CALL_EXPR, $1, $3);
	}
	| postfix_expression DOT IDENTIFIER {
		$$ = build_expr(MEMBER_REF, $1, $3);
	}
	| postfix_expression ARROW IDENTIFIER {
		$$ = build_expr(MEMBER_REF, build_unary_expr(INDIRECT_REF, $1), $3);
	}
	| postfix_expression INCREMENT {
		$$ = build_unary_expr(POST_INCR_EXPR, $1);
	}
	| postfix_expression DECREMENT {
		$$ = build_unary_expr(POST_DECR_EXPR, $1);
	}
	;

/*	1.3. Unary expressions */

unary_expression
	: postfix_expression
	| PLUS_PLUS unary_expression {
		$$ = build_unary_expr(PRE_INCR_EXPR, $2);
	}
	| MINUS_MINUS unary_expression {
		$$ = build_unary_expr(PRE_DECR_EXPR, $2);
	}
	| unary_operator cast_expression {
		$$ = build_unary_expr($1, $2);
	}
	| SIZEOF unary_expression {
		$$ = build_sizeof(TREE_TYPE($2));
	}
	| SIZEOF LPAREN type_name RPAREN {
		$$ = build_sizeof($3);
	}
	;

unary_operator
	: AND { $$ = ADDR_EXPR; }
	| STAR { $$ = INDIRECT_REF; }
	| PLUS { $$ = PLUS_EXPR; }
	| MINUS { $$ = MINUS_EXPR; }
	| TILDE { $$ = BIN_NOT_EXPR; }
	| EXCLAMATION { $$ = LOG_NOT_EXPR; }
	;

/*	1.4. Cast operators */

cast_expression
	: unary_expression
	| LPAREN type_name RPAREN cast_expression {
		$$ = build_cast($2, $4);
	}
	;
	
/*	1.5. Multiplicative operators */

multiplicative_expression
	: cast_expression
	| multiplicative_expression STAR cast_expression {
		$$ = build_expr(MUL_EXPR, $1, $3);
	}
	| multiplicative_expression SLASH cast_expression {
		$$ = build_expr(DIV_EXPR, $1, $3);
	}
	| multiplicative_expression PERCENT cast_expression {
		$$ = build_expr(MOD_EXPR, $1, $3);
	}
	;

/*	1.6. Additive operators */

additive_expression
	: multiplicative_expression
	| additive_expression PLUS multiplicative_expression {
		$$ = build_expr(ADD_EXPR, $1, $3);
	}
	| additive_expression MINUS multiplicative_expression {
		$$ = build_expr(SUB_EXPR, $1, $3);
	}
	;

/*	1.7. Bitwise shift operators */

shift_expression
	: additive_expression
	| shift_expression LSHIFT additive_expression {
		$$ = build_expr(LSHIFT_EXPR, $1, $3);
	}
	| shift_expression RSHIFT additive_expression {
		$$ = build_expr(RSHIFT_EXPR, $1, $3);
	}
	;

/*	1.8. Relational operators */

relational_expression
	: shift_expression
	| relational_expression LESS_THAN shift_expression {
		$$ = build_expr(LT_EXPR, $1, $3);
	}
	| relational_expression GREATER_THAN shift_expression {
		$$ = build_expr(GT_EXPR, $1, $3);
	}
	| relational_expression LESS_THAN_EQUAL shift_expression {
		$$ = build_expr(LE_EXPR, $1, $3);
	}
	| relational_expression GREATER_THAN_EQUAL shift_expression {
		$$ = build_expr(GE_EXPR, $1, $3);
	}
	;

/*	1.9. Equality operators */

equality_expression
	: relational_expression
	| equality_expression EQUAL_EQUAL relational_expression {
		$$ = build_expr(EQ_EXPR, $1, $3);
	}
	| equality_expression NOT_EQUAL relational_expression {
		$$ = build_expr(NE_EXPR, $1, $3);
	}
	;

/*	1.10. Bitwise AND operator */

AND_expression
	: equality_expression
	| AND_expression AND equality_expression {
		$$ = build_expr(BIN_AND_EXPR, $1, $3);
	}
	;

/*	1.11. Bitwise exclusive OR operator */

exclusive_OR_expresion
	: AND_expression 
	| exclusive_OR_expresion XOR AND_expression {
		$$ = build_expr(BIN_XOR_EXPR, $1, $3);
	}
	;

/*	1.12. Bitwise inclusive OR operator */

inclusive_OR_expression
	: exclusive_OR_expresion
	| inclusive_OR_expression OR exclusive_OR_expresion {
		$$ = build_expr(BIN_OR_EXPR, $1, $3);
	}
	;

/*	1.13. Logical AND operator */

logical_AND_expression
	: inclusive_OR_expression
	| logical_AND_expression AND_AND inclusive_OR_expression {
		$$ = build_expr(LOG_AND_EXPR, $1, $3);
	}
	;

/*	1.14. Logical OR operator */

logical_OR_expression
	: logical_AND_expression
	| logical_OR_expression OR_OR logical_AND_expression {
		$$ = build_expr(LOG_OR_EXPR, $1, $3);
	}
	;

/*	1.15. Conditional operator */

conditional_expression
	: logical_OR_expression 
	| logical_OR_expression QUESTION expression COLON conditional_expression {
		$$ = build_cond_expr($1, $3, $5);
	}
	;

/*	1.16. Assignment operators */

assignement_expression
	: conditional_expression
	| unary_expression assignement_operator assignement_expression {
		if ($2 != NONE) {
			$3 = build_expr($2, $1, $3);
		}
		$$ = build_expr(ASSIGN_EXPR, $1, $3);
	}
	;

assignement_operator
	: EQUAL { $$ = NONE; }
	| STAR_EQUAL { $$ = MUL_EXPR; }
	| SLASH_EQUAL  { $$ = DIV_EXPR; }
	| PERCENT_EQUAL  { $$ = MOD_EXPR; }
	| PLUS_EQUAL  { $$ = ADD_EXPR; }
	| MINUS_EQUAL  { $$ = SUB_EXPR; }
	| LSHIFT_EQUAL { $$ = LSHIFT_EXPR; }
	| RSHIFT_EQUAL { $$ = RSHIFT_EXPR; }
	| AND_EQUAL { $$ = BIN_AND_EXPR; }
	| XOR_EQUAL { $$ = BIN_XOR_EXPR; }
	| OR_EQUAL { $$ = BIN_OR_EXPR; }
	;

/*	1.17. Comma operator */

expression
	: assignement_expression
	| expression COMMA assignement_expression {
		$$ = build_expr(COMPOUND_EXPR, $1, $3);
	}
	;

/* 2. Constant Expressions */

constant_expression
	: conditional_expression {
		if (!is_constant($1)) {
			ERROR("constant_expression must be constant");
		}
		$$ = $1;
	}
	;

/* 3. Declarations */

declaration
	: declaration_specifiers SEMICOLON {
		/* Nothing to do */
	}
	| declaration_specifiers init_declarator_list SEMICOLON {
		for (tree t = $2; t != NULL; ) {
			type_append(TREE_TYPE(t), $1);
			emit_decl(TREE_TYPE(t));

			tree next = TREE_CHAIN(t);
			free(t);
			t = next;
		}
	}
	;

declaration_specifiers
	: storage_class_specifier {
		ERROR("storage_class_specifier not implemented");
	}
	| storage_class_specifier declaration_specifiers {
		ERROR("storage_class_specifier not implemented");
	}
	| type_specifier { $$ = $1; }
	| type_specifier declaration_specifiers {
		ERROR("multiple type specifiers");
	}
	| type_qualifier {
		ERROR("type_qualifier not implemented");
	}
	| type_qualifier declaration_specifiers {
		ERROR("multiple type qualifiers");
	}
	;
	
init_declarator_list
	: init_declarator {
		$$ = new_node(TREE_LIST, $1);
	}
	| init_declarator_list COMMA init_declarator {
		$$ = new_node(TREE_LIST, $3);
		$$ = chain_append($$, $1);
	}
	;

init_declarator
	: declarator {
		$$ = $1;
	}
	| declarator EQUAL initializer {
		$$ = $1;
		DECL_BODY($$) = $3;
	}
	;

/*	3.1. Storage_class specifiers */

storage_class_specifier
	: TYPEDEF { $$ = TYPEDEF; }
	| EXTERN { $$ = EXTERN; }
	| STATIC { $$ = STATIC; }
	| AUTO { $$ = AUTO; }
	| REGISTER { $$ = REGISTER; }
	;

/*	3.2. Type specifiers */

type_specifier
	: VOID { $$ = new_node(VOID_TYPE, NULL); }
	| CHAR { $$ = new_node(CHAR_TYPE, NULL); }
	| SHORT { ERROR("SHORT not implemented"); }
	| INT { $$ = new_node(INT_TYPE, NULL); }
	| LONG { ERROR("LONG not implemented"); }
	| FLOAT { $$ = new_node(REAL_TYPE, NULL); }
	| DOUBLE { $$ = new_node(REAL_TYPE, NULL); }
	| SIGNED { ERROR("SIGNED not implemented"); }
	| UNSIGNED { ERROR("UNSIGNED not implemented"); }
	| struct_or_union_specifier { $$ = $1; }
	| enum_specifier { $$ = $1; }
	| TYPE_NAME { $$ = $1; }
	;

/*		3.2.1. Struct or union specifiers */

struct_or_union_specifier
	: struct_or_union LBRACE struct_declaration_list RBRACE { $$ = NULL; }
	| struct_or_union IDENTIFIER { $$ = NULL; }
	| struct_or_union IDENTIFIER LBRACE struct_declaration_list RBRACE { $$ = NULL; }
	;

struct_or_union
	: STRUCT { $$ = NULL; }
	| UNION { $$ = NULL; }
	;

struct_declaration_list	
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMICOLON { $$ = NULL; }
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list COMMA struct_declarator
	;

struct_declarator
	: declarator
	| COLON constant_expression { $$ = NULL; }
	| declarator COLON constant_expression
	;

/*		3.2.2. Enumeration specifiers */

enum_specifier
	: ENUM LBRACE enumerator_list RBRACE { $$ = NULL; }
	| ENUM IDENTIFIER LBRACE enumerator_list RBRACE { $$ = NULL; }
	| ENUM IDENTIFIER { $$ = NULL; }
	;

enumerator_list
	: enumerator
	| enumerator_list COMMA enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER EQUAL constant_expression
	;

/*	3.3. Type qualifiers */

type_qualifier
	: CONST { $$ = NULL; }
	| VOLATILE { $$ = NULL; }
	;

/*	3.4. Declarators */

declarator
	: pointer direct_declarator {
		type_append($1, TREE_TYPE($2));
		TREE_TYPE($2) = $1;
		$$ = $2;
	}
	| direct_declarator {
		$$ = $1;
	}
	;

direct_declarator
	: IDENTIFIER {
		$$ = new_node(VARIABLE_DECL, NULL);
		DECL_NAME($$) = $1;
	}
	| LPAREN declarator RPAREN {
		$$ = $2;
	}
	| direct_declarator LBRACKET RBRACKET {
		TREE_TYPE($1) = new_node(ARRAY_TYPE, TREE_TYPE($1));
		$$ = $1;
	}
	| direct_declarator LBRACKET constant_expression RBRACKET {
		TREE_TYPE($1) = new_node(ARRAY_TYPE, TREE_TYPE($1)); /* TODO constant_expression */
		$$ = $1;
	}
	| direct_declarator LPAREN parameter_type_list RPAREN {
		// check if variable is a function
		if (TREE_CODE($1) == VARIABLE_DECL && TREE_TYPE($1) == NULL) {
			TREE_CODE($1) = FUNCTION_DECL;
			DECL_PARM_LIST($1) = $3;
		} else {
			tree func_type = new_node(FUNCTION_TYPE, TREE_TYPE($1));
			TYPE_PARM_LIST(func_type) = $3;
			TREE_TYPE($1) = func_type;
		}
		$$ = $1;
	}
	| direct_declarator LPAREN RPAREN {
		// check if variable is a function
		if (TREE_CODE($1) == VARIABLE_DECL && TREE_TYPE($1) == NULL) {
			TREE_CODE($1) = FUNCTION_DECL;
		} else {
			tree func_type = new_node(FUNCTION_TYPE, TREE_TYPE($1));
			TREE_TYPE($1) = func_type;
		}
		$$ = $1;
	}
			
	| direct_declarator LPAREN identifier_list RPAREN {
		ERROR("identifier_list not implemented");
	}
	;

pointer
	: STAR {
		$$ = new_node(PTR_TYPE, NULL);
	}
	| STAR pointer {
		$$ = new_node(PTR_TYPE, $2);
	}
	| STAR type_qualifier_list {
		ERROR("type_qualifier_list not implemented");
	}
	| STAR type_qualifier_list pointer {
		ERROR("type_qualifier_list not implemented");
	}
	;
	 
type_qualifier_list
	: type_qualifier {
		$$ = $1;
	}
	| type_qualifier_list type_qualifier {
		chain_append($1, $2);
		$$ = $1;
	}
	;

parameter_type_list
	: parameter_list {
		$$ = $1;
	}
	| parameter_list COMMA ELLIPSIS {
		ERROR("ELLIPSIS not implemented");
	}
	;

parameter_list
	: parameter_declaration {
		$$ = new_node(TREE_LIST, $1);
	}
	| parameter_list COMMA parameter_declaration {
		$$ = chain_append($1, new_node(TREE_LIST, $3));
	}
	;

parameter_declaration
	: declaration_specifiers declarator {
		TREE_TYPE($2) = type_append(TREE_TYPE($2), $1);
		TREE_CODE($2) = PARM_DECL;
		$$ = $1;
	}	
	| declaration_specifiers abstract_declarator {
		$2 = type_append($2, $1);
		$$ = new_node(PARM_DECL, $2);
	}
	| declaration_specifiers {
		$$ = new_node(PARM_DECL, $1);
	}
	;

/*	3.5. Type names */

type_name
	: specifier_qualifier_list abstract_declarator {
		type_append($1, TREE_TYPE($2));
		TREE_TYPE($2) = $1;
		$$ = $2;
	}
	| specifier_qualifier_list {
		$$ = new_node(TYPE_DECL, NULL);
		TREE_TYPE($$) = $1;
	}
	;

abstract_declarator
	: pointer {
		$$ = $1;
	}
	| pointer direct_abstract_declarator {
		type_append($1, TREE_TYPE($2));
		TREE_TYPE($2) = $1;
		$$ = $2;
	}
	| direct_abstract_declarator {
		$$ = $1;
	}
	;


direct_abstract_declarator
	: LPAREN abstract_declarator RPAREN {
		$$ = $2;
	}
	| LBRACKET RBRACKET {
		$$ = new_node(ARRAY_TYPE, NULL);
	}
	| LBRACKET constant_expression RBRACKET {
		$$ = new_node(ARRAY_TYPE, NULL); /* TODO constant_expression */
	}
	| direct_abstract_declarator LBRACKET RBRACKET {
		TREE_TYPE($1) = new_node(ARRAY_TYPE, TREE_TYPE($1));
		$$ = $1;
	}
	| direct_abstract_declarator LBRACKET constant_expression RBRACKET {
		TREE_TYPE($1) = new_node(ARRAY_TYPE, TREE_TYPE($1)); /* TODO constant_expression */
		$$ = $1;
	}
	| LPAREN parameter_type_list RPAREN  {
		$$ = new_node(FUNCTION_TYPE, NULL);
		TYPE_PARM_LIST($$) = $2;
	}
	| direct_abstract_declarator LPAREN RPAREN {
		$$ = new_node(FUNCTION_TYPE, TREE_TYPE($1));
	}
	| direct_abstract_declarator LPAREN parameter_type_list RPAREN {
		$$ = new_node(FUNCTION_TYPE, TREE_TYPE($1));
		TYPE_PARM_LIST($$) = $3;
	}
	;

/*	3.6. Type definitions */

constant
	: INTEGER_CONSTANT
	| FLOATING_CONSTANT
	| ENUMERATION_CONSTANT
	| CHARACTER_CONSTANT
	;

specifier_qualifier_list
	: type_specifier {
		$$ = $1;
	}
	| type_qualifier {
		ERROR("type_qualifier not implemented");
	}
	| type_specifier specifier_qualifier_list {
		ERROR("multiple type specifiers");
	}
	| type_qualifier specifier_qualifier_list {
		ERROR("multiple type qualifiers");
	}
	;

identifier_list
	: IDENTIFIER {
		$$ = new_node(TREE_LIST, $1);
	}
	| identifier_list COMMA IDENTIFIER {
		$$ = new_node(TREE_LIST, $3);
		chain_append($$, $1);
	}
	;

/*	3.7. Initialization */

initializer
	: assignement_expression {
		$$ = $1;
	}
	| LBRACE initializer_list RBRACE {
		$$ = $2;
	}
	| LBRACE initializer_list COMMA RBRACE {
		$$ = $2;
	}
	;

initializer_list
	: initializer {
		$$ = new_node(TREE_LIST, $1);
	}
	| initializer_list COMMA initializer {
		$$ = new_node(TREE_LIST, $3);
		chain_append($$, $1);
	}
	;

/* 4. Statements */

statement
	: labeled_statement
	| {
		start_block();
	} compound_statement {
		$$ = end_block($2);
	}
	| expression_statement
	| selection_statement
	| iteration_statement
	| jump_statement
	;

/* 	4.1. Labeled statements */

labeled_statement
	: IDENTIFIER COLON statement {
		$$ = build_label($1, $3);
	}
	| CASE constant_expression COLON statement {
		$$ = build_case($2, $4);
	}
	| DEFAULT COLON statement {
		$$ = build_default($3);
	}
	;

/*	4.2. Compound statements, or block */

compound_statement
	: LBRACE RBRACE {
		$$ = NULL;
	}
	| LBRACE statement_list RBRACE {
		$$ = $2;
	}
	|
	LBRACE declaration_list RBRACE {
		$$ = NULL;
	}
	|
	LBRACE declaration_list statement_list RBRACE {
		$$ = $3;
	}
	;

declaration_list
	: declaration {
		$$ = $1;
	}
	| declaration_list declaration {
		chain_append($1, $2);
		$$ = $1;
	}
	;

statement_list
	: statement {
		$$ = $1;
	}
	| statement_list statement {
		chain_append($1, $2);
		$$ = $1;
	}
	;

/*	4.3. Expression statements */

expression_statement
	: SEMICOLON {
		$$ = new_node(EMPTY_STMT, NULL);
	}
	| expression SEMICOLON {
		$$ = $1;
	}
	;

/*	4.4. Selection statements */

selection_statement
	: IF LPAREN expression RPAREN statement %prec THEN {
		$$ = build_if($3, $5, NULL);
	}
	| IF LPAREN expression RPAREN statement ELSE statement {
		$$ = build_if($3, $5, $7);
	}
	| SWITCH LPAREN expression RPAREN statement {
		ERROR("SWITCH not implemented");
	}
	;

/* 	4.5. Iteration statements */

iteration_statement
	: WHILE LPAREN expression RPAREN {
		start_while($3);
	} statement {
		$$ = end_while($6);
	}
	| {
		start_do_while();
	} DO statement WHILE LPAREN expression RPAREN SEMICOLON {
		$$ = end_do_while($6, $3);
	}
	| FOR LPAREN expression_statement expression_statement expression RPAREN {
		start_for($3, $4, $5);
	} statement {
		$$ = end_for($8);
	}
	;

/* 	4.6. Jump statements */

jump_statement
	: GOTO IDENTIFIER SEMICOLON {
		$$ = build_goto($2);
	}
	| CONTINUE SEMICOLON {
		$$ = build_continue();
	}
	| BREAK SEMICOLON {
		$$ = build_break();
	}
	| RETURN SEMICOLON {
		$$ = build_return(NULL);
	}
	| RETURN expression SEMICOLON {
		$$ = build_return($2);
	}
	;

/* 5. External definitions */

translation_unit
	: external_declaration 
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

/* 	5.1. Function definitions */

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {
		ERROR("declaration_list not implemented");
	}
	| declaration_specifiers declarator {
		$<tree>$ = new_node(FUNCTION_DECL, $2);
		type_append($2, $1);
		start_function($<tree>$);
	} compound_statement { 
		end_function($4);
	}
	| declarator declaration_list compound_statement {
		ERROR("declaration_list not implemented");
	}
	| declarator {
		type_append($1, new_node(INT_TYPE, NULL));
		$<tree>$ = new_node(FUNCTION_DECL, $1);
		start_function($<tree>$);
	} compound_statement {
		end_function($3);
	}
	;

argument_expression_list
	: assignement_expression
	| argument_expression_list COMMA assignement_expression {
		tree t = new_node(TREE_LIST, $3);
		$$ = chain_append($1, t);
	}
	;

%%

void yyerror(const char *msg) {
	fprintf(stderr, "Error: %s\n", msg);
}
