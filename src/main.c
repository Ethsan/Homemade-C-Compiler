#include <stdio.h>
#include "args.h"
extern int yyparse(void);

extern void print_current_context(void);

int main(int argc, char *argv[])
{
	yyparse();
	print_current_context();
}
