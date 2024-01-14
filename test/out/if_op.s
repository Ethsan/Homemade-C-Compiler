.data
decl_1 : 
.asciz "ok\n"
decl_2 : 
.asciz "error\n"
decl_3 : 
.asciz "error\n"
decl_4 : 
.asciz "ok\n"
decl_5 : 
.asciz "ok\n"
decl_6 : 
.asciz "error\n"
decl_7 : 
.asciz "ok\n"
decl_8 : 
.asciz "error\n"
decl_9 : 
.asciz "error\n"
decl_10 : 
.asciz "ok\n"
decl_11 : 
.asciz "\n"
decl_12 : 
.asciz " "
decl_13 : 
.asciz "\n"
.text
start_end :
li a0 0
li a1 0
jal func_116
li a7 93
ecall
func_116 :
mv t6 sp
addi sp sp -16
mv t5 sp
addi sp sp 0
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
li s2 1
mv s1 s2
li s2 1
mv s0 s2
mv s3 s1
mv s2 s0
snez s3 s3
snez s2 s2
and s3 s3 s2
beq s3 zero func_116_label_16
la t2 decl_1
mv s2 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s2
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_116_label_19
func_116_label_16 :
la t2 decl_2
mv s2 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s2
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_116_label_19 :
li s2 0
mv s0 s2
mv s3 s1
mv s2 s0
snez s3 s3
snez s2 s2
and s3 s3 s2
beq s3 zero func_116_label_31
la t2 decl_3
mv s2 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s2
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_116_label_34
func_116_label_31 :
la t2 decl_4
mv s2 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s2
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_116_label_34 :
li s2 1
mv s0 s2
mv s3 s1
mv s2 s0
snez s3 s3
snez s2 s2
or s3 s3 s2
beq s3 zero func_116_label_46
la t2 decl_5
mv s2 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s2
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_116_label_49
func_116_label_46 :
la t2 decl_6
mv s2 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s2
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_116_label_49 :
li s2 0
mv s0 s2
mv s3 s1
mv s2 s0
snez s3 s3
snez s2 s2
or s3 s3 s2
beq s3 zero func_116_label_61
la t2 decl_7
mv s2 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s2
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_116_label_64
func_116_label_61 :
la t2 decl_8
mv s2 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s2
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_116_label_64 :
li s2 0
mv s1 s2
mv s3 s1
mv s2 s0
snez s3 s3
snez s2 s2
or s3 s3 s2
beq s3 zero func_116_label_76
la t2 decl_9
mv s2 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s2
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_116_label_79
func_116_label_76 :
la t2 decl_10
mv s2 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s2
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_116_label_79 :
li a0 0
addi sp t5 -0
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_110 :
mv t6 sp
addi sp sp -28
mv t5 sp
addi sp sp -4
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
la t2 decl_11
mv s2 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s2
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s2 0
mv s0 s2
func_110_label_7 :
mv s2 s0
sw t2 -32(t6)
mv s4 a0
li s3 1
blt s2 s4 func_110_label_12
li s3 0
func_110_label_12 :
beq s3 zero func_110_label_45
li s2 0
mv s1 s2
func_110_label_15 :
mv s2 s1
sw t2 -28(t6)
mv s4 a1
li s3 1
blt s2 s4 func_110_label_20
li s3 0
func_110_label_20 :
beq s3 zero func_110_label_39
sw t2 -24(t6)
mv s4 a2
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s4 s4 s5
flw fs1 0(s4)
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
fmv.s fa0 fs1
jal func_3
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_12
mv s2 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s2
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
addi s3 s2 1
mv s1 s3
j func_110_label_15
func_110_label_39 :
la t2 decl_13
mv s2 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s2
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
addi s3 s2 1
mv s0 s3
j func_110_label_7
func_110_label_45 :
li a0 0
addi sp t5 -4
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_99 :
mv t6 sp
addi sp sp -32
mv t5 sp
addi sp sp -4
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
li s2 0
mv s0 s2
func_99_label_4 :
mv s2 s0
sw t2 -32(t6)
mv s3 a0
li s4 1
blt s2 s3 func_99_label_9
li s4 0
func_99_label_9 :
beq s4 zero func_99_label_50
sw t2 -20(t6)
mv s2 a3
mv s1 s2
func_99_label_12 :
mv s2 s1
sw t2 -16(t6)
mv s3 a4
li s4 1
blt s2 s3 func_99_label_17
li s4 0
func_99_label_17 :
beq s4 zero func_99_label_47
sw t2 -4(t6)
mv s3 a7
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
flw fs1 0(s3)
sw t2 -8(t6)
mv s3 a6
mv s5 s0
sw t2 -24(t6)
mv s6 a2
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
sw t2 -20(t6)
mv s6 a3
sub s5 s5 s6
sw t2 -12(t6)
mv s6 a5
sw t2 -24(t6)
mv s7 a2
mul s6 s6 s7
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
fsw fs1 0(s3)
addi s4 s2 1
mv s1 s4
j func_99_label_12
func_99_label_47 :
addi s4 s2 1
mv s0 s4
j func_99_label_4
func_99_label_50 :
li a0 0
addi sp t5 -4
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_88 :
mv t6 sp
addi sp sp -28
mv t5 sp
addi sp sp -4
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
sw t2 -20(t6)
mv s2 a3
mv s0 s2
func_88_label_4 :
mv s2 s0
sw t2 -16(t6)
mv s3 a4
li s4 1
blt s2 s3 func_88_label_9
li s4 0
func_88_label_9 :
beq s4 zero func_88_label_48
li s2 0
mv s1 s2
func_88_label_12 :
mv s2 s1
sw t2 -28(t6)
mv s3 a1
li s4 1
blt s2 s3 func_88_label_17
li s4 0
func_88_label_17 :
beq s4 zero func_88_label_45
sw t2 -4(t6)
mv s3 a7
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
flw fs1 0(s3)
sw t2 -8(t6)
mv s3 a6
mv s5 s0
sw t2 -20(t6)
mv s6 a3
sub s5 s5 s6
sw t2 -24(t6)
mv s6 a2
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
sw t2 -12(t6)
mv s6 a5
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
fsw fs1 0(s3)
addi s4 s2 1
mv s1 s4
j func_88_label_12
func_88_label_45 :
addi s4 s2 1
mv s0 s4
j func_88_label_4
func_88_label_48 :
li a0 0
addi sp t5 -4
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_81 :
mv t6 sp
addi sp sp -28
mv t5 sp
addi sp sp -4
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
li s2 0
mv s0 s2
func_81_label_4 :
mv s2 s0
sw t2 -32(t6)
mv s3 a0
li s4 1
blt s2 s3 func_81_label_9
li s4 0
func_81_label_9 :
beq s4 zero func_81_label_44
li s2 0
mv s1 s2
func_81_label_12 :
mv s2 s1
sw t2 -28(t6)
mv s3 a1
li s4 1
blt s2 s3 func_81_label_17
li s4 0
func_81_label_17 :
beq s4 zero func_81_label_41
sw t2 -20(t6)
mv s3 a3
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
flw fs1 0(s3)
sw t2 -24(t6)
mv s3 a2
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
fsw fs1 0(s3)
addi s4 s2 1
mv s1 s4
j func_81_label_12
func_81_label_41 :
addi s4 s2 1
mv s0 s4
j func_81_label_4
func_81_label_44 :
li a0 0
addi sp t5 -4
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_73 :
mv t6 sp
addi sp sp -28
mv t5 sp
addi sp sp -8
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
li s2 0
mv s0 s2
func_73_label_4 :
mv s2 s0
sw t2 -32(t6)
mv s3 a0
li s4 1
blt s2 s3 func_73_label_9
li s4 0
func_73_label_9 :
beq s4 zero func_73_label_46
li s2 0
mv s1 s2
func_73_label_12 :
mv s2 s1
sw t2 -28(t6)
mv s3 a1
li s4 1
blt s2 s3 func_73_label_17
li s4 0
func_73_label_17 :
beq s4 zero func_73_label_43
sw t2 -16(t6)
mv s3 a4
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
flw fs1 0(s3)
fsw ft1 -24(t6)
fmv.s fs0 fa2
fsub.s fs1 fs1 fs0
sw t2 -20(t6)
mv s3 a3
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
fsw fs1 0(s3)
addi s4 s2 1
mv s1 s4
j func_73_label_12
func_73_label_43 :
addi s4 s2 1
mv s0 s4
j func_73_label_4
func_73_label_46 :
li a0 0
addi sp t5 -8
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_65 :
mv t6 sp
addi sp sp -28
mv t5 sp
addi sp sp -8
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
li s2 0
mv s0 s2
func_65_label_4 :
mv s2 s0
sw t2 -32(t6)
mv s3 a0
li s4 1
blt s2 s3 func_65_label_9
li s4 0
func_65_label_9 :
beq s4 zero func_65_label_46
li s2 0
mv s1 s2
func_65_label_12 :
mv s2 s1
sw t2 -28(t6)
mv s3 a1
li s4 1
blt s2 s3 func_65_label_17
li s4 0
func_65_label_17 :
beq s4 zero func_65_label_43
sw t2 -16(t6)
mv s3 a4
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
flw fs1 0(s3)
fsw ft1 -24(t6)
fmv.s fs0 fa2
fadd.s fs1 fs1 fs0
sw t2 -20(t6)
mv s3 a3
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
fsw fs1 0(s3)
addi s4 s2 1
mv s1 s4
j func_65_label_12
func_65_label_43 :
addi s4 s2 1
mv s0 s4
j func_65_label_4
func_65_label_46 :
li a0 0
addi sp t5 -8
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_57 :
mv t6 sp
addi sp sp -28
mv t5 sp
addi sp sp -8
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
li s2 0
mv s0 s2
func_57_label_4 :
mv s2 s0
sw t2 -32(t6)
mv s3 a0
li s4 1
blt s2 s3 func_57_label_9
li s4 0
func_57_label_9 :
beq s4 zero func_57_label_46
li s2 0
mv s1 s2
func_57_label_12 :
mv s2 s1
sw t2 -28(t6)
mv s3 a1
li s4 1
blt s2 s3 func_57_label_17
li s4 0
func_57_label_17 :
beq s4 zero func_57_label_43
sw t2 -16(t6)
mv s3 a4
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
flw fs1 0(s3)
fsw ft1 -24(t6)
fmv.s fs0 fa2
fdiv.s fs1 fs1 fs0
sw t2 -20(t6)
mv s3 a3
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
fsw fs1 0(s3)
addi s4 s2 1
mv s1 s4
j func_57_label_12
func_57_label_43 :
addi s4 s2 1
mv s0 s4
j func_57_label_4
func_57_label_46 :
li a0 0
addi sp t5 -8
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_49 :
mv t6 sp
addi sp sp -28
mv t5 sp
addi sp sp -8
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
li s2 0
mv s0 s2
func_49_label_4 :
mv s2 s0
sw t2 -32(t6)
mv s3 a0
li s4 1
blt s2 s3 func_49_label_9
li s4 0
func_49_label_9 :
beq s4 zero func_49_label_46
li s2 0
mv s1 s2
func_49_label_12 :
mv s2 s1
sw t2 -28(t6)
mv s3 a1
li s4 1
blt s2 s3 func_49_label_17
li s4 0
func_49_label_17 :
beq s4 zero func_49_label_43
sw t2 -16(t6)
mv s3 a4
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
flw fs1 0(s3)
fsw ft1 -24(t6)
fmv.s fs0 fa2
fmul.s fs1 fs1 fs0
sw t2 -20(t6)
mv s3 a3
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
fsw fs1 0(s3)
addi s4 s2 1
mv s1 s4
j func_49_label_12
func_49_label_43 :
addi s4 s2 1
mv s0 s4
j func_49_label_4
func_49_label_46 :
li a0 0
addi sp t5 -8
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_38 :
mv t6 sp
addi sp sp -40
mv t5 sp
addi sp sp -12
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
li s2 0
li s3 0
mv s0 s3
func_38_label_5 :
mv s3 s0
sw t2 -32(t6)
mv s4 a0
li s5 1
blt s3 s4 func_38_label_10
li s5 0
func_38_label_10 :
beq s5 zero func_38_label_90
li s3 0
mv s1 s3
func_38_label_13 :
mv s3 s1
sw t2 -20(t6)
mv s4 a3
li s5 1
blt s3 s4 func_38_label_18
li s5 0
func_38_label_18 :
beq s5 zero func_38_label_87
li s3 0
fcvt.s.w fs0 s3
sw t2 -16(t6)
mv s4 a4
mv s6 s0
sw t2 -20(t6)
mv s7 a3
mul s6 s6 s7
mv s7 s1
add s6 s6 s7
li s7 4
mul s6 s6 s7
add s4 s4 s6
fsw fs0 0(s4)
li s3 0
mv s2 s3
func_38_label_33 :
mv s3 s2
sw t2 -28(t6)
mv s4 a1
li s5 1
blt s3 s4 func_38_label_38
li s5 0
func_38_label_38 :
beq s5 zero func_38_label_84
sw t2 -16(t6)
mv s4 a4
mv s6 s0
sw t2 -20(t6)
mv s7 a3
mul s6 s6 s7
mv s7 s1
add s6 s6 s7
li s7 4
mul s6 s6 s7
add s4 s4 s6
flw fs0 0(s4)
sw t2 -12(t6)
mv s6 a5
mv s7 s0
sw t2 -28(t6)
mv s8 a1
mul s7 s7 s8
mv s8 s2
add s7 s7 s8
li s8 4
mul s7 s7 s8
add s6 s6 s7
flw fs1 0(s6)
sw t2 -8(t6)
mv s7 a6
mv s8 s2
sw t2 -20(t6)
mv s9 a3
mul s8 s8 s9
mv s9 s1
add s8 s8 s9
li s9 4
mul s8 s8 s9
add s7 s7 s8
flw fs2 0(s7)
fdiv.s fs1 fs1 fs2
fadd.s fs0 fs0 fs1
sw t2 -16(t6)
mv s4 a4
mv s6 s0
sw t2 -20(t6)
mv s7 a3
mul s6 s6 s7
mv s7 s1
add s6 s6 s7
li s7 4
mul s6 s6 s7
add s4 s4 s6
fsw fs0 0(s4)
addi s5 s3 1
mv s2 s5
j func_38_label_33
func_38_label_84 :
addi s5 s3 1
mv s1 s5
j func_38_label_13
func_38_label_87 :
addi s5 s3 1
mv s0 s5
j func_38_label_5
func_38_label_90 :
li a0 0
addi sp t5 -12
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_27 :
mv t6 sp
addi sp sp -40
mv t5 sp
addi sp sp -12
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
li s2 0
li s3 0
mv s0 s3
func_27_label_5 :
mv s3 s0
sw t2 -32(t6)
mv s4 a0
li s5 1
blt s3 s4 func_27_label_10
li s5 0
func_27_label_10 :
beq s5 zero func_27_label_78
li s3 0
mv s1 s3
func_27_label_13 :
mv s3 s1
sw t2 -20(t6)
mv s4 a3
li s5 1
blt s3 s4 func_27_label_18
li s5 0
func_27_label_18 :
beq s5 zero func_27_label_75
li s3 0
mv s2 s3
func_27_label_21 :
mv s3 s2
sw t2 -28(t6)
mv s4 a1
li s5 1
blt s3 s4 func_27_label_26
li s5 0
func_27_label_26 :
beq s5 zero func_27_label_72
sw t2 -16(t6)
mv s4 a4
mv s6 s0
sw t2 -20(t6)
mv s7 a3
mul s6 s6 s7
mv s7 s1
add s6 s6 s7
li s7 4
mul s6 s6 s7
add s4 s4 s6
flw fs1 0(s4)
sw t2 -12(t6)
mv s6 a5
mv s7 s0
sw t2 -28(t6)
mv s8 a1
mul s7 s7 s8
mv s8 s2
add s7 s7 s8
li s8 4
mul s7 s7 s8
add s6 s6 s7
flw fs0 0(s6)
sw t2 -8(t6)
mv s7 a6
mv s8 s2
sw t2 -20(t6)
mv s9 a3
mul s8 s8 s9
mv s9 s1
add s8 s8 s9
li s9 4
mul s8 s8 s9
add s7 s7 s8
flw fs2 0(s7)
fmul.s fs0 fs0 fs2
fadd.s fs1 fs1 fs0
sw t2 -16(t6)
mv s4 a4
mv s6 s0
sw t2 -20(t6)
mv s7 a3
mul s6 s6 s7
mv s7 s1
add s6 s6 s7
li s7 4
mul s6 s6 s7
add s4 s4 s6
fsw fs1 0(s4)
addi s5 s3 1
mv s2 s5
j func_27_label_21
func_27_label_72 :
addi s5 s3 1
mv s1 s5
j func_27_label_13
func_27_label_75 :
addi s5 s3 1
mv s0 s5
j func_27_label_5
func_27_label_78 :
li a0 0
addi sp t5 -12
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_19 :
mv t6 sp
addi sp sp -32
mv t5 sp
addi sp sp -8
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
li s2 0
mv s0 s2
func_19_label_4 :
mv s2 s0
sw t2 -32(t6)
mv s3 a0
li s4 1
blt s2 s3 func_19_label_9
li s4 0
func_19_label_9 :
beq s4 zero func_19_label_55
li s2 0
mv s1 s2
func_19_label_12 :
mv s2 s1
sw t2 -28(t6)
mv s3 a1
li s4 1
blt s2 s3 func_19_label_17
li s4 0
func_19_label_17 :
beq s4 zero func_19_label_52
sw t2 -20(t6)
mv s3 a3
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
flw fs1 0(s3)
sw t2 -16(t6)
mv s5 a4
mv s6 s0
sw t2 -28(t6)
mv s7 a1
mul s6 s6 s7
mv s7 s1
add s6 s6 s7
li s7 4
mul s6 s6 s7
add s5 s5 s6
flw fs0 0(s5)
fsub.s fs1 fs1 fs0
sw t2 -24(t6)
mv s3 a2
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
fsw fs1 0(s3)
addi s4 s2 1
mv s1 s4
j func_19_label_12
func_19_label_52 :
addi s4 s2 1
mv s0 s4
j func_19_label_4
func_19_label_55 :
li a0 0
addi sp t5 -8
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_11 :
mv t6 sp
addi sp sp -32
mv t5 sp
addi sp sp -8
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
li s2 0
mv s0 s2
func_11_label_4 :
mv s2 s0
sw t2 -32(t6)
mv s3 a0
li s4 1
blt s2 s3 func_11_label_9
li s4 0
func_11_label_9 :
beq s4 zero func_11_label_55
li s2 0
mv s1 s2
func_11_label_12 :
mv s2 s1
sw t2 -28(t6)
mv s3 a1
li s4 1
blt s2 s3 func_11_label_17
li s4 0
func_11_label_17 :
beq s4 zero func_11_label_52
sw t2 -20(t6)
mv s3 a3
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
flw fs1 0(s3)
sw t2 -16(t6)
mv s5 a4
mv s6 s0
sw t2 -28(t6)
mv s7 a1
mul s6 s6 s7
mv s7 s1
add s6 s6 s7
li s7 4
mul s6 s6 s7
add s5 s5 s6
flw fs0 0(s5)
fadd.s fs1 fs1 fs0
sw t2 -24(t6)
mv s3 a2
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
fsw fs1 0(s3)
addi s4 s2 1
mv s1 s4
j func_11_label_12
func_11_label_52 :
addi s4 s2 1
mv s0 s4
j func_11_label_4
func_11_label_55 :
li a0 0
addi sp t5 -8
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_4 :
mv t6 sp
addi sp sp -28
mv t5 sp
addi sp sp -4
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
li s0 0
li s1 0
li s2 0
mv s0 s2
func_4_label_4 :
mv s2 s0
sw t2 -32(t6)
mv s3 a0
li s4 1
blt s2 s3 func_4_label_9
li s4 0
func_4_label_9 :
beq s4 zero func_4_label_44
li s2 0
mv s1 s2
func_4_label_12 :
mv s2 s1
sw t2 -28(t6)
mv s3 a1
li s4 1
blt s2 s3 func_4_label_17
li s4 0
func_4_label_17 :
beq s4 zero func_4_label_41
sw t2 -20(t6)
mv s3 a3
mv s5 s0
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s1
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
flw fs1 0(s3)
sw t2 -24(t6)
mv s3 a2
mv s5 s1
sw t2 -28(t6)
mv s6 a1
mul s5 s5 s6
mv s6 s0
add s5 s5 s6
li s6 4
mul s5 s5 s6
add s3 s3 s5
fsw fs1 0(s3)
addi s4 s2 1
mv s1 s4
j func_4_label_12
func_4_label_41 :
addi s4 s2 1
mv s0 s4
j func_4_label_4
func_4_label_44 :
li a0 0
addi sp t5 -4
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_3 :
mv t6 sp
addi sp sp -8
mv t5 sp
addi sp sp 0
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
sw t2 -32(t6)
mv s0 a0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
sw a7 -4(sp)
addi sp sp -4
mv a0 s0
li a7 2
ecall
mv s1 a0
lw a7 0(sp)
addi sp sp 4
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv a0 s1
addi sp t5 -0
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_2 :
mv t6 sp
addi sp sp -8
mv t5 sp
addi sp sp 0
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
sw t2 -32(t6)
mv s0 a0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
sw a7 -4(sp)
addi sp sp -4
mv a0 s0
li a7 1
ecall
mv s1 a0
lw a7 0(sp)
addi sp sp 4
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv a0 s1
addi sp t5 -0
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
func_1 :
mv t6 sp
addi sp sp -8
mv t5 sp
addi sp sp 0
sw s0 -4(sp)
sw s1 -8(sp)
sw s2 -12(sp)
sw s3 -16(sp)
sw s4 -20(sp)
sw s5 -24(sp)
sw s6 -28(sp)
sw s7 -32(sp)
sw s8 -36(sp)
sw s9 -40(sp)
sw s10 -44(sp)
sw s11 -48(sp)
fsw fs0 -52(sp)
fsw fs1 -56(sp)
fsw fs2 -60(sp)
fsw fs3 -64(sp)
fsw fs4 -68(sp)
fsw fs5 -72(sp)
fsw fs6 -76(sp)
fsw fs7 -80(sp)
fsw fs8 -84(sp)
fsw fs9 -88(sp)
fsw fs10 -92(sp)
fsw fs11 -96(sp)
addi sp sp -96
sw t2 -32(t6)
mv s0 a0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
sw a7 -4(sp)
addi sp sp -4
mv a0 s0
li a7 4
ecall
mv s1 a0
lw a7 0(sp)
addi sp sp 4
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv a0 s1
addi sp t5 -0
lw s0 -4(sp)
lw s1 -8(sp)
lw s2 -12(sp)
lw s3 -16(sp)
lw s4 -20(sp)
lw s5 -24(sp)
lw s6 -28(sp)
lw s7 -32(sp)
lw s8 -36(sp)
lw s9 -40(sp)
lw s10 -44(sp)
lw s11 -48(sp)
flw fs0 -52(sp)
flw fs1 -56(sp)
flw fs2 -60(sp)
flw fs3 -64(sp)
flw fs4 -68(sp)
flw fs5 -72(sp)
flw fs6 -76(sp)
flw fs7 -80(sp)
flw fs8 -84(sp)
flw fs9 -88(sp)
flw fs10 -92(sp)
flw fs11 -96(sp)
mv sp t6
jr ra
