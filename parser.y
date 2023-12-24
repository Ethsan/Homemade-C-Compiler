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

%token HASH HASH_HASH
%token TYPE_NAME

%right THEN ELSE

%start translation-unit

%%
/* 1. Expressions */

/*	 1.1. Primary expressions */

primary-expression
	: IDENTIFIER
	| constant
	| STRING_LITERAL
	| LPAREN expression RPAREN
	;

/*	1.2. Postfix expressions */

postfix-expression
	: primary-expression
	| postfix-expression LBRACKET expression RBRACKET
	| postfix-expression LPAREN RPAREN
	| postfix-expression LPAREN argument-expression-list RPAREN
	| postfix-expression DOT IDENTIFIER
	| postfix-expression ARROW IDENTIFIER
	| postfix-expression INCREMENT
	| postfix-expression DECREMENT
	;

/*	1.3. Unary expressions */

unary-expression
	: postfix-expression
	| PLUS_PLUS unary-expression
	| MINUS_MINUS unary-expression
	| unary-operator cast-expression
	| SIZEOF unary-expression
	| SIZEOF LPAREN type-name RPAREN
	;

unary-operator
	: AND
	| STAR
	| PLUS
	| MINUS
	| TILDE
	| EXCLAMATION
	;

/*	1.4. Cast operators */

cast-expression
	: unary-expression
	| LPAREN type-name RPAREN cast-expression
	;
	
/*	1.5. Multiplicative operators */

multiplicative-expression
	: cast-expression
	| multiplicative-expression STAR cast-expression
	| multiplicative-expression SLASH cast-expression
	| multiplicative-expression PERCENT cast-expression
	;

/*	1.6. Additive operators */

additive-expression
	: multiplicative-expression
	| additive-expression PLUS multiplicative-expression
	| additive-expression MINUS multiplicative-expression
	;

/*	1.7. Bitwise shift operators */

shift-expression
	: additive-expression
	| shift-expression LSHIFT additive-expression
	| shift-expression RSHIFT additive-expression
	;

/*	1.8. Relational operators */

relational-expression
	: shift-expression
	| relational-expression LESS_THAN shift-expression
	| relational-expression GREATER_THAN shift-expression
	| relational-expression LESS_THAN_EQUAL shift-expression
	| relational-expression GREATER_THAN_EQUAL shift-expression
	;

/*	1.9. Equality operators */

equality-expression
	: relational-expression
	| equality-expression EQUAL_EQUAL relational-expression
	| equality-expression NOT_EQUAL relational-expression
	;

/*	1.10. Bitwise AND operator */

AND-expression
	: equality-expression
	| AND-expression AND equality-expression
	;

/*	1.11. Bitwise exclusive OR operator */

exclusive-OR-expresion
	: AND-expression 
	| exclusive-OR-expresion XOR AND-expression
	;

/*	1.12. Bitwise inclusive OR operator */

inclusive-OR-expression
	: exclusive-OR-expresion
	| inclusive-OR-expression OR exclusive-OR-expresion
	;

/*	1.13. Logical AND operator */

logical-AND-expression
	: inclusive-OR-expression
	| logical-AND-expression AND_AND inclusive-OR-expression
	;

/*	1.14. Logical OR operator */

logical-OR-expression
	: logical-AND-expression
	| logical-OR-expression OR_OR logical-AND-expression
	;

/*	1.15. Conditional operator */

conditional-expression
	: logical-OR-expression 
	| logical-OR-expression QUESTION expression COLON conditional-expression
	;

/*	1.16. Assignment operators */

assignement-expression
	: conditional-expression
	| unary-expression assignement-operator assignement-expression
	;

assignement-operator
	: EQUAL
	| STAR_EQUAL
	| SLASH_EQUAL
	| PERCENT_EQUAL
	| PLUS_EQUAL
	| MINUS_EQUAL
	| LSHIFT_EQUAL
	| RSHIFT_EQUAL
	| AND_EQUAL
	| XOR_EQUAL
	| OR_EQUAL
	;

/*	1.17. Comma operator */

expression
	: assignement-expression
	| expression COMMA assignement-expression
	;

/* 2. Constant Expressions */

constant-expression
	: conditional-expression
	;

/* 3. Declarations */

declaration
	: declaration-specifiers SEMICOLON
	| declaration-specifiers init-declarator-list SEMICOLON
	;

declaration-specifiers
	: storage-class-specifier
	| storage-class-specifier declaration-specifiers
	| type-specifier 
	| type-specifier declaration-specifiers
	| type-qualifier
	| type-qualifier declaration-specifiers
	;
	
init-declarator-list
	: init-declarator
	| init-declarator-list COMMA init-declarator
	;

init-declarator
	: declarator
	| declarator EQUAL initializer
	;

/*	3.1. Storage-class specifiers */

storage-class-specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

/*	3.2. Type specifiers */

type-specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| struct-or-union-specifier
	| enum-specifier
	| TYPE_NAME
	;

/*		3.2.1. Struct or union specifiers */

struct-or-union-specifier
	: struct-or-union LBRACE struct-declaration-list RBRACE
	| struct-or-union IDENTIFIER
	| struct-or-union IDENTIFIER LBRACE struct-declaration-list RBRACE
	;

struct-or-union
	: STRUCT
	| UNION
	;

struct-declaration-list	
	: struct-declaration
	| struct-declaration-list struct-declaration
	;

struct-declaration
	: specifier-qualifier-list struct-declarator-list SEMICOLON
	;

struct-declarator-list
	: struct-declarator
	| struct-declarator-list COMMA struct-declarator
	;

struct-declarator
	: declarator
	| COLON constant-expression
	| declarator COLON constant-expression
	;

/*		3.2.2. Enumeration specifiers */

enum-specifier
	: ENUM LBRACE enumerator-list RBRACE
	| ENUM IDENTIFIER LBRACE enumerator-list RBRACE
	| ENUM IDENTIFIER
	;

enumerator-list
	: enumerator
	| enumerator-list COMMA enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER EQUAL constant-expression
	;

/*	3.3. Type qualifiers */

type-qualifier
	: CONST
	| VOLATILE
	;

/*	3.4. Declarators */

declarator
	: pointer direct-declarator
	| direct-declarator
	;

direct-declarator
	: IDENTIFIER
	| LPAREN declarator RPAREN
	| direct-declarator LBRACKET RBRACKET
	| direct-declarator LBRACKET constant-expression RBRACKET
	| direct-declarator LPAREN parameter-type-list RPAREN
	| direct-declarator LPAREN RPAREN
	| direct-declarator LPAREN identifier-list RPAREN
	;

pointer
	: STAR
	| STAR pointer
	| STAR type-qualifier-list
	| STAR type-qualifier-list pointer
	;
	 
type-qualifier-list
	: type-qualifier
	| type-qualifier-list type-qualifier
	;

parameter-type-list
	: parameter-list
	| parameter-list COMMA ELLIPSIS
	;

parameter-list
	: parameter-declaration
	| parameter-list COMMA parameter-declaration
	;

parameter-declaration
	: declaration-specifiers declarator
	| declaration-specifiers abstract-declarator
	| declaration-specifiers
	;

/*	3.5. Type names */

type-name
	: specifier-qualifier-list abstract-declarator
	| specifier-qualifier-list
	;

abstract-declarator
	: pointer 
	| pointer direct-abstract-declarator
	| direct-abstract-declarator
	;


direct-abstract-declarator
	: LPAREN abstract-declarator RPAREN
	| LBRACKET RBRACKET
	| LBRACKET constant-expression RBRACKET
	| direct-abstract-declarator LBRACKET RBRACKET
	| direct-abstract-declarator LBRACKET constant-expression RBRACKET
	| LPAREN RPAREN
	| LPAREN parameter-type-list RPAREN
	| direct-abstract-declarator LPAREN RPAREN
	| direct-abstract-declarator LPAREN parameter-type-list RPAREN
	;

/*	3.6. Type definitions */

constant
	: INTEGER_CONSTANT
	| FLOATING_CONSTANT
	| ENUMERATION_CONSTANT
	| CHARACTER_CONSTANT
	;

specifier-qualifier-list
	: type-specifier 
	| type-qualifier
	| type-specifier specifier-qualifier-list
	| type-qualifier specifier-qualifier-list
	;

identifier-list
	: IDENTIFIER
	| identifier-list COMMA IDENTIFIER
	;

/*	3.7. Initialization */

initializer
	: assignement-expression
	| LBRACE initializer-list RBRACE
	| LBRACE initializer-list COMMA RBRACE
	;

initializer-list
	: initializer
	| initializer-list COMMA initializer
	;

/* 4. Statements */

statement
	: labeled-statement
	| compound-statement
	| expression-statement
	| selection-statement
	| iteration-statement
	| jump-statement
	;

/* 	4.1. Labeled statements */

labeled-statement
	: IDENTIFIER COLON statement
	| CASE constant-expression COLON statement
	| DEFAULT COLON statement
	;

/*	4.2. Compound statements, or block */

compound-statement
	: LBRACE RBRACE
	| LBRACE statement-list RBRACE
	| LBRACE declaration-list RBRACE
	| LBRACE declaration-list statement-list RBRACE
	;

declaration-list
	: declaration
	| declaration-list declaration
	;

statement-list
	: statement
	| statement-list statement
	;

/*	4.3. Expression statements */

expression-statement
	: SEMICOLON
	| expression SEMICOLON
	;

/*	4.4. Selection statements */

selection-statement
	: IF LPAREN expression RPAREN statement %prec THEN
	| IF LPAREN expression RPAREN statement ELSE statement
	| SWITCH LPAREN expression RPAREN statement
	;

/* 	4.5. Iteration statements */

iteration-statement
	: WHILE LPAREN expression RPAREN statement
	| DO statement WHILE LPAREN expression RPAREN SEMICOLON
	| FOR LPAREN expression-statement expression-statement RPAREN statement
	;

/* 	4.6. Jump statements */

jump-statement
	: GOTO IDENTIFIER SEMICOLON
	| CONTINUE SEMICOLON
	| BREAK SEMICOLON
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

/* 5. External definitions */

translation-unit
	: external-declaration
	| translation-unit external-declaration
	;

external-declaration
	: function-definition
	| declaration
	;

/* 	5.1. Function definitions */

function-definition
	: declaration-specifiers declarator declaration-list compound-statement
	| declaration-specifiers declarator compound-statement
	| declarator declaration-list compound-statement
	| declarator compound-statement
	;

argument-expression-list
	: assignement-expression
	| argument-expression-list COMMA assignement-expression
	;

%%

void yyerror(const char *msg) {
	fprintf(stderr, "Error: %s\n", msg);
}
