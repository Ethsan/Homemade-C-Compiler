#define MAX_IDENTIFIER_SIZE 64

#define PRIME 613
#define TABLE_SIZE 1009

typedef struct identifier_t {
	char name[MAX_IDENTIFIER_SIZE];
	int number;
	int type;
	// for functions
	int nb_params;
	// for tables
	int nb_dimensions;
	int *dimensions;

	int mem_size;
	struct identifier_t *next;
} identifier_t;

typedef struct symbol_table {
	identifier_t *table[TABLE_SIZE];
	int nb_identifiers;
	int block_number;
} symbol_table;

symbol_table create_symbol_table(void);

void test_malloc(void *ptr);

void display_table(symbol_table *table);

void table_init(symbol_table *table, char **keywords, int nb_keywords);

int get_identifier_number(symbol_table *table, char *id);

void free_table(symbol_table *table);
