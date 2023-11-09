
void yyerror (const char * msg);

%token 	AUTO DOUBLE INT STRUCT BREAK ELSE \ 
	LONG SWITCH CASE ENUM REGISTER TYPEDEF CHAR \
	EXTERN RETURN UNION CONST FLOAT SHORT UNSIGNED \
	CONTINUE FOR SIGNED VOID DEFAULT GOTO SIZEOF \
	VOLATILE DO IF STATIC WHILE \
	IDENTIFIER INTEGER_CONSTANT FLOATING_CONSTANT \
	ENUMERATION_CONSTANT CHARACTER_CONSTANT STRING_LITERAL \
	LBRACKET RBRACKET LPAREN RPAREN LBRACE RBRACE \ 
	COMMA 	DOT ARROW INCREMENT DECREMENT AND STAR \
	PLUS MINUS TILDE EXCLAMATION SLASH PERCENT \
	LSHIFT RSHIFT LESS_THAN GREATER_THAN \
	LESS_THAN_EQUAL GREATER_THAN_EQUAL EQUAL \ 
	NOT_EQUAL EQUAL_EQUAL STAR_EQUAL SLASH_EQUAL \
	PERCENT_EQUAL PLUS_EQUAL MINUS_EQUAL LSHIFT_EQUAL \
	RSHIFT_EQUAL AND_EQUAL XOR_EQUAL OR_EQUAL \
	PLUS_PLUS MINUS_MINUS COLON QUESTION OR_OR AND_AND \
	OR XOR ELLIPSIS SEMICOLON


%start program

%%

program
	: /* empty */
	;

primary-expression
	: IDENTIFIER
	| constant
	| STRING_LITERAL
	| LPAREN expression RPAREN
	;

constant
	: INTEGER_CONSTANT
	| FLOATING_CONSTANT
	| ENUMERATION_CONSTANT
	| CHARACTER_CONSTANT
	;

expression
	: assignement-expression
	| expression COMMA assignement-expression
	;

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

conditional-expression
	: logical-OR-expression 
	| logical-OR-expression QUESTION expression COLON conditional-expression
	;

logical-OR-expression
	: logical-AND-expression
	| logical-OR-expression OR_OR logical-AND-expression
	;

logical-AND-expression
	: inclusive-OR-expression
	| logical-AND-expression AND_AND inclusive-OR-expression
	;

inclusive-OR-expression
	: exclusive-OR-expresion
	| inclusive-OR-expression OR exclusive-OR-expresion

exclusive-OR-expresion
	: AND-expression 
	| exclusive-OR-expresion XOR AND-expression
	;

AND-expression
	: equality-expression
	| AND-expression AND equality-expression
	;

equality-expression
	: relational-expression
	| equality-expression EQUAL_EQUAL relational-expression
	| equality-expression NOT_EQUAL relational-expression

relational-expression
	: shift-expression
	| relational-expression LESS_THAN shift-expression
	| relational-expression GREATER_THAN shift-expression
	| relational-expression LESS_THAN_EQUAL shift-expression
	| relational-expression GREATER_THAN_EQUAL shift-expression
	;

shift-expression
	: additive-expression
	| shift-expression LSHIFT additive-expression
	| shift-expression RSHIFT additive-expression
	;

additive-expression
	: multiplicative-expression
	| additive-expression PLUS multiplicative-expression
	| additive-expression MINUS multiplicative-expression
	;

multiplicative-expression
	: cast-expression
	| multiplicative-expression STAR cast-expression
	| multiplicative-expression SLASH cast-expression
	| multiplicative-expression PERCENT cast-expression
	;

cast-expression
	: unary-expression
	| LPAREN type-name RPAREN cast-expression
	;

type-name
	: specifier-qualifier-list abstract-declarator
	| specifier-qualifier-list
	;

abstract-declarator
	: pointer 
	| pointer direct-abstract-declarator
	| direct-abstract-declarator
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

type-qualifier
	: CONST
	| VOLATILE
	;

direct-abstract-declarator
	: LPAREN abstract-declarator RPAREN
	| LBRACKET RBRACKET
	| LBRACKET conditional-expression RBRACKET
	| direct-abstract-declarator LBRACKET RBRACKET
	| direct-abstract-declarator LBRACKET conditional-expression RBRACKET
	| LPAREN RPAREN
	| LPAREN parameter-type-list RPAREN
	| direct-abstract-declarator LPAREN RPAREN
	| direct-abstract-declarator LPAREN parameter-type-list RPAREN
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

specifier-qualifier-list
	: type-specifier 
	| type-qualifier
	| type-specifier specifier-qualifier-list
	| type-qualifier specifier-qualifier-list
	;

declaration
	: declaration-specifiers SEMICOLON
	| declaration-specifiers init-declarator-list SEMICOLON
	;

declaration-list
	: declaration
	| declaration-list declaration
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

storage-class-specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

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
	| typedef-name
	;

typedef-name
	: IDENTIFIER
	;
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

identifier-list
	: IDENTIFIER
	| identifier-list COMMA IDENTIFIER
	;
initializer
	: assignment-expression
	| LBRACE initializer-list RBRACE
	| LBRACE initializer-list COMMA RBRACE
	;

enum-specifier
	: ENUM LBRACE enumerator-list RBRACE
	| ENUM IDENTIFIER LBRACE enumerator-list RBRACE
	| ENUM IDENTIFIER
	;
	 
statement
	: labeled-statement
	| compound-statement
	| expression-statement
	| selection-statement
	| iteration-statement
	| jump-statement
	;

statement-list
	: statement
	| statement-list statement
	;

labeled-statement
	: IDENTIFIER COLON statement
	| CASE constant-expression COLON statement
	| DEFAULT COLON statement
	;

constant-expression
	: conditional-expression
	;

compound-statement
	: LBRACE RBRACE
	| LBRACE statement-list RBRACE
	| LBRACE declaration-list RBRACE
	| LBRACE declaration-list statement-list RBRACE
	;

expression-statement
	: SEMICOLON
	| expression SEMICOLON
	;

selection-statement
	: IF LPAREN expression RPAREN statement
	| IF LPAREN expression RPAREN statement ELSE statement
	| SWITCH LPAREN expression RPAREN statement
	;

iteration-statement
	: WHILE LPAREN expression RPAREN statement
	| DO statement WHILE LPAREN expression RPAREN SEMICOLON
	| FOR LPAREN expression-statement expression-statement RPAREN statement
	;

jump-statement
	: GOTO IDENTIFIER SEMICOLON
	| CONTINUE SEMICOLON
	| BREAK SEMICOLON
	| RETURN SEMICOLON
	| RETURN expression SEMICOLON
	;

translation-unit
	: external-declaration
	| translation-unit external-declaration
	;

external-declaration
	: function-definition
	| declaration
	;

function-definition
	: declaration-specifiers declarator
	| compound-statement
	| declaration-list compound-statement
	;
