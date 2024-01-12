#include <stdint.h>
#include <sys/types.h>

enum cimple_op {
	OP_NULL, // No operation
	// opérateurs arithmétiques
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_DIV,
	OP_MOD, // reste de la division euclidienne
	OP_NEG,
	OP_AND,
	OP_OR,
	OP_NOT, // !

	OP_ASSIGN,

	OP_GOTO,
	// relations
	OP_GREATER, // >
	OP_LESS, // <
	OP_GREATER_EQ, // >=
	OP_LESS_EQ, // <=
	OP_EQ_EQ, // ==
	OP_NOT_EQ, // !=

	OP_SYSCALL,
	OP_CALL,
	OP_PARAM,
	OP_RETURN,
	OP_FUNC, // déclaration de fonction (OP_FUNC, _, nombre de paramètres, nom de la fonction)

};

enum cimple_scope {
	CIMPLE_LOCAL,
	CIMPLE_GLOBAL,
	CIMPLE_ARG,
	CIMPLE_CONST,
};

struct cimple_instr {
	enum cimple_op op;
	enum cimple_scope scope_ret;
	enum cimple_scope scope_1;
	enum cimple_scope scope_2;

	uint32_t uid;

	uint32_t ret;
	uint32_t arg1;
	uint32_t arg2;

	uint is_float : 1;
};

struct cimple_function {
	uint32_t uid;

	uint32_t size;
	uint32_t capacity;

	struct cimple_instr instrs[];
};

struct cimple_string {
	uint32_t uid;

	uint32_t size;
	char *str;
};

struct cimple_program {
	uint32_t decl_size;
	struct cimple_string **decls;

	uint32_t func_size;
	struct cimple_function **funcs;
};

struct cimple_program *cimple_new_program(void);

void cimple_free_program(struct cimple_program *prog);

void cimple_push_instr(struct cimple_function *func, struct cimple_instr instr);

struct cimple_function *cimple_new_function(struct cimple_program *prog);

void cimple_new_string(struct cimple_program *prog, const char *str);

void cimple_dump_program(struct cimple_program *prog);
