%{
#include <stdio.h>

void yyerror(const char * msg);

extern int yylex(void);
%}

%locations

%define parse.error verbose

%token AUTO DOUBLE INT STRUCT BREAK ELSE 
%token LONG SWITCH CASE ENUM REGISTER TYPEDEF CHAR
%token EXTERN RETURN UNION CONST FLOAT SHORT UNSIGNED
%token CONTINUE FOR SIGNED VOID DEFAULT GOTO SIZEOF
%token VOLATILE DO IF STATIC WHILE
%token IDENTIFIER INTEGER_CONSTANT FLOATING_CONSTANT
%token ENUMERATION_CONSTANT CHARACTER_CONSTANT STRING_LITERAL
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

%token TYPE_NAME

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
		$$ = build_deref(build_expr(ADD_EXPR, $1, $3));
	}
	| postfix_expression LPAREN RPAREN {
		$$ = build_call($1, NULL);
	}
	| postfix_expression LPAREN argument_expression_list RPAREN {
		$$ = build_call($1, $3);
	}
	| postfix_expression DOT IDENTIFIER {
		$$ = build_member_ref($1, $3);
	}
	| postfix_expression ARROW IDENTIFIER {
		$$ = build_deref(build_member_ref($1, $3));
	}
	| postfix_expression INCREMENT {
		$$ = build_incr_expr(POST_INCR_EXPR, $1);
	}
	| postfix_expression DECREMENT {
		$$ = build_incr_expr(POST_DECR_EXPR, $1);
	}
	;

/*	1.3. Unary expressions */

unary_expression
	: postfix_expression
	| PLUS_PLUS unary_expression {
		$$ = build_incr_expr(PRE_INCR_EXPR, $2);
	}
	| MINUS_MINUS unary_expression {
		$$ = build_incr_expr(PRE_DECR_EXPR, $2);
	}
	| unary_operator cast_expression {
		$$ = build_expr($1, NULL, $2);
	}
	| SIZEOF unary_expression {
		$$ = build_sizeof($2);
	}
	| SIZEOF LPAREN type_name RPAREN {
		$$ = build_sizeof($3);
	}
	;

unary_operator
	: AND { $$ = ADDR_EXPR; }
	| STAR { $$ = DEREF_EXPR; }
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
		$$ = build_conditional($1, $3, $5);
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
	: conditional_expression
	;

/* 3. Declarations */

declaration
	: declaration_specifiers SEMICOLON {
		/* Nothing to do */
	}
	| declaration_specifiers init_declarator_list SEMICOLON {
		for (tree t = $2; t != NULL; ) {
			type_append(TREE_VALUE(t), $1);
			emit_declaration(TREE_VALUE(t));

			tree next = TREE_CHAIN(t);
			free(t);
			t = next;
		}
	}
	;

declaration_specifiers
	: storage_class_specifier {
		YYERROR("storage_class_specifier not implemented");
	}
	| storage_class_specifier declaration_specifiers {
		YYERROR("storage_class_specifier not implemented");
	}
	| type_specifier { $$ = $1; }
	| type_specifier declaration_specifiers {
		if (is_qualifier($2)) {
			TYPE_QUALS($1) = $2;
			$$ = $1;
		} else {
			YYERROR("multiple type specifiers");
		}
	}
	| type_qualifier {
		$$ = $1;
	}
	| type_qualifier declaration_specifiers {
		if (is_qualifier($2)) {
			tree_chain_append($2, $1);
		} else {
			type_qual_append($2, $1);
		}
		$$ = $2;
	}
	;
	
init_declarator_list
	: init_declarator {
		$$ = new_node(TREE_LIST, $1);
	}
	| init_declarator_list COMMA init_declarator {
		$$ = new_node(TREE_LIST, $3);
		tree_chain_append($$, $1);
	}
	;

init_declarator
	: declarator {
		$$ = $1;
	}
	| declarator EQUAL initializer {
		$$ = $1;
		decl_set_init($$, $3);
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
	| SHORT { YYERROR("SHORT not implemented"); }
	| INT { $$ = new_node(INT_TYPE, NULL); }
	| LONG { YYERROR("LONG not implemented"); }
	| FLOAT { $$ = new_node(FLOAT_TYPE, NULL); }
	| DOUBLE { $$ = new_node(FLOAT_TYPE, NULL); }
	| SIGNED { YYERROR("SIGNED not implemented"); }
	| UNSIGNED { YYERROR("UNSIGNED not implemented"); }
	| struct_or_union_specifier { $$ = $1; }
	| enum_specifier { $$ = $1; }
	| TYPE_NAME { $$ = $1; }
	;

/*		3.2.1. Struct or union specifiers */

struct_or_union_specifier
	: struct_or_union LBRACE struct_declaration_list RBRACE
	| struct_or_union IDENTIFIER
	| struct_or_union IDENTIFIER LBRACE struct_declaration_list RBRACE
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list	
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list SEMICOLON
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list COMMA struct_declarator
	;

struct_declarator
	: declarator
	| COLON constant_expression
	| declarator COLON constant_expression
	;

/*		3.2.2. Enumeration specifiers */

enum_specifier
	: ENUM LBRACE enumerator_list RBRACE
	| ENUM IDENTIFIER LBRACE enumerator_list RBRACE
	| ENUM IDENTIFIER
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
	: CONST { $$ = new_node(CONST_QUAL, NULL); }
	| VOLATILE { $$ = new_node(VOLATILE_QUAL, NULL); }
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
			TYPE_ARGS(func_type) = $3;
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
		YYERROR("identifier_list not implemented");
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
		$$ = new_node(PTR_TYPE, NULL);
		TYPE_QUALS($$) = $2;
	}
	| STAR type_qualifier_list pointer {
		$$ = new_node(PTR_TYPE, $3);
		TYPE_QUALS($$) = $2;
	}
	;
	 
type_qualifier_list
	: type_qualifier {
		$$ = $1;
	}
	| type_qualifier_list type_qualifier {
		tree_chain_append($1, $2);
		$$ = $1;
	}
	;

parameter_type_list
	: parameter_list {
		$$ = $1;
	}
	| parameter_list COMMA ELLIPSIS {
		YYERROR("ELLIPSIS not implemented");
	}
	;

parameter_list
	: parameter_declaration {
		$$ = $1;
	}
	| parameter_list COMMA parameter_declaration {
		tree_chain_append($1, $3);
		$$ = $1;
	}
	;

parameter_declaration
	: declaration_specifiers declarator {
		type_append($2, $1);
		$$ = new_node(PARM_DECL, $2);
	}	
	| declaration_specifiers abstract_declarator {
		type_append($2, $1);
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
		TYPE_ARGS($$) = $2;
	}
	| direct_abstract_declarator LPAREN RPAREN {
		$$ = new_node(FUNCTION_TYPE, TREE_TYPE($1));
	}
	| direct_abstract_declarator LPAREN parameter_type_list RPAREN {
		$$ = new_node(FUNCTION_TYPE, TREE_TYPE($1));
		TYPE_ARGS($$) = $3;
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
	: type_specifier 
	| type_qualifier
	| type_specifier specifier_qualifier_list {
		if (is_qualifier($2)) {
			TYPE_QUALS($1) = $2;
			$$ = $1;
		} else {
			YYERROR("multiple type specifiers");
		}
	}
	| type_qualifier specifier_qualifier_list {
		if (is_qualifier($2)) {
			tree_chain_append($2, $1);
		} else {
			type_qual_append($2, $1);
		}
		$$ = $2;
	}
	;

identifier_list
	: IDENTIFIER {
		$$ = new_node(TREE_LIST, $1);
	}
	| identifier_list COMMA IDENTIFIER {
		$$ = new_node(TREE_LIST, $3);
		tree_chain_append($$, $1);
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
		tree_chain_append($$, $1);
	}
	;

/* 4. Statements */

statement
	: labeled_statement
	| compound_statement
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
	: {
		start_block();
	} LBRACE RBRACE {
		$$ = end_block(NULL);
	}
	| {
		start_block();
	} LBRACE statement_list RBRACE {
		$$ = end_block($2)
	}
	| {
		start_block();
	} LBRACE declaration_list RBRACE {
		$$ = end_block(NULL)
	}
	| {
		start_block();
	} LBRACE declaration_list statement_list RBRACE {
		$$ = end_block($3);
	}
	;

declaration_list
	: declaration {
		$$ = $1;
	}
	| declaration_list declaration {
		tree_chain_append($1, $2);
		$$ = $1;
	}
	;

statement_list
	: statement {
		$$ = $1;
	}
	| statement_list statement {
		tree_chain_append($1, $2);
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
		YYERROR("SWITCH not implemented");
	}
	;

/* 	4.5. Iteration statements */

iteration_statement
	: WHILE LPAREN expression RPAREN statement {
		$$ = build_while($3, $5);
	}
	| DO statement WHILE LPAREN expression RPAREN SEMICOLON {
		$$ = build_do_while($5, $2);
	}
	| FOR LPAREN expression_statement expression_statement RPAREN statement {
		$$ = build_for($3, $4, $5, $6); /* FIXME */
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
	: { start_unit(); } external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration
	;

/* 	5.1. Function definitions */

function_definition
	: declaration_specifiers declarator declaration_list compound_statement {
		YYERROR("declaration_list not implemented");
	}
	| declaration_specifiers declarator {
		$$ = new_node(FUNCTION_DECL, $2);
		type_append($2, $1);
		start_function($$);
	} compound_statement { 
		end_function($4);
	}
	| declarator declaration_list compound_statement {
		YYERROR("declaration_list not implemented");
	}
	| declarator {
		type_append($1, new_node(INT_TYPE, NULL));
		$$ = new_node(FUNCTION_DECL, $1);
		start_function($$);
	} compound_statement {
		end_function($3);
	}
	;

argument_expression_list
	: assignement_expression
	| argument_expression_list COMMA assignement_expression {
		$$ = new_node(TREE_LIST, $3);
		tree_chain_append($$, $1);
	}
	;

%%

void yyerror(const char *msg) {
	fprintf(stderr, "Error: %s\n", msg);
}
