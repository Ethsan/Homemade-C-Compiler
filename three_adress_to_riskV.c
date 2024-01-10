#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "three_address_code.h"

int sp = 0;

typedef struct variable {
	int name; // t1, t2, t3, ...
	int emplacement;
} var;

typedef struct register_use {
	int use[8]; // on itilise que les registres a0 à a7
} register_use;

typedef struct risc_instruction {
	char register_arg1[3];
	char register_arg2[3];
	char register_result[3];
} risc_instruction;

void manage_register(three_address_instruction three_inst, risc_instruction *risc_inst)
{
}

void risc_assign(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	if (isdigit(instruction.arg1[1])) {
		fprintf(fp, "li %s %s\n", risc_inst.register_result, instruction.arg1);
	} else {
		fprintf(fp, "mv %s %s\n", risc_inst.register_result, instruction.arg1);
	}
}

void risc_add(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	if (isdigit(instruction.arg1[1]) && isdigit(instruction.arg2[1]))
		fprintf(fp, "li %s %d\n", risc_inst.register_result, atoi(instruction.arg1) + atoi(instruction.arg2));
	else if (isdigit(instruction.arg1[1]))
		fprintf(fp, "addi %s %s %d\n", risc_inst.register_result, risc_inst.register_arg2,
			atoi(instruction.arg1));
	else if (isdigit(instruction.arg2[1]))
		fprintf(fp, "addi %s %s %d\n", risc_inst.register_result, risc_inst.register_arg1,
			atoi(instruction.arg2));
	else
		fprintf(fp, "add %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
			risc_inst.register_arg2);
}

void risc_sub(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	if (isdigit(instruction.arg1[1]) && isdigit(instruction.arg2[1]))
		fprintf(fp, "li %s %d\n", risc_inst.register_result, atoi(instruction.arg1) - atoi(instruction.arg2));
	else if (isdigit(instruction.arg1[1]))
		fprintf(fp, "addi %s %s %d\n", risc_inst.register_result, risc_inst.register_arg2,
			-atoi(instruction.arg1));
	else if (isdigit(instruction.arg2[1]))
		fprintf(fp, "addi %s %s %d\n", risc_inst.register_result, risc_inst.register_arg1,
			-atoi(instruction.arg2));
	else
		fprintf(fp, "sub %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
			risc_inst.register_arg2);
}

void risc_mul(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	if (isdigit(instruction.arg1[1]) && isdigit(instruction.arg2[1]))
		fprintf(fp, "li %s %d\n", risc_inst.register_result, atoi(instruction.arg1) * atoi(instruction.arg2));
	else {
		if (isdigit(instruction.arg1[1])) {
			// on utilise les registres temporaire
			fprintf(fp, "li t0 %s\n", instruction.arg1);
			fprintf(fp, "mul %s %s t0\n", risc_inst.register_result, risc_inst.register_arg2);
		} else {
			if (isdigit(instruction.arg2[1])) {
				fprintf(fp, "li t0 %s\n", instruction.arg2);
				fprintf(fp, "mul %s %s t0\n", risc_inst.register_result, risc_inst.register_arg1);
			} else
				fprintf(fp, "mul %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
					risc_inst.register_arg2);
		}
	}
}

void risc_div(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	if (isdigit(instruction.arg1[1]) && isdigit(instruction.arg2[1]))
		fprintf(fp, "li %s %d\n", risc_inst.register_result, atoi(instruction.arg1) / atoi(instruction.arg2));
	else {
		if (isdigit(instruction.arg1[1])) {
			// on utilise les registres temporaire
			fprintf(fp, "li t0 %s\n", instruction.arg1);
			fprintf(fp, "div %s t0 %s\n", risc_inst.register_result, risc_inst.register_arg2);
		} else {
			if (isdigit(instruction.arg2[1])) {
				fprintf(fp, "li t0 %s\n", instruction.arg2);
				fprintf(fp, "div %s %s t0\n", risc_inst.register_result, risc_inst.register_arg1);
			} else
				fprintf(fp, "div %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
					risc_inst.register_arg2);
		}
	}
}

void risc_mod(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	if (isdigit(instruction.arg1[1]) && isdigit(instruction.arg2[1]))
		fprintf(fp, "li %s %d\n", risc_inst.register_result, atoi(instruction.arg1) % atoi(instruction.arg2));
	else {
		if (isdigit(instruction.arg1[1])) {
			// on utilise les registres temporaire
			fprintf(fp, "li t0 %s\n", instruction.arg1);
			fprintf(fp, "rem %s t0 %s\n", risc_inst.register_result, risc_inst.register_arg2);
		} else {
			if (isdigit(instruction.arg2[1])) {
				fprintf(fp, "li t0 %s\n", instruction.arg2);
				fprintf(fp, "rem %s %s t0\n", risc_inst.register_result, risc_inst.register_arg1);
			} else
				fprintf(fp, "rem %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
					risc_inst.register_arg2);
		}
	}
}

void risc_neg(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	if (isdigit(instruction.arg1[1]))
		fprintf(fp, "li %s %d\n", risc_inst.register_result, -atoi(instruction.arg1));
	else
		fprintf(fp, "neg %s %s\n", risc_inst.register_result, risc_inst.register_arg1);
}
void risc_and(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	if (isdigit(instruction.arg1[1]) && isdigit(instruction.arg2[1]))
		fprintf(fp, "li %s %d\n", risc_inst.register_result, atoi(instruction.arg1) + atoi(instruction.arg2));
	else if (isdigit(instruction.arg1[1]))
		fprintf(fp, "andi %s %s %d\n", risc_inst.register_result, risc_inst.register_arg2,
			atoi(instruction.arg1));
	else if (isdigit(instruction.arg2[1]))
		fprintf(fp, "andi %s %s %d\n", risc_inst.register_result, risc_inst.register_arg1,
			atoi(instruction.arg2));
	else
		fprintf(fp, "and %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
			risc_inst.register_arg2);
}

void risc_or(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	if (isdigit(instruction.arg1[1]) && isdigit(instruction.arg2[1]))
		fprintf(fp, "li %s %d\n", risc_inst.register_result, atoi(instruction.arg1) + atoi(instruction.arg2));
	else if (isdigit(instruction.arg1[1]))
		fprintf(fp, "ori %s %s %d\n", risc_inst.register_result, risc_inst.register_arg2,
			atoi(instruction.arg1));
	else if (isdigit(instruction.arg2[1]))
		fprintf(fp, "ori %s %s %d\n", risc_inst.register_result, risc_inst.register_arg1,
			atoi(instruction.arg2));
	else
		fprintf(fp, "or %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
			risc_inst.register_arg2);
}

void risc_not(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	if (isdigit(instruction.arg1[1]))
		fprintf(fp, "li %s %d\n", risc_inst.register_result, -atoi(instruction.arg1));
	else
		fprintf(fp, "not %s %s\n", risc_inst.register_result, risc_inst.register_arg1);
}

void risc_goto(three_address_instruction instruction, FILE *fp)
{
	fprintf(fp, "jal label_%s\n", instruction.result);
}

// place un entier dans un registre temporaire pour effectuer les opérations
void temp_register(risc_instruction *inst, FILE *fp)
{
	if (isdigit(inst->register_arg1[1])) {
		fprintf(fp, "li t0 %s\n", inst->register_arg1);
		strcpy(inst->register_arg1, "t0");
	}
	if (isdigit(inst->register_arg2[1])) {
		fprintf(fp, "li t1 %s\n", inst->register_arg2);
		strcpy(inst->register_arg2, "t1");
	}
}

void rics_greater(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	temp_register(&risc_inst, fp);
	printf("blt %s %s label_%s\n", risc_inst.register_arg2, risc_inst.register_arg1, instruction.result);
}

void risc_less(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	temp_register(&risc_inst, fp);
	printf("blt %s %s label_%s\n", risc_inst.register_arg1, risc_inst.register_arg2, instruction.result);
}

void risc_greater_eq(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	temp_register(&risc_inst, fp);
	printf("bge %s %s label_%s\n", risc_inst.register_arg1, risc_inst.register_arg2, instruction.result);
}

void risc_less_eq(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	temp_register(&risc_inst, fp);
	printf("bge %s %s label_%s\n", risc_inst.register_arg2, risc_inst.register_arg1, instruction.result);
}

void risc_eq(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	temp_register(&risc_inst, fp);
	printf("beq %s %s label_%s\n", risc_inst.register_arg1, risc_inst.register_arg2, instruction.result);
}

void risc_not_eq(three_address_instruction instruction, FILE *fp)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst);
	temp_register(&risc_inst, fp);
	printf("bne %s %s label_%s\n", risc_inst.register_arg1, risc_inst.register_arg2, instruction.result);
}

int is_goto(three_address_instruction instruction)
{
	if (instruction.op == OP_GOTO || instruction.op == OP_GREATER || instruction.op == OP_LESS ||
	    instruction.op == OP_GREATER_EQ || instruction.op == OP_LESS_EQ || instruction.op == OP_EQ_EQ ||
	    instruction.op == OP_NOT_EQ || instruction.op == OP_NOT) {
		return 1;
	}

	return 0;
}

void label_used(three_address_program three_address, int *label)
{
	for (int i = 0; i < three_address.size; i++) {
		three_address_instruction instruction = three_address.instructions[i];
		if (is_goto(instruction)) {
			int goto_label = atoi(instruction.result);
			label[goto_label] = 1;
		}
	}
}

int process_three_address(three_address_program three_address, char *output_file)
{
	FILE *fp;
	fp = fopen(output_file, "w");
	if (fp == NULL) {
		printf("Error output file!\n");
		exit(1);
	}

	int label[three_address.size];
	for (int i = 0; i < three_address.size; i++) {
		label[i] = 0;
	}
	label_used(three_address, label);

	for (int i = 0; i < three_address.size; i++) {
		three_address_instruction instruction = three_address.instructions[i];
		if (label[i] == 1) {
			fprintf(fp, "labe_%d :\n", i);
		}

		switch (instruction.op) {
		case OP_NULL:
			break;
		case OP_ADD:
			risc_add(instruction, fp);
			break;
		case OP_SUB:
			risc_sub(instruction, fp);
			break;
		case OP_MUL:

			break;
		case OP_DIV:

			break;
		case OP_MOD:

			break;
		case OP_NEG:

			break;
		case OP_ASSIGN:
			risc_assign(instruction, fp);
			break;
		case OP_GOTO:
			risc_goto(instruction, fp);
			break;
		case OP_GREATER:

			break;
		case OP_LESS:

			break;
		case OP_GREATER_EQ:

			break;
		case OP_LESS_EQ:

			break;
		case OP_EQ_EQ:

			break;
		case OP_NOT_EQ:
			break;
		case OP_NOT:

			break;
		case OP_CALL:

			break;
		case OP_PARAM:

			break;
		case OP_RETURN:
			break;
		case OP_FUNC:
			break;
		default:
			fprintf(stderr, "Invalid operation: %d\n", instruction.op);
			return 1;
		}
	}

	fclose(fp);
	return 0;
}