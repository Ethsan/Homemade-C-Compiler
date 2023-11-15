#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "hash_table.h"


typedef struct identifier_t {
	char id[MAX_IDENTIFIER_SIZE];
	void *binding;
	struct identifier_t *next;
} identifier_t;

typedef struct symbol_table {
	identifier_t *table[TABLE_SIZE];
	int nb_identifiers;
} symbol_table;

symbol_table create_table(void)
{
	symbol_table table;
	table.nb_identifiers = 0;
	return table;
}
int hash(char *id, int b, int mod)
{
	int hash = 0;
	for (int i = 0; i < (int)strlen(id); i++) {
		hash = hash*b + id[i];
		hash = hash % mod;
	}
	return hash;
}

void add_identifier(symbol_table *table, char *id)
{
	int hash_value = hash(id, PRIME, TABLE_SIZE);
	identifier_t *identifier = malloc(sizeof(identifier_t));
	strcpy(identifier->id, id);
	identifier->next = NULL;
	if (table->table[hash_value] == NULL) {
		table->table[hash_value] = identifier;
	} else {
		identifier_t *current = table->table[hash_value];
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = identifier;
	}
	table->nb_identifiers++;
}
