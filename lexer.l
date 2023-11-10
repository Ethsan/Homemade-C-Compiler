%{
#include "parser.tab.h"

int lineno = 1;
int column = 1;

#define YY_USER_ACTION  do { \
	yylloc.first_line = lineno; \
	yylloc.last_line = lineno; \
	 \
	yylloc.first_column = column; \
	column += yyleng; \
	yylloc.last_column = column; \
} while (0);
%}

%option noinput
%option noyywrap
%option nounput

SIGN [+-]

NONDIGIT [a-zA-Z_]
NONZERO_DIGIT [1-9]
DIGIT [0-9]
OCTAL_DIGIT [0-7]
HEX_DIGIT [0-9a-fA-F]

SUFFIX {NONDIGIT}({NONDIGIT}|{DIGIT})*

DIGIT_SEQUENCE {DIGIT}+
FRACTIONAL_CONSTANT {DIGIT_SEQUENCE}?\.{DIGIT_SEQUENCE}|{DIGIT_SEQUENCE}\.
EXPONENT_PART [eE]{SIGN}?{DIGIT_SEQUENCE}

FLOATING_CONSTANT {FRACTIONAL_CONSTANT}{EXPONENT_PART}?|{DIGIT_SEQUENCE}{EXPONENT_PART}

DECIMAL_CONSTANT {NONZERO_DIGIT}{DIGIT}*
OCTAL_CONSTANT 0{OCTAL_DIGIT}*
HEX_CONSTANT 0[xX]{HEX_DIGIT}+

INTEGER_CONSTANT {DECIMAL_CONSTANT}|{OCTAL_CONSTANT}|{HEX_CONSTANT}

C_CHAR [^'\n]|\\.

C_CHAR_SEQUENCE {C_CHAR}*

S_CHAR [^"\n]|\\.

S_CHAR_SEQUENCE {S_CHAR}*

IDENTIFIER {NONDIGIT}({NONDIGIT}|{DIGIT})*
%%

auto		{ return AUTO; }
double		{ return DOUBLE; }
int		{ return INT; }
struct		{ return STRUCT; }
break		{ return BREAK; }
else		{ return ELSE; }
long		{ return LONG; }
switch		{ return SWITCH; }
case		{ return CASE; }
enum		{ return ENUM; }
register	{ return REGISTER; }
typedef		{ return TYPEDEF; }
char		{ return CHAR; }
extern		{ return EXTERN; }
return		{ return RETURN; }
union		{ return UNION; }
const		{ return CONST; }
float		{ return FLOAT; }
short		{ return SHORT; }
unsigned	{ return UNSIGNED; }
continue	{ return CONTINUE; }
for		{ return FOR; }
signed		{ return SIGNED; }
void		{ return VOID; }
default		{ return DEFAULT; }
goto		{ return GOTO; }
sizeof		{ return SIZEOF; }
volatile	{ return VOLATILE; }
do		{ return DO; }
if		{ return IF; }
static		{ return STATIC; }
while		{ return WHILE; }

	/* Operators */
\.	{ return DOT; }
\-\>	{ return ARROW; }
\+\+	{ return INCREMENT; }
\-\-	{ return DECREMENT; }
\&	{ return AND; }
\*	{ return STAR; }
\+	{ return PLUS; }
\-	{ return MINUS; }
\~	{ return TILDE; }
\!	{ return EXCLAMATION; }
\/	{ return SLASH; }
\%	{ return PERCENT; }

\<\<	{ return LSHIFT; }
\>\>	{ return RSHIFT; }
\<	{ return LESS_THAN; }
\>	{ return GREATER_THAN; }
\<\=	{ return LESS_THAN_EQUAL; }
\>\=	{ return GREATER_THAN_EQUAL; }
\=\=	{ return EQUAL_EQUAL; }
\!\=	{ return NOT_EQUAL; }

\^	{ return XOR; }
\|	{ return OR; }
\&\&	{ return AND_AND; }
\|\|	{ return OR_OR; }
\?	{ return QUESTION; }
\:	{ return COLON; }
\#	{ return HASH; }
\#\#	{ return HASH_HASH; }

=	{ return EQUAL; }
\*=	{ return STAR_EQUAL; }
\/=	{ return SLASH_EQUAL; }
%=	{ return PERCENT_EQUAL; }
\+=	{ return PLUS_EQUAL; }
-=	{ return MINUS_EQUAL; }
\<\<=	{ return LSHIFT_EQUAL; }
>>=	{ return RSHIFT_EQUAL; }
&=	{ return AND_EQUAL; }
\^=	{ return XOR_EQUAL; }
\|=	{ return OR_EQUAL; }

	/* Punctuators */
\[	{ return LBRACKET; }
\]	{ return RBRACKET; }
\(	{ return LPAREN; }
\)	{ return RPAREN; }
\{	{ return LBRACE; }
\}	{ return RBRACE; }
\;	{ return SEMICOLON; }
\,	{ return COMMA; }
\.\.\.	{ return ELLIPSIS; }

	/* Identifiers */
{IDENTIFIER} {
	return IDENTIFIER;
}

	/* Integer constants */
{INTEGER_CONSTANT}{SUFFIX}? {
	return INTEGER_CONSTANT;
}

	/* Floating constants */
{FLOATING_CONSTANT}{SUFFIX}? {
	return FLOATING_CONSTANT;
}

	/* Character constants */
\'{C_CHAR_SEQUENCE}\' {
	yylloc.first_column += 1;
	yylloc.last_column -= 1;
	return CHARACTER_CONSTANT;
}

L\'{C_CHAR_SEQUENCE}\' {
	yylloc.first_column += 2;
	yylloc.last_column -= 1;
	return CHARACTER_CONSTANT;
}

	/* String literals */
\"{S_CHAR_SEQUENCE}\" {
	yylloc.first_column += 1;
	yylloc.last_column -= 1;
	return STRING_LITERAL;
}

L\"{S_CHAR_SEQUENCE}\" {
	yylloc.first_column += 2;
	yylloc.last_column -= 1;
	return STRING_LITERAL;
}
	/* Newlines */
\n {
	lineno++;
	column = 1;
}

	/* Whitespace */
[ \t]+ { /* ignore whitespace */ }

. {
	return yytext[0];
}


%%
