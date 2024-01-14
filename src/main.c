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

/*
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "cimplify.h"
#include "args.h"

extern int yyparse(void);
extern FILE *yyin;

extern void print_current_context(void);

extern tree current_context;

void cimple_test(struct cimple_program *prog)
{
	prog->decl_size = 0;
	prog->func_size = 1;
	prog->decls = NULL;
	struct cimple_function *func = malloc(10 *sizeof(struct cimple_function));
	func[0].uid = 0;
	func[0].size = 4;
	struct cimple_instr *instr = malloc(50*sizeof(struct cimple_instr));
	instr[0].op = OP_ASSIGN;
	instr[0].arg1 = 5;
	instr[0].arg2 = 0;
	instr[0].ret = 0;
	instr[0].is_float = 0;
	instr[0].scope_1 = CIMPLE_CONST;
	instr[0].scope_2 = CIMPLE_NONE;
	instr[0].scope_ret = CIMPLE_LOCAL;
	instr[1].op = OP_ASSIGN;
	instr[1].arg1 = 6;
	instr[1].arg2 = 0;
	instr[1].ret = 1;
	instr[1].is_float = 0;
	instr[1].scope_1 = CIMPLE_CONST;
	instr[1].scope_2 = CIMPLE_NONE;
	instr[1].scope_ret = CIMPLE_LOCAL;
	instr[2].op = OP_ADD;
	instr[2].arg1 = 0;
	instr[2].arg2 = 1;
	instr[2].ret = 2;
	instr[2].is_float = 0;
	instr[2].scope_1 = CIMPLE_LOCAL;
	instr[2].scope_2 = CIMPLE_LOCAL;
	instr[2].scope_ret = CIMPLE_LOCAL;
	instr[3].op = OP_RETURN;
	instr[3].arg1 = 2;
	instr[3].arg2 = 0;
	instr[3].ret = 0;
	instr[3].is_float = 0;
	instr[3].scope_1 = CIMPLE_LOCAL;
	instr[3].scope_2 = CIMPLE_NONE;
	instr[3].scope_ret = CIMPLE_NONE;

	func[0].instrs = instr;
	prog->funcs = func;
}

int main(int argc, char *argv[])
{
	args_t args;
	init_args(&args); 
	parse_args( argc, argv,&args);
	FILE *in = fopen(args.input_file, "r");
	if (in == NULL) {
		fprintf(stderr, "Error: cannot open file %s\n", args.input_file);
		return 1;
	}
	yyin = in;
	yyparse();
	print_current_context();
	struct cimple_program *prog = cimplify(current_context);
	cimple_dump_program(prog);
	struct cimple_program prog;
	cimple_test(&prog);
	FILE *out = fopen("out.s", "w");
	if (out == NULL) {
		fprintf(stderr, "Error: cannot open file out.s\n");
		return 1;
	}
	process_three_address(prog, out);
	return 0;
}

*/