#import "three_address_code.h"
#import <stdio.h>


void print_3_address(three_address_instruction instruction){
        if(instruction.op != OP_NULL){
                printf("%d ", (int)instruction.op);
        }
        if (instruction.arg1 != NULL){
                printf("%s ", instruction.arg1);
        }
        if (instruction.arg2 != NULL){
                printf("%s ", instruction.arg2);
        }
        if (instruction.result != NULL){
                printf("%s ", instruction.result);
        }
        printf("\n");
}

void print_3_address_code(three_address_program three_address){
        for (int i = 0; i < three_address.size; i++){
                printf("%d: ", i);
                print_3_address(three_address.instructions[i]);
        }
}

