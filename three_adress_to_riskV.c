#include <stdio.h>
#include <stdlib.h>
#include "three_address_code.h"


int is_goto(three_address_instruction instruction)
{
	if (instruction.op == OP_GOTO || instruction.op == OP_GREATER ||
	    instruction.op == OP_LESS || instruction.op == OP_GREATER_EQ ||
	    instruction.op == OP_LESS_EQ || instruction.op == OP_EQ ||
	    instruction.op == OP_NOT_EQ || instruction.op == OP_AND ||
	    instruction.op == OP_OR || instruction.op == OP_NOT) {
		return 1;
	}
	return 0;
}

void label_used(three_address_program three_address, int *label)
{
	for (int i = 0; i < three_address.size; i++) {
		three_address_instruction instruction =
			three_address.instructions[i];
		if (is_goto(instruction)) {
			int goto_label = atoi(instruction.result);
			label[goto_label] = 1;
		}
	}
}

int process_three_address(three_address_program three_address,
			  char *output_file)
{
	FILE *fp;
	fp = fopen(output_file, "w");
	if (fp == NULL) {
		printf("Error output file!\n");
		exit(1);
	}

        int label[three_address.size];
        for (int i = 0; i < three_address.size; i++){
                label[i] = 0;
        }
        label_used(three_address, label);


	for (int i = 0; i < three_address.size; i++) {
		three_address_instruction instruction =
			three_address.instructions[i];
                if (label[i] == 1) {
                        fprintf(fp, "labe_%d :\n", i);
                }
		switch (instruction.op) {
		case OP_NULL:
			break;
		case OP_ADD:
			fprintf(fp, "add %s %s %s\n", instruction.arg1,
				instruction.arg2, instruction.result);
			break;
		case OP_SUB:
			fprintf(fp, "sub %s %s %s\n", instruction.arg1,
				instruction.arg2, instruction.result);
			break;
		case OP_MUL:
			fprintf(fp, "mul %s %s %s\n", instruction.arg1,
				instruction.arg2, instruction.result);
			break;
		case OP_DIV:
			fprintf(fp, "div %s %s %s\n", instruction.arg1,
				instruction.arg2, instruction.result);
			break;
		case OP_MOD:
			fprintf(fp, "mod %s %s %s\n", instruction.arg1,
				instruction.arg2, instruction.result);
			break;
		case OP_NEG:
			fprintf(fp, "neg %s %s\n", instruction.arg1,
				instruction.result);
			break;
		case OP_ASSIGN:
			fprintf(fp, "assign %s %s\n", instruction.arg1,
				instruction.result);
			break;
		case OP_GOTO:
			fprintf(fp, "goto %s\n", instruction.result);
			break;
		case OP_GREATER:
			fprintf(fp, "greater %s %s %s\n", instruction.arg1,
				instruction.arg2, instruction.result);
			break;
		case OP_LESS:
			fprintf(fp, "less %s %s %s\n", instruction.arg1,
				instruction.arg2, instruction.result);
			break;
		case OP_GREATER_EQ:
			fprintf(fp, "greater_eq %s %s %s\n", instruction.arg1,
				instruction.arg2, instruction.result);
			break;
		case OP_LESS_EQ:
			fprintf(fp, "less_eq %s %s %s\n", instruction.arg1,
				instruction.arg2, instruction.result);
			break;
		case OP_EQ:
			fprintf(fp, "eq %s %s %s\n", instruction.arg1,
				instruction.arg2, instruction.result);
			break;
		case OP_NOT_EQ:
			fprintf(fp, "not_eq %s %s %s\n", instruction.arg1,
				instruction.arg2, instruction.result);
			break;
		case OP_AND:
			fprintf(fp, "and %s %s %s\n", instruction.arg1,
				instruction.arg2, instruction.result);
			break;
		case OP_OR:
			fprintf(fp, "or %s %s %s\n", instruction.arg1,
				instruction.arg2, instruction.result);
			break;
		case OP_NOT:
			fprintf(fp, "not %s %s\n", instruction.arg1,
				instruction.result);
			break;
		case OP_CALL:
			fprintf(fp, "call %s %s\n", instruction.arg1,
				instruction.result);
			break;
		case OP_PARAM:
			fprintf(fp, "param %s\n", instruction.result);
			break;
		default:
			fprintf(stderr, "Invalid operation: %d\n",
				instruction.op);
			return 1;
		}
	}

	fclose(fp);
	return 0;
}


void risk_add(three_address_instruction instruction, FILE *fp)
{


}

void risk_goto(three_address_instruction instruction, FILE *fp)
{
        fprintf(fp, "jal label_%s\n", instruction.result);
}