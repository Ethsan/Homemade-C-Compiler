typedef struct args_t {
	char *input_file;
	char *output_file;
	int print_ast;
	int print_cimple;
	int print_symbol_table;

} args_t;

void help(void);

void init_args(args_t *args);

int parse_args(int argc, char *argv[], args_t *args);

int check_args(args_t *args);
