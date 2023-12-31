




enum three_address_op {
    OP_NULL, // No operation
    // opérateurs arithmétiques
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_MOD, // reste de la division euclidienne
    OP_NEG,

    OP_ASSIGN,
    
    OP_GOTO,
    // relations
    OP_GREATER, // >
    OP_LESS, // <
    OP_GREATER_EQ, // >=
    OP_LESS_EQ, // <=
    OP_EQ, // ==
    OP_NOT_EQ, // !=
    OP_AND, // &&
    OP_OR, // ||
    OP_NOT, // !

    OP_CALL,
    OP_PARAM,

};

typedef struct three_address_instruction {
	enum three_address_op op;
	char *arg1;
	char *arg2;
	char *result;
	int label;
} three_address_instruction;

typedef struct three_address_program {
	three_address_instruction *instructions;
	int size;
} three_address_program;