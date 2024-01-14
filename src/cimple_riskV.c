#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "cimple.h"

typedef struct risc_instruction {
	char register_arg1[5];
	char register_arg2[5];
	char register_result[5];
} risc_instruction;

// on utilise que les registres s0 à s11 et les registres temporaire t0 à t6
// on met
typedef struct register_manager {
	int nb_int;
	int nb_float;
	int *int_used;
	int *float_used;
	// -1 si non utilisé
	int register_int[12];
	int register_float[12];
	struct register_manager *global_manager;
	struct cimple_function *current_func;
	int current_inst_index;
} register_manager;

int is_in(int *tab, int size, int value, int *index)
{
	for (int i = 0; i < size; i++) {
		if (tab[i] == value) {
			if (index != NULL)
				*index = i;
			return 1;
		}
	}
	return 0;
}
void get_var_inst(struct cimple_instr instruction, int *var)
{
	if (instruction.scope_1 == CIMPLE_LOCAL)
		var[0] = instruction.arg1;
	if (instruction.scope_2 == CIMPLE_LOCAL)
		var[1] = instruction.arg2;
	if (instruction.scope_ret == CIMPLE_LOCAL)
		var[2] = instruction.ret;
}
// le but de cette fonction est de trouver le registre qui sera le moins utilisé à l'avenir
int var_less_used(register_manager *manager, int var_is_float, int *index_var_less_used)
{
	struct cimple_function *func = manager->current_func;
	int var_use[12] = { 0 };
	for (int i = manager->current_inst_index; i < (int)func->size; i++) {
		struct cimple_instr instruction = func->instrs[i];
		int index = -1;
		if (var_is_float == 1 && instruction.is_float == 1) {
			int var[3] = { -1, -1, -1 };
			get_var_inst(instruction, var);
			for (int j = 0; j < 3; j++) {
				if (var[j] != -1) {
					int index = -1;
					if (is_in(manager->register_float, 12, var[j], &index)) {
						var_use[index] = 1;
					}
				}
			}
		}
		if (var_is_float == 0 && instruction.is_float == 0) {
			int var[3] = { -1, -1, -1 };
			get_var_inst(instruction, var);
			for (int j = 0; j < 3; j++) {
				if (var[j] != -1) {
					int index = -1;
					if (is_in(manager->register_int, 12, var[j], &index)) {
						var_use[index] = 1;
					}
				}
			}
		}
		int count_zero = 0;
		for (int j = 0; j < 12; j++) {
			if (var_use[j] == 0) {
				count_zero++;
			}
		}

		if (count_zero == 0) {
			// on prend le registre qui sera utilisé le plus tard
			*index_var_less_used = index;
			if (var_is_float == 1)
				return manager->register_float[index];
			else
				return manager->register_int[index];
		}
	}
	int index = -1;
	if (is_in(var_use, 12, 0, &index)) {
		*index_var_less_used = index;
		if (var_is_float == 1)
			return manager->register_float[index];
		else
			return manager->register_int[index];
	}
	// on ne devrait jamais arriver ici
	fprintf(stderr, "Error: var_less_used\n");
	exit(1);
}

// var t2 t3 utilisé pour les variable decl et t2 t3 t4 ft1 ft2 ft3 pour les arguments
// renvoie 1 si il y a besoin de rétablir les registres après (que pour les arguments > 8)
int manage_register(struct cimple_instr instruction, risc_instruction *risc_inst, int use_arg1, int use_arg2,
		    int use_ret, register_manager *manager, FILE *fp)
{
	int restore = 0;
	if (instruction.is_float) {
		if (use_arg1) {
			if (instruction.scope_1 == CIMPLE_LOCAL) {
				int index = -1;
				if (is_in(manager->register_float, 12, instruction.arg1, &index)) {
					sprintf(risc_inst->register_arg1, "fs%d", index);
				} else {
					if (is_in(manager->register_float, 12, -1, &index)) {
						sprintf(risc_inst->register_arg1, "fs%d", index);
						manager->register_float[index] = instruction.arg1;
					} else {
						int register_var_push = 0;
						int var_to_push = var_less_used(manager, 1, &register_var_push);
						int addr_vat_to_push = 0;
						if (!is_in(manager->float_used, manager->nb_float, var_to_push,
							   &addr_vat_to_push)) {
							fprintf(stderr, "Error: var not in float_use\n");
							exit(1);
						}
						fprintf(fp, "fsw fs%d %d(t5)\n", register_var_push,
							-(addr_vat_to_push + 1) * 4);

						if (!is_in(manager->float_used, manager->nb_float, instruction.arg1,
							   &index)) {
							fprintf(stderr, "Error: var not in float_use\n");
							exit(1);
						}
						fprintf(fp, "flw fs%d %d(t5)\n", register_var_push, -(index + 1) * 4);
						sprintf(risc_inst->register_arg1, "fs%d", register_var_push);
						manager->register_float[register_var_push] = instruction.arg1;
					}
				}
			}
			if (instruction.scope_1 == CIMPLE_ARG) {
				if (instruction.arg1 < 8)
					sprintf(risc_inst->register_arg1, "fa%d", instruction.arg1);
				else
					sprintf(risc_inst->register_arg1, "ft1");
				fprintf(fp, "fsw ft1 %d(t6)\n", (instruction.arg1 - 8) * 4);
			}
		}
		if (use_arg2) {
			if (instruction.scope_2 == CIMPLE_LOCAL) {
				int index = -1;
				if (is_in(manager->register_float, 12, instruction.arg2, &index)) {
					sprintf(risc_inst->register_arg2, "fs%d", index);
				} else {
					if (is_in(manager->register_float, 12, -1, &index)) {
						sprintf(risc_inst->register_arg2, "fs%d", index);
						manager->register_float[index] = instruction.arg2;
					} else {
						int register_var_push = 0;
						int var_to_push = var_less_used(manager, 1, &register_var_push);
						int addr_vat_to_push = 0;
						if (!is_in(manager->float_used, manager->nb_float, var_to_push,
							   &addr_vat_to_push)) {
							fprintf(stderr, "Error: var not in float_use\n");
							exit(1);
						}
						fprintf(fp, "fsw fs%d %d(t5)\n", register_var_push,
							-(addr_vat_to_push + 1) * 4);

						if (!is_in(manager->float_used, manager->nb_float, instruction.arg2,
							   &index)) {
							fprintf(stderr, "Error: var not in float_use\n");
							exit(1);
						}
						fprintf(fp, "flw fs%d %d(t5)\n", register_var_push, -(index + 1) * 4);
						sprintf(risc_inst->register_arg2, "fs%d", register_var_push);
						manager->register_float[register_var_push] = instruction.arg2;
					}
				}
			}
			if (instruction.scope_2 == CIMPLE_ARG) {
				if (instruction.arg2 < 8)
					sprintf(risc_inst->register_arg2, "fa%d", instruction.arg2);
				else {
					sprintf(risc_inst->register_arg2, "ft2");
					fprintf(fp, "fsw ft2 %d(t6)\n", (instruction.arg2 - 8) * 4);
				}
			}
		}
		if (use_ret) {
			if (instruction.scope_ret == CIMPLE_LOCAL) {
				int index = -1;
				if (is_in(manager->register_float, 12, instruction.ret, &index)) {
					sprintf(risc_inst->register_result, "fs%d", index);
				} else {
					if (is_in(manager->register_float, 12, -1, &index)) {
						sprintf(risc_inst->register_result, "fs%d", index);
						manager->register_float[index] = instruction.ret;
					} else {
						int register_var_push = 0;
						int var_to_push = var_less_used(manager, 1, &register_var_push);
						int addr_vat_to_push = 0;
						if (!is_in(manager->float_used, manager->nb_float, var_to_push,
							   &addr_vat_to_push)) {
							fprintf(stderr, "Error: var not in float_use\n");
							exit(1);
						}
						fprintf(fp, "fsw fs%d %d(t5)\n", register_var_push,
							-(addr_vat_to_push + 1) * 4);

						if (!is_in(manager->float_used, manager->nb_float, instruction.ret,
							   &index)) {
							fprintf(stderr, "Error: var not in float_use\n");
							exit(1);
						}
						fprintf(fp, "flw fs%d %d(t5)\n", register_var_push, -(index + 1) * 4);
						sprintf(risc_inst->register_result, "fs%d", register_var_push);
						manager->register_float[register_var_push] = instruction.ret;
					}
				}
			}
			if (instruction.scope_ret == CIMPLE_ARG) {
				if (instruction.ret < 8)
					sprintf(risc_inst->register_result, "fa%d", instruction.ret);
				else {
					sprintf(risc_inst->register_result, "ft3");
					fprintf(fp, "fsw ft3 %d(t6)\n", (instruction.ret - 8) * 4);
					restore = 1;
				}
			}
		}
	} else {
		if (use_arg1) {
			if (instruction.scope_1 == CIMPLE_LOCAL) {
				int index = -1;
				if (is_in(manager->register_int, 12, instruction.arg1, &index)) {
					sprintf(risc_inst->register_arg1, "s%d", index);
				} else {
					if (is_in(manager->register_int, 12, -1, &index)) {
						sprintf(risc_inst->register_arg1, "s%d", index);
						manager->register_int[index] = instruction.arg1;
					} else {
						int register_var_push = 0;
						int var_to_push = var_less_used(manager, 0, &register_var_push);
						int addr_vat_to_push = 0;
						if (!is_in(manager->int_used, manager->nb_int, var_to_push,
							   &addr_vat_to_push)) {
							fprintf(stderr, "Error: var not in int_used\n");
							exit(1);
						}
						fprintf(fp, "sw s%d %d(t6)\n", register_var_push,
							-(addr_vat_to_push + 1) * 4);

						if (!is_in(manager->int_used, manager->nb_int, instruction.arg1,
							   &index)) {
							fprintf(stderr, "Error: var not in int_used\n");
							exit(1);
						}
						fprintf(fp, "lw s%d %d(t6)\n", register_var_push, -(index + 1) * 4);
						sprintf(risc_inst->register_arg1, "s%d", register_var_push);
						manager->register_int[register_var_push] = instruction.arg1;
					}
				}
			}
			if (instruction.scope_1 == CIMPLE_TEXT) {
				sprintf(risc_inst->register_arg1, "t2");
				fprintf(fp, "la t2 decl_%d\n", instruction.arg1);
			}
			if (instruction.scope_1 == CIMPLE_ARG) {
				if (instruction.arg1 < 8)
					sprintf(risc_inst->register_arg1, "a%d", instruction.arg1);
				else
					sprintf(risc_inst->register_arg1, "t2");
				fprintf(fp, "sw t2 %d(t6)\n", (instruction.arg1 - 8) * 4);
			}
		}
		if (use_arg2) {
			if (instruction.scope_2 == CIMPLE_LOCAL) {
				int index = -1;
				if (is_in(manager->register_int, 12, instruction.arg2, &index)) {
					sprintf(risc_inst->register_arg2, "s%d", index);
				} else {
					if (is_in(manager->register_int, 12, -1, &index)) {
						sprintf(risc_inst->register_arg2, "s%d", index);
						manager->register_int[index] = instruction.arg2;
					} else {
						int register_var_push = 0;
						int var_to_push = var_less_used(manager, 0, &register_var_push);
						int addr_vat_to_push = 0;
						if (!is_in(manager->int_used, manager->nb_int, var_to_push,
							   &addr_vat_to_push)) {
							fprintf(stderr, "Error: var not in int_used\n");
							exit(1);
						}
						fprintf(fp, "sw s%d %d(t6)\n", register_var_push,
							-(addr_vat_to_push + 1) * 4);

						if (!is_in(manager->int_used, manager->nb_int, instruction.arg2,
							   &index)) {
							fprintf(stderr, "Error: var not in int_used\n");
							exit(1);
						}
						fprintf(fp, "lw s%d %d(t6)\n", register_var_push, -(index + 1) * 4);
						sprintf(risc_inst->register_arg2, "s%d", register_var_push);
						manager->register_int[register_var_push] = instruction.arg2;
					}
				}
			}
			if (instruction.scope_2 == CIMPLE_TEXT) {
				sprintf(risc_inst->register_arg2, "t3");
				fprintf(fp, "la t3 decl_%d\n", instruction.arg2);
			}
			if (instruction.scope_2 == CIMPLE_ARG) {
				if (instruction.arg2 < 8)
					sprintf(risc_inst->register_arg2, "a%d", instruction.arg2);
				else
					sprintf(risc_inst->register_arg2, "t3");
				fprintf(fp, "sw t3 %d(t6)\n", (instruction.arg2 - 8) * 4);
			}
		}
		if (use_ret) {
			if (instruction.scope_ret == CIMPLE_LOCAL) {
				int index = -1;
				if (is_in(manager->register_int, 12, instruction.ret, &index)) {
					sprintf(risc_inst->register_result, "s%d", index);
				} else {
					if (is_in(manager->register_int, 12, -1, &index)) {
						sprintf(risc_inst->register_result, "s%d", index);
						manager->register_int[index] = instruction.ret;
					} else {
						int register_var_push = 0;
						int var_to_push = var_less_used(manager, 0, &register_var_push);
						int addr_vat_to_push = 0;
						if (!is_in(manager->int_used, manager->nb_int, var_to_push,
							   &addr_vat_to_push)) {
							fprintf(stderr, "Error: var not in int_used\n");
							exit(1);
						}
						fprintf(fp, "sw s%d %d(t6)\n", register_var_push,
							-(addr_vat_to_push + 1) * 4);

						if (!is_in(manager->int_used, manager->nb_int, instruction.ret,
							   &index)) {
							fprintf(stderr, "Error: var not in int_used\n");
							exit(1);
						}
						fprintf(fp, "lw s%d %d(t6)\n", register_var_push, -(index + 1) * 4);
						sprintf(risc_inst->register_result, "s%d", register_var_push);
						manager->register_int[register_var_push] = instruction.ret;
					}
				}
			}
			if (instruction.scope_ret == CIMPLE_TEXT) {
				fprintf(stderr, "Error: decl in ret\n");
				exit(1);
			}
			if (instruction.scope_ret == CIMPLE_ARG) {
				if (instruction.ret < 8)
					sprintf(risc_inst->register_result, "a%d", instruction.ret);
				else
					sprintf(risc_inst->register_result, "t4");
				fprintf(fp, "sw t4 %d(t6)\n", (instruction.ret - 8) * 4);
				restore = 1;
			}
		}
	}
	return restore;
}

void restore_args(struct cimple_instr instruction, FILE *fp)
{
	if (instruction.is_float) {
		fprintf(fp, "flw ft3 %d(t6)\n", (instruction.arg1 - 8) * 4);
	} else {
		fprintf(fp, "lw t4 %d(t6)\n", (instruction.arg1 - 8) * 4);
	}
}

int is_first_param(register_manager *manager)
{
	struct cimple_function *func = manager->current_func;
	if (manager->current_inst_index == 0)
		return 1;
	if (func->instrs[manager->current_inst_index - 1].op != OP_PARAM)
		return 1;
	return 0;
}
void risc_assign(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 1, 0, 1, manager, fp);
	if (instruction.scope_1 == CIMPLE_CONST) {
		if (instruction.is_float) {
			fprintf(fp, "li t0 %x\n", instruction.arg1);
			fprintf(fp, "fmv.s.x %s t0\n", risc_inst.register_result);
		} else
			fprintf(fp, "li %s %d\n", risc_inst.register_result, instruction.arg1);
	} else {
		if (instruction.is_float) {
			fprintf(fp, "fmv.s %s %s\n", risc_inst.register_result, risc_inst.register_arg1);
		} else
			fprintf(fp, "mv %s %s\n", risc_inst.register_result, risc_inst.register_arg1);
	}
}

void exchange_args_const(struct cimple_instr *instruction, risc_instruction *risc_inst)
{
	if (instruction->scope_1 == CIMPLE_CONST && instruction->scope_2 != CIMPLE_CONST) {
		int tmp = instruction->arg1;
		enum cimple_scope tmp_scope = instruction->scope_1;
		instruction->arg1 = instruction->arg2;
		instruction->arg2 = tmp;
		instruction->scope_1 = instruction->scope_2;
		instruction->scope_2 = tmp_scope;
		strcpy(risc_inst->register_arg1, risc_inst->register_arg2);
	}
}
void risc_add(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	if (instruction.scope_2 == CIMPLE_CONST && instruction.scope_1 == CIMPLE_CONST) {
		if (instruction.is_float) {
			instruction.farg1 = instruction.farg1 + instruction.farg2;
		} else {
			instruction.arg1 = instruction.arg1 + instruction.arg2;
		}
		risc_assign(instruction, fp, manager);
		return;
	}
	manage_register(instruction, &risc_inst, 1, 1, 1, manager, fp);

	exchange_args_const(&instruction, &risc_inst);
	if (instruction.scope_2 == CIMPLE_CONST) {
		if (instruction.is_float) {
			fprintf(fp, "li t0 %x\n", instruction.arg2);
			fprintf(fp, "fmv.s.x ft0 t0\n");
			fprintf(fp, "fadd.s %s %s ft0\n", risc_inst.register_result, risc_inst.register_arg1);
		} else
			fprintf(fp, "addi %s %s %d\n", risc_inst.register_result, risc_inst.register_arg1,
				instruction.arg2);
	} else {
		if (instruction.is_float) {
			fprintf(fp, "fadd.s %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
				risc_inst.register_arg2);
		} else
			fprintf(fp, "add %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
				risc_inst.register_arg2);
	}
}

void risc_sub(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	if (instruction.scope_2 == CIMPLE_CONST && instruction.scope_1 == CIMPLE_CONST) {
		if (instruction.is_float) {
			instruction.farg1 = instruction.farg1 - instruction.farg2;
		} else {
			instruction.arg1 = instruction.arg1 - instruction.arg2;
		}
		risc_assign(instruction, fp, manager);
		return;
	}
	manage_register(instruction, &risc_inst, 1, 1, 1, manager, fp);
	exchange_args_const(&instruction, &risc_inst);

	if (instruction.scope_2 == CIMPLE_CONST) {
		if (instruction.is_float) {
			// à traduire en hexa
			fprintf(fp, "li t0 %x\n", *(uint32_t *)&instruction.arg2);
			fprintf(fp, "fmv.s.x ft0 t0\n");
			fprintf(fp, "fsub.s %s %s ft0\n", risc_inst.register_result, risc_inst.register_arg1);
		} else
			fprintf(fp, "addi %s %s %d\n", risc_inst.register_result, risc_inst.register_arg1,
				-instruction.arg2);
	} else {
		if (instruction.is_float) {
			fprintf(fp, "fsub.s %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
				risc_inst.register_arg2);
		} else
			fprintf(fp, "sub %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
				risc_inst.register_arg2);
	}
}

void risc_mul(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	if (instruction.scope_2 == CIMPLE_CONST && instruction.scope_1 == CIMPLE_CONST) {
		if (instruction.is_float) {
			instruction.farg1 = instruction.farg1 * instruction.farg2;
		} else {
			instruction.arg1 = instruction.arg1 * instruction.arg2;
		}
		risc_assign(instruction, fp, manager);
		return;
	}
	manage_register(instruction, &risc_inst, 1, 1, 1, manager, fp);
	exchange_args_const(&instruction, &risc_inst);
	if (instruction.scope_2 == CIMPLE_CONST) {
		if (instruction.is_float) {
			fprintf(fp, "li t0 %x\n", instruction.arg2);
			fprintf(fp, "fmv.s.x ft0 t0\n");
			fprintf(fp, "fmul.s %s %s ft0\n", risc_inst.register_result, risc_inst.register_arg1);
		} else {
			fprintf(fp, "li t0 %d\n", instruction.arg2);
			fprintf(fp, "mul %s %s t0\n", risc_inst.register_result, risc_inst.register_arg1);
		}

	} else {
		if (instruction.is_float) {
			fprintf(fp, "fmul.s %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
				risc_inst.register_arg2);
		} else
			fprintf(fp, "mul %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
				risc_inst.register_arg2);
	}
}
// la division par zéro n'est pas géré par nous (renvoie 0xffffffff)
void risc_div(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	if (instruction.scope_2 == CIMPLE_CONST && instruction.scope_1 == CIMPLE_CONST) {
		if (instruction.is_float) {
			instruction.farg1 = instruction.farg1 / instruction.farg2;
		} else {
			instruction.arg1 = instruction.arg1 / instruction.arg2;
		}
		risc_assign(instruction, fp, manager);
		return;
	}

	manage_register(instruction, &risc_inst, 1, 1, 1, manager, fp);
	if (instruction.scope_2 == CIMPLE_CONST) {
		if (instruction.is_float) {
			fprintf(fp, "li t0 %x\n", instruction.arg2);
			fprintf(fp, "fmv.s.x ft0 t0\n");
			fprintf(fp, "fdiv.s %s %s ft0\n", risc_inst.register_result, risc_inst.register_arg1);
		} else {
			fprintf(fp, "li t0 %d\n", instruction.arg2);
			fprintf(fp, "div %s %s t0\n", risc_inst.register_result, risc_inst.register_arg1);
		}
		return;
	}
	if (instruction.scope_1 == CIMPLE_CONST) {
		if (instruction.is_float) {
			fprintf(fp, "li t0 %x\n", instruction.arg1);
			fprintf(fp, "fmv.s.x ft0 t0\n");
			fprintf(fp, "fdiv.s %s ft0 %s\n", risc_inst.register_result, risc_inst.register_arg2);
		} else {
			fprintf(fp, "li t0 %d\n", instruction.arg1);
			fprintf(fp, "div %s t0 %s\n", risc_inst.register_result, risc_inst.register_arg2);
		}
		return;
	}
	if (instruction.is_float) {
		fprintf(fp, "fdiv.s %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
			risc_inst.register_arg2);
	} else
		fprintf(fp, "div %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
			risc_inst.register_arg2);
}

void risc_mod(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	if (instruction.is_float) {
		fprintf(stderr, "Error: mod on float\n");
		exit(1);
	}
	if (instruction.scope_2 == CIMPLE_CONST && instruction.scope_1 == CIMPLE_CONST) {
		instruction.arg1 = instruction.arg1 % instruction.arg2;
		risc_assign(instruction, fp, manager);
		return;
	}
	manage_register(instruction, &risc_inst, 1, 1, 1, manager, fp);
	if (instruction.scope_2 == CIMPLE_CONST) {
		fprintf(fp, "li t0 %d\n", instruction.arg2);
		fprintf(fp, "rem %s %s t0\n", risc_inst.register_result, risc_inst.register_arg1);
		return;
	}
	if (instruction.scope_1 == CIMPLE_CONST) {
		fprintf(fp, "li t0 %d\n", instruction.arg1);
		fprintf(fp, "rem %s t0 %s\n", risc_inst.register_result, risc_inst.register_arg2);
		return;
	}
	fprintf(fp, "rem %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1, risc_inst.register_arg2);
}

void risc_neg(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	if (instruction.scope_1 == CIMPLE_CONST) {
		if (instruction.is_float) {
			instruction.farg1 = -instruction.farg1;
		} else {
			instruction.arg1 = -instruction.arg1;
		}
		risc_assign(instruction, fp, manager);
		return;
	}
	manage_register(instruction, &risc_inst, 1, 0, 1, manager, fp);
	exchange_args_const(&instruction, &risc_inst);

	if (instruction.is_float) {
		fprintf(fp, "fneg.s %s %s\n", risc_inst.register_result, risc_inst.register_arg1);
	} else
		fprintf(fp, "neg %s %s\n", risc_inst.register_result, risc_inst.register_arg1);
}
void risc_and(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	if (instruction.is_float) {
		fprintf(stderr, "Error: and on float\n");
		exit(1);
	}
	if (instruction.scope_1 == CIMPLE_CONST && instruction.scope_2 == CIMPLE_CONST) {
		instruction.arg1 = instruction.arg1 & instruction.arg2;
		risc_assign(instruction, fp, manager);
		return;
	}
	manage_register(instruction, &risc_inst, 1, 1, 1, manager, fp);
	exchange_args_const(&instruction, &risc_inst);

	if (instruction.scope_2 == CIMPLE_CONST) {
		fprintf(fp, "andi %s %s %d\n", risc_inst.register_result, risc_inst.register_arg1, instruction.arg2);
	} else {
		fprintf(fp, "and %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
			risc_inst.register_arg2);
	}
}

void risc_or(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	if (instruction.is_float) {
		fprintf(stderr, "Error: or on float\n");
		exit(1);
	}
	if (instruction.scope_1 == CIMPLE_CONST && instruction.scope_2 == CIMPLE_CONST) {
		instruction.arg1 = instruction.arg1 | instruction.arg2;
		risc_assign(instruction, fp, manager);
		return;
	}
	manage_register(instruction, &risc_inst, 1, 1, 1, manager, fp);
	exchange_args_const(&instruction, &risc_inst);

	if (instruction.scope_2 == CIMPLE_CONST) {
		fprintf(fp, "ori %s %s %d\n", risc_inst.register_result, risc_inst.register_arg1, instruction.arg2);
	} else {
		fprintf(fp, "or %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
			risc_inst.register_arg2);
	}
}

void risc_not(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	if (instruction.is_float) {
		fprintf(stderr, "Error: not on float\n");
		exit(1);
	}
	if (instruction.scope_1 == CIMPLE_CONST) {
		instruction.arg1 = ~instruction.arg1;
		risc_assign(instruction, fp, manager);
		return;
	}
	manage_register(instruction, &risc_inst, 1, 0, 1, manager, fp);

	fprintf(fp, "not %s %s\n", risc_inst.register_result, risc_inst.register_arg1);
}

void risc_xor(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	if (instruction.is_float) {
		fprintf(stderr, "Error: xor on float\n");
		exit(1);
	}
	if (instruction.scope_1 == CIMPLE_CONST && instruction.scope_2 == CIMPLE_CONST) {
		instruction.arg1 = instruction.arg1 ^ instruction.arg2;
		risc_assign(instruction, fp, manager);
		return;
	}
	manage_register(instruction, &risc_inst, 1, 1, 1, manager, fp);
	exchange_args_const(&instruction, &risc_inst);

	if (instruction.scope_2 == CIMPLE_CONST) {
		fprintf(fp, "xori %s %s %d\n", risc_inst.register_result, risc_inst.register_arg1, instruction.arg2);
	} else {
		fprintf(fp, "xor %s %s %s\n", risc_inst.register_result, risc_inst.register_arg1,
			risc_inst.register_arg2);
	}
}

void risc_goto(struct cimple_instr instruction, FILE *fp)
{
	fprintf(fp, "j labe_%d\n", instruction.ret);
}

// place un entier dans un registre temporaire pour effectuer les opérations
void temp_register(struct cimple_instr instruction, risc_instruction *risc_inst, FILE *fp)
{
	if (instruction.is_float) {
		if (instruction.scope_1 == CIMPLE_CONST) {
			if (instruction.arg1 == 0)
				strcpy(risc_inst->register_arg1, "zero");
			else {
				fprintf(fp, "li t0 %x\n", instruction.arg1);
				fprintf(fp, "fmv.s.x ft0 t0\n");
				strcpy(risc_inst->register_arg1, "ft0");
			}
		}
		if (instruction.scope_2 == CIMPLE_CONST) {
			if (instruction.arg2 == 0)
				strcpy(risc_inst->register_arg2, "zero");
			else {
				fprintf(fp, "li t1 %x\n", instruction.arg2);
				fprintf(fp, "fmv.s.x ft1 t1\n");
				strcpy(risc_inst->register_arg2, "ft1");
			}
		}

	} else {
		if (instruction.scope_1 == CIMPLE_CONST) {
			if (instruction.arg1 == 0)
				strcpy(risc_inst->register_arg1, "zero");
			else {
				fprintf(fp, "li t0 %d\n", instruction.arg1);
				strcpy(risc_inst->register_arg1, "t0");
			}
		}
		if (instruction.scope_2 == CIMPLE_CONST) {
			if (instruction.arg2 == 0)
				strcpy(risc_inst->register_arg2, "zero");
			else {
				fprintf(fp, "li t1 %d\n", instruction.arg2);
				strcpy(risc_inst->register_arg2, "t1");
			}
		}
	}
}

void rics_greater(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 1, 1, 0, manager, fp);
	temp_register(instruction, &risc_inst, fp);
	printf("blt %s %s label_%d\n", risc_inst.register_arg2, risc_inst.register_arg1, instruction.uid);
}

void risc_less(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 1, 1, 0, manager, fp);
	temp_register(instruction, &risc_inst, fp);
	printf("blt %s %s label_%d\n", risc_inst.register_arg1, risc_inst.register_arg2, instruction.uid);
}

void risc_greater_eq(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 1, 1, 0, manager, fp);
	temp_register(instruction, &risc_inst, fp);
	printf("bge %s %s label_%d\n", risc_inst.register_arg1, risc_inst.register_arg2, instruction.uid);
}

void risc_less_eq(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 1, 1, 0, manager, fp);
	temp_register(instruction, &risc_inst, fp);
	printf("bge %s %s label_%d\n", risc_inst.register_arg2, risc_inst.register_arg1, instruction.uid);
}

void risc_eq(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 1, 1, 0, manager, fp);
	temp_register(instruction, &risc_inst, fp);
	printf("beq %s %s label_%d\n", risc_inst.register_arg1, risc_inst.register_arg2, instruction.uid);
}

void risc_not_eq(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 1, 1, 0, manager, fp);
	temp_register(instruction, &risc_inst, fp);
	printf("bne %s %s label_%d\n", risc_inst.register_arg1, risc_inst.register_arg2, instruction.uid);
}

void risk_convert_to_int(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	if (instruction.scope_1 == CIMPLE_CONST) {
		manage_register(instruction, &risc_inst, 1, 0, 1, manager, fp);
		fprintf(fp, "li %s %d\n", risc_inst.register_result, (int)instruction.farg1);
	} else {
		struct cimple_instr instr_float;
		risc_instruction risc_inst_temp;
		instr_float.op = OP_CONVERT_TO_INT;
		instr_float.arg1 = instruction.arg1;
		instr_float.scope_1 = instruction.scope_1;
		instr_float.is_float = 1;
		manage_register(instr_float, &risc_inst_temp, 1, 0, 0, manager, fp);
		manage_register(instruction, &risc_inst, 0, 0, 1, manager, fp);
		fprintf(fp, "fcvt.w.s %s %s\n", risc_inst_temp.register_result, risc_inst_temp.register_arg1);
	}
}

void risk_convert_to_float(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	if (instruction.scope_1 == CIMPLE_CONST) {
		manage_register(instruction, &risc_inst, 1, 0, 1, manager, fp);
		fprintf(fp, "li %s %d\n", risc_inst.register_result, (int)instruction.farg1);
	} else {
		struct cimple_instr instr_float;
		risc_instruction risc_inst_temp;
		instr_float.op = OP_CONVERT_TO_FLOAT;
		instr_float.arg1 = instruction.arg1;
		instr_float.scope_1 = instruction.scope_1;
		instr_float.is_float = 1;
		manage_register(instr_float, &risc_inst_temp, 0, 0, 1, manager, fp);
		manage_register(instruction, &risc_inst, 1, 0, 0, manager, fp);
		fprintf(fp, "fcvt.s.w %s %s\n", risc_inst_temp.register_result, risc_inst.register_arg1);
	}
}

void risk_convert_bool(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 1, 0, 1, manager, fp);
	if (instruction.scope_1 == CIMPLE_CONST) {
		if (instruction.arg1 == 0)
			fprintf(fp, "li %s 0\n", risc_inst.register_result);
		else
			fprintf(fp, "li %s 1\n", risc_inst.register_result);
	} else {
		fprintf(fp, "snez %s %s\n", risc_inst.register_result, risc_inst.register_arg1);
	}
}
int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

void store_register_s()
{
}

void store_register_for_call(FILE *fp, struct cimple_instr instruction, uint32_t is_syscall)
{
	fprintf(fp, "sw ra -4(sp)\n");
	fprintf(fp, "sw t5 -8(sp)\n");
	fprintf(fp, "sw t6 -12(sp)\n");
	fprintf(fp, "addi sp sp -12\n");
	// on sauvegarde les registres des arguments qui vont être utilisés par la suite
	int max_arg = 8;
	if (is_syscall)
		max_arg = 7;
	int arg_to_store_count = min(instruction.arg2 + 1, max_arg);
	if (instruction.op == OP_CALL || instruction.op == OP_SYSCALL) {
		arg_to_store_count = min(instruction.arg2, max_arg);
	}
	for (int i = 0; i < arg_to_store_count; i++) {
		fprintf(fp, "sw a%d -%d(sp)\n", i, (i + 1) * 4);
	}
	fprintf(fp, "addi sp sp -%d\n", arg_to_store_count * 4);
	// on sauvegarde a7 si c'est un syscall
	if (is_syscall) {
		fprintf(fp, "sw a7 -4(sp)\n");
		fprintf(fp, "addi sp sp -4\n");
	}
}

void risc_syscall(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	if (is_first_param(manager)) {
		store_register_for_call(fp, instruction, 1);
	}

	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 0, 0, 1, manager, fp);
	fprintf(fp, "li a7 %d\n", instruction.arg1);
	fprintf(fp, "ecall\n");
	if (instruction.is_float)
		fprintf(fp, "fmv.s %s fa0\n", risc_inst.register_result);
	else
		fprintf(fp, "mv %s a0\n", risc_inst.register_result);
	// on rétablit les arguments et ra, t5, t6
	// a7
	fprintf(fp, "lw a7 0(sp)\n");
	fprintf(fp, "addi sp sp 4\n");
	// arguments
	if (instruction.arg2 > 7)
		fprintf(fp, "addi sp sp %d\n", (instruction.arg2 - 7) * 4);
	int nb_arg = min(instruction.arg2, 7);
	for (int i = 0; i < nb_arg; i++)
		fprintf(fp, "lw a%d %d(sp)\n", (nb_arg - 1) - i, (i)*4);
	fprintf(fp, "addi sp sp %d\n", nb_arg * 4);
	fprintf(fp, "lw t6 0(sp)\n");
	fprintf(fp, "lw t5 4(sp)\n");
	fprintf(fp, "lw ra 8(sp)\n");
	fprintf(fp, "addi sp sp 12\n");
}

void risc_call(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	// cas ou il n'y a pas d'arguments
	if (is_first_param(manager)) {
		store_register_for_call(fp, instruction, 0);
	}
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 0, 0, 1, manager, fp);
	fprintf(fp, "jal func_%d\n", instruction.arg1);
	if (instruction.is_float)
		fprintf(fp, "fmv.s %s fa0\n", risc_inst.register_result);
	else
		fprintf(fp, "mv %s a0\n", risc_inst.register_result);
	// on rétablit les arguments et ra, t5, t6
	if (instruction.arg2 > 8)
		fprintf(fp, "addi sp sp %d\n", (instruction.arg2 - 8) * 4);
	int nb_arg = min(instruction.arg2, 8);
	for (int i = 0; i < nb_arg; i++)
		fprintf(fp, "lw a%d %d(sp)\n", (nb_arg - 1) - i, (i)*4);
	fprintf(fp, "addi sp sp %d\n", nb_arg * 4);
	fprintf(fp, "lw t6 0(sp)\n");
	fprintf(fp, "lw t5 4(sp)\n");
	fprintf(fp, "lw ra 8(sp)\n");
	fprintf(fp, "addi sp sp 12\n");
}

void risc_param(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	// on sauvegarde les registres utilisés en tant que pointeurs
	if (is_first_param(manager)) {
		store_register_for_call(fp, instruction, instruction.ret);
	}
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 1, 0, 0, manager, fp);
	uint32_t max_arg = 8;
	if (instruction.ret == 1)
		max_arg = 7; // cas du syscall car on met le numéro de la fonction dans a7
	if (instruction.scope_1 == CIMPLE_CONST) {
		if (instruction.is_float) {
			fprintf(fp, "li t0 %x\n", instruction.arg1);
			if (instruction.arg2 < max_arg)
				fprintf(fp, "fmv.s.x fa%s t0\n", risc_inst.register_arg2);
			// les argument doivent être donnés dans l'ordre décroissant
			else {
				fprintf(fp, "sw t0 -4(sp)\n");
				fprintf(fp, "addi sp sp -4\n");
			}
		} else if (instruction.arg2 < 8)
			fprintf(fp, "li a%s %d\n", risc_inst.register_arg2, instruction.arg1);
		else {
			fprintf(fp, "li t0 %d\n", instruction.arg1);
			fprintf(fp, "sw t0 -4(sp)\n");
			fprintf(fp, "addi sp sp -4\n");
		}
	} else {
		if (instruction.is_float) {
			if (instruction.arg2 < max_arg)
				fprintf(fp, "fmv.s fa%s %s\n", risc_inst.register_arg2, risc_inst.register_arg1);
			else {
				fprintf(fp, "fsw %s -4(sp)\n", risc_inst.register_arg1);
				fprintf(fp, "addi sp sp -4\n");
			}
		} else if (instruction.arg2 < 8)
			fprintf(fp, "mv a%s %s\n", risc_inst.register_arg2, risc_inst.register_arg1);
		else {
			fprintf(fp, "sw %s -4(sp)\n", risc_inst.register_arg1);
			fprintf(fp, "addi sp sp -4\n");
		}
	}
}

void risc_return(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 1, 0, 0, manager, fp);
	if (instruction.scope_1 == CIMPLE_CONST) {
		if (instruction.is_float) {
			fprintf(fp, "li t0 %x\n", instruction.arg1);
			fprintf(fp, "fmv.s.x fa0 t0\n");
		} else
			fprintf(fp, "li a0 %d\n", instruction.arg1);
	} else {
		if (instruction.is_float) {
			fprintf(fp, "fmv.s fa0 %s\n", risc_inst.register_arg1);
		} else
			fprintf(fp, "mv a0 %s\n", risc_inst.register_arg1);
	}
	// on rétablit les registres s
	fprintf(fp, "addi sp t5 -%d\n", manager->nb_float * 4);
	for (int i = 0; i < 12; i++)
		fprintf(fp, "lw s%d -%d(sp)\n", i, (i + 1) * 4);
	for (int i = 0; i < 12; i++)
		fprintf(fp, "flw fs%d -%d(sp)\n", i, (i + 13) * 4);
	fprintf(fp, "mv sp t6\n");
	fprintf(fp, "jr ra\n");
}

void risc_ld(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 1, 0, 1, manager, fp);
	if (instruction.is_float) {
		fprintf(fp, "flw %s 0(%s)\n", risc_inst.register_result, risc_inst.register_arg1);
	} else
		fprintf(fp, "lw %s 0(%s)\n", risc_inst.register_result, risc_inst.register_arg1);
}

void risc_st(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 1, 1, 0, manager, fp);
	if (instruction.is_float) {
		fprintf(fp, "fsw %s 0(%s)\n", risc_inst.register_arg2, risc_inst.register_arg1);
	} else
		fprintf(fp, "sw %s 0(%s)\n", risc_inst.register_arg2, risc_inst.register_arg1);
}

void risc_alloc(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 0, 0, 1, manager, fp);
	if (instruction.scope_1 == CIMPLE_CONST) {
		fprintf(fp, "addi sp sp -%d\n", instruction.arg1); // à voir avec ethan si *4 ou pas
	} else {
		fprintf(fp, "sub sp sp %s\n", risc_inst.register_arg1); // de même
	}
	fprintf(fp, "mv %s sp\n", risc_inst.register_result);
}

void risc_free(struct cimple_instr instruction, FILE *fp, register_manager *manager)
{
	risc_instruction risc_inst;
	manage_register(instruction, &risc_inst, 0, 0, 1, manager, fp);
	if (instruction.scope_1 == CIMPLE_CONST) {
		fprintf(fp, "addi sp sp %d\n", instruction.arg1); // à voir avec ethan si *4 ou pas
	} else {
		fprintf(fp, "add sp sp %s\n", risc_inst.register_arg1); // de même
	}
}

int is_goto(struct cimple_instr instruction)
{
	if (instruction.op == OP_GOTO || instruction.op == OP_GREATER || instruction.op == OP_LESS ||
	    instruction.op == OP_GREATER_EQ || instruction.op == OP_LESS_EQ || instruction.op == OP_EQ_EQ ||
	    instruction.op == OP_NOT_EQ || instruction.op == OP_NOT) {
		return 1;
	}
	return 0;
}

int error_malloc(void *ptr)
{
	if (ptr == NULL) {
		fprintf(stderr, "Error malloc\n");
		exit(1);
	}

	return 0;
}

// à free
void label_used(struct cimple_function cimple_func, int *label_use, int *nb_label_use, int *nb_int, int *nb_float,
		int *int_used, int *float_used)
{
	int_used = malloc(1000 * sizeof(int));
	error_malloc(int_used);
	int alloc_int = 1000;
	nb_int = 0;
	float_used = malloc(1000 * sizeof(int));
	error_malloc(float_used);
	int alloc_float = 1000;
	nb_float = 0;

	nb_label_use = 0;
	label_use = malloc(1000 * sizeof(int));
	error_malloc(label_use);
	int alloc_label = 1000;

	for (int i = 0; i < (int)cimple_func.size; i++) {
		struct cimple_instr instruction = cimple_func.instrs[i];
		// label used
		if (is_goto(instruction)) {
			int goto_label = instruction.ret;
			if (!is_in(label_use, cimple_func.size, goto_label, NULL)) {
				if (*nb_label_use > alloc_label) {
					label_use = realloc(label_use, (*nb_label_use + 1000) * sizeof(int));
					error_malloc(label_use);
					alloc_label += 1000;
				}
				label_use[*nb_label_use] = goto_label;
				nb_label_use++;
			}
		}

		// number of variable
		if (instruction.scope_ret != CIMPLE_UID) {
			if (instruction.is_float) {
				if (is_in(float_used, *nb_float, instruction.ret, NULL)) {
					if (*nb_float > alloc_float) {
						float_used = realloc(float_used, (*nb_float + 1000) * sizeof(int));
						error_malloc(float_used);
						alloc_float += 1000;
					}
					float_used[*nb_float] = instruction.ret;
					nb_float++;
				}
			} else {
				if (is_in(int_used, *nb_int, instruction.ret, NULL)) {
					if (*nb_int > alloc_int) {
						int_used = realloc(int_used, (*nb_int + 1000) * sizeof(int));
						error_malloc(int_used);
						alloc_int += 1000;
					}
					int_used[*nb_int] = instruction.ret;
					nb_int++;
				}
			}
		}
	}
}

int process_three_address(struct cimple_program program, FILE *fp)
{
	fprintf(fp, ".data\n");
	for (int i = 0; i < (int)program.decl_size; i++) {
		struct cimple_string string = program.decls[i];
		fprintf(fp, "decl_%d : \n", string.uid);
		fprintf(fp, ".asciiz \"%s\"\n", string.str);
	}
	fprintf(fp, ".text\n");

	// on crée un foncion qui va appeler le main
	fprintf(fp, "start_end :\n");
	// chargement de argc et argv non géré donc sont mis à 0
	fprintf(fp, "li a0 0\n");
	fprintf(fp, "li a1 0\n");
	fprintf(fp, "jal func_0\n"); // on appelle le main
	fprintf(fp, "li a7 10\n"); // on quitte le programme
	fprintf(fp, "ecall\n");

	for (int j = 0; j < (int)program.func_size; j++) {
		struct cimple_function func = program.funcs[j];
		int *label_use = NULL;
		int *int_used = NULL;
		int *float_used = NULL;
		int var_int = 0;
		int var_float = 0;
		int nb_label = 0;
		label_used(func, label_use, &nb_label, &var_float, &var_int, int_used, float_used);

		fprintf(fp, "func_%d :\n", func.uid);
		// allocation des variables
		fprintf(fp, "mv t6 sp\n");
		fprintf(fp, "addi sp sp %d\n", -((var_int)*4));
		fprintf(fp, "mv t5 sp\n");
		fprintf(fp, "addi sp sp %d\n", -((var_float)*4));
		// on push les anciens registres s
		for (int i = 0; i < 12; i++)
			fprintf(fp, "sw s%d -%d(sp)\n", i, (i + 1) * 4);
		for (int i = 0; i < 12; i++)
			fprintf(fp, "fsw fs%d -%d(sp)\n", i, (i + 13) * 4);
		fprintf(fp, "addi sp sp -96\n");
		// gestion des registres
		register_manager manager;
		manager.nb_int = var_int;
		manager.nb_float = var_float;
		for (int i = 0; i < 12; i++) {
			manager.register_int[i] = -1;
			manager.register_float[i] = -1;
		}
		manager.int_used = int_used;
		manager.float_used = float_used;
		manager.current_func = &func;
		manager.current_inst_index = 0;
		manager.global_manager = NULL;

		for (int i = 0; i < (int)func.size; i++) {
			struct cimple_instr instruction = func.instrs[i];
			if (is_in(label_use, func.size, i, NULL)) {
				fprintf(fp, "labe_%d :\n", i);
			}

			switch (instruction.op) {
			case OP_NULL:
				break;
			case OP_ADD:
				risc_add(instruction, fp, &manager);
				break;
			case OP_SUB:
				risc_sub(instruction, fp, &manager);
				break;
			case OP_MUL:
				risc_mul(instruction, fp, &manager);
				break;
			case OP_DIV:
				risc_div(instruction, fp, &manager);
				break;
			case OP_MOD:
				risc_mod(instruction, fp, &manager);
				break;
			case OP_NEG:
				risc_neg(instruction, fp, &manager);
				break;
			case OP_AND:
				risc_and(instruction, fp, &manager);
				break;
			case OP_OR:
				risc_or(instruction, fp, &manager);
				break;
			case OP_XOR:
				risc_xor(instruction, fp, &manager);
				break;
			case OP_ASSIGN:
				risc_assign(instruction, fp, &manager);
				break;
			case OP_GOTO:
				risc_goto(instruction, fp);
				break;
			case OP_GREATER:
				rics_greater(instruction, fp, &manager);
				break;
			case OP_LESS:
				risc_less(instruction, fp, &manager);
				break;
			case OP_GREATER_EQ:
				risc_greater_eq(instruction, fp, &manager);
				break;
			case OP_LESS_EQ:
				risc_less_eq(instruction, fp, &manager);
				break;
			case OP_EQ_EQ:
				risc_eq(instruction, fp, &manager);
				break;
			case OP_NOT_EQ:
				risc_not_eq(instruction, fp, &manager);
				break;
			case OP_NOT:
				risc_not(instruction, fp, &manager);
				break;
			case OP_CONVERT_TO_INT:
				risk_convert_to_int(instruction, fp, &manager);
				break;
			case OP_CONVERT_TO_FLOAT:
				risk_convert_to_float(instruction, fp, &manager);
				break;
			case OP_CONVERT_BOOL:
				risk_convert_bool(instruction, fp, &manager);
				break;
			case OP_SYSCALL:
				risc_syscall(instruction, fp, &manager);
				break;
			case OP_CALL:
				risc_call(instruction, fp, &manager);
				break;
			case OP_PARAM:
				risc_param(instruction, fp, &manager);
				break;
			case OP_RETURN:
				risc_return(instruction, fp, &manager);
				break;
			case OP_LD:
				risc_ld(instruction, fp, &manager);
				break;
			case OP_ST:
				risc_st(instruction, fp, &manager);
				break;
			case OP_ALLOC:
				risc_alloc(instruction, fp, &manager);
				break;
			case OP_FREE:
				risc_free(instruction, fp, &manager);
				break;
			default:
				fprintf(stderr, "Invalid operation: %d\n", instruction.op);
				return 1;
			}
			manager.current_inst_index++;
		}
		free(label_use);
		free(int_used);
		free(float_used);
	}

	return 0;
}