// norme du c 63 significant initial characters in an internal identifier, 31 significant initial characters in an external identifier
// on choisit 64 pour tout
#define MAX_IDENTIFIER_SIZE 64

#define PRIME 613
#define TABLE_SIZE 1009

enum id_predefined {
	main,
	// à discuter à propos de ça
};

typedef struct identifier_t {
	char id[MAX_IDENTIFIER_SIZE];
	int number;
	struct identifier_t *next;
} identifier_t;

typedef struct symbol_table {
	identifier_t *table[TABLE_SIZE];
	int nb_identifiers;
} symbol_table;

symbol_table create_symbol_table(void);

void test_malloc(void *ptr);

void display_table(symbol_table *table);

void table_init(symbol_table *table, char **keywords, int nb_keywords);

int get_identifier_number(symbol_table *table, char *id);

void free_table(symbol_table *table);
