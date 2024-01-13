#include "cimple.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <err.h>

#define INITIAL_CAPACITY 10

struct cimple_program *cimple_new_program(void)
{
	struct cimple_program *prog = malloc(sizeof(struct cimple_program));
	if (prog == NULL)
		err(EXIT_FAILURE, "malloc");
	prog->decl_size = 0;
	prog->func_size = 0;
	prog->decls = NULL;
	prog->funcs = NULL;
	return prog;
}

void cimple_free_program(struct cimple_program *prog)
{
	for (uint32_t i = 0; i < prog->decl_size; i++) {
		free(prog->decls[i].str);
	}
	free(prog->decls);

	for (uint32_t i = 0; i < prog->func_size; i++) {
		free(prog->funcs[i].instrs);
	}
	free(prog->funcs);

	free(prog);
}

int cimple_push_instr(struct cimple_function *func, struct cimple_instr instr)
{
	if (func->size >= func->capacity) {
		func->capacity = func->capacity == 0 ? 1 : func->capacity * 2;
		void *tmp = realloc(func->instrs, func->capacity * sizeof(struct cimple_instr));
		if (tmp == NULL)
			err(EXIT_FAILURE, "realloc");
		func->instrs = tmp;
	}
	int index = func->size++;
	func->instrs[index] = instr;
	return index;

}

struct cimple_function *cimple_new_function(struct cimple_program *prog)
{
	void *tmp = realloc(prog->funcs, (prog->func_size + 1) * sizeof(struct cimple_function));
	if (tmp == NULL)
		err(EXIT_FAILURE, "realloc");

	prog->funcs = tmp;
	struct cimple_function *func = &prog->funcs[prog->func_size++];
	func->uid = prog->func_size;
	func->size = 0;
	func->capacity = 0;
	func->instrs = NULL;
	return func;
}

void cimple_new_string(struct cimple_program *prog, const char *str)
{
	void *tmp = realloc(prog->decls, (prog->decl_size + 1) * sizeof(struct cimple_string));
	if (tmp == NULL)
		err(EXIT_FAILURE, "realloc");

	prog->decls = tmp;
	struct cimple_string *new_str = &prog->decls[prog->decl_size++];
	new_str->uid = prog->decl_size;
	new_str->size = strlen(str);
	new_str->str = strdup(str);
}

void cimple_dump_program(struct cimple_program *prog)
{
	printf("Program:\n");
	for (uint32_t i = 0; i < prog->func_size; i++) {
		struct cimple_function *func = &prog->funcs[i];
		printf("Function %u:\n", func->uid);
		for (uint32_t j = 0; j < func->size; j++) {
			struct cimple_instr *instr = &func->instrs[j];
			printf("  Instruction %u: op=%d, scope_ret=%d, scope_1=%d, scope_2=%d, uid=%u, ret=%u, arg1=%u, arg2=%u, is_float=%u\n",
			       j, instr->op, instr->scope_ret, instr->scope_1, instr->scope_2, instr->uid, instr->ret,
			       instr->arg1, instr->arg2, instr->is_float);
		}
	}
}
