%union {
	int ival;
}

%code requires {
	#include "location.h"
}

%locations
%define api.location.type {struct location}

%start program

%%

program
	: /* empty */
	;
