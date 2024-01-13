#include <stdio.h>
#include "tree.h"
#include "cimplify.h"
#include "args.h"
extern int yyparse(void);

extern void print_current_context(void);

extern tree current_context;

int main(int argc, char *argv[])
{
	yyparse();
	print_current_context();
	struct cimple_program *prog = cimplify(current_context);
	cimple_dump_program(prog);
}
