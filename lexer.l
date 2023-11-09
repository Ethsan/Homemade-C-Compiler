/* 
Flex scanner for C

The phases 1 to 6 of translation are done in the scanner. The scanner
is responsible for the following:
	- Phase 1: Trigraphs
	- Phase 2: Line splicing
	- Phase 3: Tokenization
	- Phase 4: Macro expansion
	- Phase 5: Stringization
	- Phase 6: Character constants
*/
%{
#include "parser.tab.h"

char get_escape_char(char c);

char *curr_string;

extern char *entry_name;

struct named_location current_file = {
	.name = entry_name,
	.loc = { 0 }
};

struct named_location current_macro = {
	.name = NULL,
	.loc = { 0 }
};

int conditional_depth = 0;
int last_conditional_depth = 0;

/* Keep track of the number of escaped newlines to keep line count correct */
int escaped_newline = 0;

#define SET_INTEGER(value, type) do { \
	yylval.integer.value = value; \
	yylval.integer.type = type; \
} while (0)

%}

%option noinput
%option noyywrap

SIGN [+-]

NONDIGIT [a-zA-Z_]
NONZERO_DIGIT [1-9]
DIGIT [0-9]
OCTAL_DIGIT [0-7]
HEX_DIGIT [0-9a-fA-F]

UNSIGNED_SUFFIX [uU]
LONG_SUFFIX [lL]
FLOAT_SUFFIX [fF]

DIGIT_SEQUENCE {DIGIT}+
FRACTIONAL_CONSTANT {DIGIT_SEQUENCE}?\.{DIGIT_SEQUENCE}|{DIGIT_SEQUENCE}\.
EXPONENT_PART [eE]{SIGN}?{DIGIT_SEQUENCE}

FLOATING_CONSTANT {FRACTIONAL_CONSTANT}{EXPONENT_PART}?|{DIGIT_SEQUENCE}{EXPONENT_PART}

DECIMAL_CONSTANT {NONZERO_DIGIT}{DIGIT}*
OCTAL_CONSTANT 0{OCTAL_DIGIT}*
HEX_CONSTANT 0[xX]{HEX_DIGIT}+
INTEGER_CONSTANT {DECIMAL_CONSTANT}|{OCTAL_CONSTANT}|{HEX_CONSTANT}

/* Escape sequences long enough to be a char */
OCTAL_ESCAPE_SEQUENCE [\\]{OCTAL_DIGIT}{1,3}
HEX_ESCAPE_SEQUENCE [\\]x{HEX_DIGIT}*

C_CHAR [^']|\\.|{OCTAL_ESCAPE_SEQUENCE}|{HEX_ESCAPE_SEQUENCE}

C_CHAR_SEQUENCE {C_CHAR}+

S_CHAR [^"]|\\.

IDENTIFIER {NONDIGIT}({NONDIGIT}|{DIGIT})*

CONTROL_LINE ^#[ \t]*

%%

	/* Identifiers */
{IDENTIFIER} {
	return IDENTIFIER;
}

	/* Floating constants */
{FLOATING_CONSTANT} {
	return FLOATING_CONSTANT;
}


	/* Integer constants */
{INTEGER_CONSTANT}{UNSIGNED_SUFFIX}{LONG_SUFFIX} {
	errno = 0;
	yylval.integer.val = strtoul(yytext, NULL, 0);
	yylval.integer.type = TYPE_UNSIGNED_LONG;
	if (errno == ERANGE)
		return INTEGER_CONSTANT_WOVERFLOW;
	return INTEGER_CONSTANT;
}

{INTEGER_CONSTANT}{UNSIGNED_SUFFIX} {
	errno = 0;
	yylval.integer.val = strtoul(yytext, NULL, 0);
	if (yylval.integer.val <= UINT_MAX)
		yylval.integer.type = TYPE_UNSIGNED;
	else
		yylval.integer.type = TYPE_UNSIGNED_LONG;
	if (errno == ERANGE)
		return INTEGER_CONSTANT_WOVERFLOW;
	return INTEGER_CONSTANT;
}

{INTEGER_CONSTANT}{LONG_SUFFIX} {
	errno = 0;
	yylval.integer.val = strtol(yytext, NULL, 0);
	if (yylval.integer.val <= LONG_MAX)
		yylval.integer.type = TYPE_LONG;
	else
		yylval.integer.type = TYPE_UNSIGNED_LONG;
	if (errno == ERANGE)
		return INTEGER_CONSTANT_WOVERFLOW;
	return INTEGER_CONSTANT;
}

{DECIMAL_CONSTANT} {
	errno = 0;
	yylval.integer.val = strtol(yytext, NULL, 10);
	if (yylval.integer.val <= INT_MAX)
		yylval.integer.type = TYPE_INT;
	else if (yylval.integer.val <= LONG_MAX)
		yylval.integer.type = TYPE_LONG;
	else
		yylval.integer.type = TYPE_UNSIGNED_LONG;
	if (errno == ERANGE)
		return INTEGER_CONSTANT_WOVERFLOW;
	return INTEGER_CONSTANT;
}

{OCTAL_CONSTANT}|{HEX_CONSTANT} {
	errno = 0;
	yylval.integer.val = strtoul(yytext, NULL, 0);
	if (yylval.integer.val <= INT_MAX)
		yylval.integer.type = TYPE_INT;
	else if (yylval.integer.val <= UINT_MAX)
		yylval.integer.type = TYPE_UNSIGNED;
	else if (yylval.integer.val <= LONG_MAX)
		yylval.integer.type = TYPE_LONG;
	else
		yylval.integer.type = TYPE_UNSIGNED_LONG;
	if (errno == ERANGE)
		return INTEGER_CONSTANT_WOVERFLOW;
	return INTEGER_CONSTANT;
}

	/* Character constants */
\'{C_CHAR_SEQUENCE}\'([ \n] {
	yyless(yyleng - 1);
	BEGIN(CHAR_SEQUENCE);
	return CHAR_CONSTANT_START;
}

L\'{C_CHAR_SEQUENCE}\' {
	yyless(yyleng - 2);
	BEGIN(WCHAR_SEQUENCE);
	return WCHAR_CONSTANT_START;
}

<C_CHAR_LEXER>\' {
	BEGIN(INITIAL);
	return CHAR_CONSTANT_END;
}

<C_WCHAR_LEXER>\" {
	BEGIN(INITIAL);
	return WCHAR_CONSTANT_END;
}

<C_CHAR_LEXER>. {
	yylval.integer.val = yytext[0];
	yylval.integer.type = TYPE_CHAR;
	return CHAR_CONSTANT;
}

<C_CHAR_LEXER>. {
	yylval.integer.val = yytext[0];
	yylval.integer.type = TYPE_WCHAR;
	return WCHAR_CONSTANT;
}

<C_CHAR_LEXER>\\[0-3]{OCTAL_DIGIT}{0,2} {
	yylval.integer.type = TYPE_CHAR;
	yylval.integer.val = strtol(yytext, NULL, 8)
	return CHAR_CONSTANT;
}

<C_CHAR_LEXER>{OCTAL_ESCAPE_SEQUENCE} {
	return ERROR_OCTAL_ESCAPE_TOO_LARGE;
}

<C_WCHAR_LEXER>{OCTAL_ESCAPE_SEQUENCE} {
	yylval.integer.type = TYPE_CHAR;
	yylval.integer.val = strtol(yytext, NULL, 8)
	return CHAR_CONSTANT;
}

<C_CHAR_LEXER>\\x{HEX_DIGIT}{1,2} {
	yylval.integer.type = TYPE_CHAR;
	yylval.integer.val = strtol(yytext, NULL, 16);
	return CHAR_CONSTANT;
}

<C_CHAR_LEXER>{HEX_ESCAPE_SEQUENCE} {
	return ERROR_HEX_ESCAPE_TOO_LARGE;
}

<C_WCHAR_LEXER>\\x{HEX_DIGIT}{1,8} {
	yylval.integer.type = TYPE_WCHAR;
	yylval.integer.val = strtol(yytext, NULL, 16);
	return CHAR_CONSTANT;
}

<C_WCHAR_LEXER>{HEX_ESCAPE_SEQUENCE} {
	return ERROR_HEX_ESCAPE_TOO_LARGE;
}

<C_CHAR_LEXER>\\x {
	return ERROR_HEX_ESCAPE_NO_DIGITS;
}

<C_WCHAR_LEXER>\\x {
	return ERROR_HEX_ESCAPE_NO_DIGITS;
}


<C_CHAR_LEXER>{SINGLE_ESCAPE_SEQUENCE} {
	yylval.integer.type = TYPE_CHAR;
	yylval.integer.val = get_escape_char(yytext[1])
	return CHAR_CONSTANT;
}

<C_WCHAR_LEXER>{SINGLE_ESCAPE_SEQUENCE} {
	yylval.integer.type = TYPE_WCHAR;
	yylval.integer.val = get_escape_char(yytext[1])
	return WCHAR_CONSTANT;
}

<C_CHAR_LEXER>\\. {
	return ERROR_UNKNOWN_ESCAPE_SEQUENCE;
}

<C_WCHAR_LEXER>\\. {
	return ERROR_UNKNOWN_ESCAPE_SEQUENCE;
}

%%
