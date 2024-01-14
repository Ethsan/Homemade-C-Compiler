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

struct cimple_function *cimple_new_function(struct cimple_program *prog, uint uid)
{
	void *tmp = realloc(prog->funcs, (prog->func_size + 1) * sizeof(struct cimple_function));
	if (tmp == NULL)
		err(EXIT_FAILURE, "realloc");

	prog->funcs = tmp;
	struct cimple_function *func = &prog->funcs[prog->func_size++];
	func->uid = uid;
	func->size = 0;
	func->capacity = 0;
	func->instrs = NULL;
	return func;
}

uint cimple_new_string(struct cimple_program *prog, const char *str)
{
	void *tmp = realloc(prog->decls, (prog->decl_size + 1) * sizeof(struct cimple_string));
	if (tmp == NULL)
		err(EXIT_FAILURE, "realloc");

	prog->decls = tmp;
	struct cimple_string *new_str = &prog->decls[prog->decl_size++];
	new_str->uid = prog->decl_size;
	new_str->size = strlen(str);
	new_str->str = strdup(str);

	return new_str->uid;
}

void cimple_print_reg(enum cimple_scope type, uint value)
{
	switch (type) {
	case CIMPLE_TEXT:
		printf("T%u", value);
		break;
	case CIMPLE_LOCAL:
		printf("L%u", value);
		break;
	case CIMPLE_ARG:
		printf("A%u", value);
		break;
	case CIMPLE_CONST:
		printf("%u", value);
		break;
	case CIMPLE_UID:
		printf("<%u>", value);
		break;
	default:
		printf("NULL");
		break;
	}
}

void cimple_print_op(enum cimple_op op)
{
	switch (op) {
	case OP_ADD:
		printf("ADD");
		break;
	case OP_SUB:
		printf("SUB");
		break;
	case OP_MUL:
		printf("MUL");
		break;
	case OP_DIV:
		printf("DIV");
		break;
	case OP_MOD:
		printf("MOD");
		break;
	case OP_NEG:
		printf("NEG");
		break;
	case OP_AND:
		printf("AND");
		break;
	case OP_OR:
		printf("OR");
		break;
	case OP_NOT:
		printf("NOT");
		break;
	case OP_XOR:
		printf("XOR");
		break;
	case OP_ASSIGN:
		printf("ASSIGN");
		break;
	case OP_GOTO:
		printf("GOTO");
		break;
	case OP_GREATER:
		printf("GREATER");
		break;
	case OP_LESS:
		printf("LESS");
		break;
	case OP_GREATER_EQ:
		printf("GREATER_EQ");
		break;
	case OP_LESS_EQ:
		printf("LESS_EQ");
		break;
	case OP_EQ_EQ:
		printf("EQ_EQ");
		break;
	case OP_NOT_EQ:
		printf("NOT_EQ");
		break;
	case OP_CONVERT_TO_INT:
		printf("CONVERT_TO_INT");
		break;
	case OP_CONVERT_TO_FLOAT:
		printf("CONVERT_TO_FLOAT");
		break;
	case OP_CONVERT_BOOL:
		printf("CONVERT_BOOL");
		break;
	case OP_SYSCALL:
		printf("SYSCALL");
		break;
	case OP_CALL:
		printf("CALL");
		break;
	case OP_PARAM:
		printf("PARAM");
		break;
	case OP_RETURN:
		printf("RETURN");
		break;
	case OP_LD:
		printf("LD");
		break;
	case OP_ST:
		printf("ST");
		break;
	case OP_ALLOC:
		printf("ALLOC");
		break;
	case OP_FREE:
		printf("FREE");
		break;
	default:
		printf("NULL");
		break;
	}
}

void cimple_print_instr(struct cimple_instr *instr)
{
	printf("%d:\t", instr->uid);
	cimple_print_op(instr->op);
	printf("\t");
	cimple_print_reg(instr->scope_ret, instr->ret);
	printf("\t");
	cimple_print_reg(instr->scope_1, instr->arg1);
	printf("\t");
	cimple_print_reg(instr->scope_2, instr->arg2);
	printf("\t");
	printf( instr->is_float ? "float\n" : "int\n");
}

void cimple_dump_program(struct cimple_program *prog)
{
	printf("Program:\n");
	for (uint32_t i = 0; i < prog->decl_size; i++) {
		struct cimple_string *str = &prog->decls[i];
		printf("String %u: %s\n", str->uid, str->str);
	}
	for (uint32_t i = 0; i < prog->func_size; i++) {
		struct cimple_function *func = &prog->funcs[i];
		printf("Function %u:\n", func->uid);
		for (uint32_t j = 0; j < func->size; j++) {
			struct cimple_instr *instr = &func->instrs[j];
			cimple_print_instr(instr);
		}
	}
}
