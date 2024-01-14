#pragma once
#include <stdint.h>
#include <stdio.h>
#include <sys/types.h>


enum cimple_op {
	OP_NULL, // No operation
	// opérateurs arithmétiques
	OP_ADD, // pas deux entiers/ flotant, et si entier alors sur le scope 2.
	OP_SUB, // idem
	OP_MUL, // idem
	OP_DIV, // le premier comme le second peuvent être des entiers ou des flottants
	OP_MOD, // reste de la division euclidienne
	OP_NEG,
	OP_AND,
	OP_OR,
	OP_NOT, // !
	OP_XOR,

	OP_ASSIGN,

	OP_GOTO,
	// relations
	OP_GREATER, // >
	OP_LESS, // <
	OP_GREATER_EQ, // >=
	OP_LESS_EQ, // <=
	OP_EQ_EQ, // ==
	OP_NOT_EQ, // !=
	OP_CONVERT_TO_INT, //(OP_CONVERT_TO_INT, var_float, _, var_int)
	OP_CONVERT_TO_FLOAT, //(OP_CONVERT_TO_FLOAT, var_int, _, var_float)

	OP_CONVERT_BOOL, // convertit en 0 ou 1

	OP_SYSCALL, // (OP_SYSCALL, numéro fonction, nombre de paramètres,var_retour)
	OP_CALL, // (OP_CALL, numéro_fonction, nombre de paramètres, var_retour)
	OP_PARAM, // (OP_PARAM, var, numéro du paramètre,syscall ou non )
	OP_RETURN, // (OP_RETURN, var_retour, _, _)
	OP_LD, // (OP_LD,address, _, uid)
	OP_ST, // (OP_ST, address, uid, _)
	OP_ALLOC, // (OP_ALLOC, size, _, ret) ret est la variable dans laquelle il y a l'adresse
	OP_FREE, // (OP_FREE,size,_,_) permet de free le dernier bloc alloué
};

enum cimple_scope {
	CIMPLE_NONE,
	CIMPLE_LOCAL,
	CIMPLE_TEXT,
	CIMPLE_ARG,
	CIMPLE_CONST,
	CIMPLE_UID,
};

struct cimple_instr {
	enum cimple_op op;
	enum cimple_scope scope_ret;
	enum cimple_scope scope_1;
	enum cimple_scope scope_2;

	uint32_t uid;

	uint32_t ret;
	union {
		uint32_t arg1;
		float farg1;
	};
	union {
		uint32_t arg2;
		float farg2;
	};

	uint is_float : 1;
};

struct cimple_function {
	uint32_t uid;
	int params_count;
	uint32_t size;
	uint32_t capacity;

	struct cimple_instr *instrs;
};

struct cimple_string {
	uint32_t uid;

	uint32_t size;
	char *str;
};

struct cimple_program {
	uint32_t decl_size;
	struct cimple_string *decls;

	uint32_t func_size;
	struct cimple_function *funcs;
};

struct cimple_program *cimple_new_program(void);

void cimple_free_program(struct cimple_program *prog);

int cimple_push_instr(struct cimple_function *func, struct cimple_instr instr);

struct cimple_function *cimple_new_function(struct cimple_program *prog);

void cimple_new_string(struct cimple_program *prog, const char *str);

void cimple_dump_program(struct cimple_program *prog);
