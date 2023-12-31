#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "hash_table.h"

symbol_table create_table(void)
{
	symbol_table table;
	table.nb_identifiers = 0;
	return table;
}

void test_malloc(void *ptr)
{
	if (ptr == NULL) {
		fprintf(stderr, "Erreur d'allocation mémoire\n");
		exit(1);
	}
}

int hash(char *id, int b, int mod)
{
	int hash = 0;
	for (int i = 0; i < (int)strlen(id); i++) {
		hash = hash * b + id[i];
		hash = hash % mod;
	}
	return hash;
}

void display_table(symbol_table *table)
{
	for (int i = 0; i < TABLE_SIZE; i++) {
		identifier_t *current = table->table[i];
		while (current != NULL) {
			printf("%s\n", current->name);
			current = current->next;
		}
	}
}

int add_identifier(symbol_table *table, char *id)
{
	int hash_value = hash(id, PRIME, TABLE_SIZE);
	identifier_t *identifier = malloc(sizeof(identifier_t));
	test_malloc(identifier);
	strcpy(identifier->name, id);
	identifier->next = NULL;
	identifier->number = table->nb_identifiers + 1;
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
	return identifier->number;
}

int is_in_table(symbol_table *table, char *id)
{
	int hash_value = hash(id, PRIME, TABLE_SIZE);
	identifier_t *current = table->table[hash_value];
	while (current != NULL) {
		if (strcmp(current->name, id) == 0) {
			return current->number;
		}
		current = current->next;
	}
	return 0;
}

int get_identifier_number(symbol_table *table, char *id)
{
	int n = 0;
	if ((n = is_in_table(table, id) == 0)) {
		return add_identifier(table, id);
	} else {
		return n;
	}
}

void free_table(symbol_table *table)
{
        for (int i = 0; i < TABLE_SIZE; i++) {
                identifier_t *current = table->table[i];
                while (current != NULL) {
                        identifier_t *tmp = current;
                        current = current->next;
                        free(tmp);
                }
        }
}
