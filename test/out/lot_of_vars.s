.data
decl_1 : 
.asciz "\n"
decl_2 : 
.asciz " "
decl_3 : 
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
addi sp sp -116
mv t5 sp
addi sp sp -112
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
li t0 0x0
fmv.s.x fs0 t0
li t0 0x0
fmv.s.x fs1 t0
li t0 0x0
fmv.s.x fs2 t0
li t0 0x0
fmv.s.x fs3 t0
li t0 0x0
fmv.s.x fs4 t0
li t0 0x0
fmv.s.x fs5 t0
li t0 0x0
fmv.s.x fs6 t0
li t0 0x0
fmv.s.x fs7 t0
li t0 0x0
fmv.s.x fs8 t0
li t0 0x0
fmv.s.x fs9 t0
li t0 0x0
fmv.s.x fs10 t0
li t0 0x0
fmv.s.x fs11 t0
fsw fs11 -48(t5)
flw fs11 -52(t5)
li t0 0x0
fmv.s.x fs11 t0
fsw fs11 -52(t5)
flw fs11 -56(t5)
li t0 0x0
fmv.s.x fs11 t0
fsw fs11 -56(t5)
flw fs11 -60(t5)
li t0 0x0
fmv.s.x fs11 t0
fsw fs10 -44(t5)
flw fs10 -64(t5)
li t0 0x0
fmv.s.x fs10 t0
fsw fs9 -40(t5)
flw fs9 -68(t5)
li t0 0x0
fmv.s.x fs9 t0
fsw fs8 -36(t5)
flw fs8 -72(t5)
li t0 0x0
fmv.s.x fs8 t0
fsw fs7 -32(t5)
flw fs7 -76(t5)
li t0 0x0
fmv.s.x fs7 t0
fsw fs6 -28(t5)
flw fs6 -80(t5)
li t0 0x0
fmv.s.x fs6 t0
fsw fs5 -24(t5)
flw fs5 -84(t5)
li t0 0x0
fmv.s.x fs5 t0
fsw fs5 -84(t5)
flw fs5 -88(t5)
li t0 0x0
fmv.s.x fs5 t0
fsw fs5 -88(t5)
flw fs5 -92(t5)
li t0 0x0
fmv.s.x fs5 t0
fsw fs5 -92(t5)
flw fs5 -96(t5)
li t0 0x0
fmv.s.x fs5 t0
fsw fs5 -96(t5)
flw fs5 -100(t5)
li t0 0x0
fmv.s.x fs5 t0
fsw fs5 -100(t5)
flw fs5 -104(t5)
li t0 0x0
fmv.s.x fs5 t0
li s0 0
li s1 0
li s2 0
li s3 0
li s4 0
li s5 0
li s6 0
li s7 0
li s8 0
li s9 0
li s10 0
li s11 0
sw s11 -48(t6)
lw s11 -52(t6)
li s11 0
sw s11 -52(t6)
lw s11 -56(t6)
li s11 0
sw s11 -56(t6)
lw s11 -60(t6)
li s11 0
sw s11 -60(t6)
lw s11 -64(t6)
li s11 0
sw s11 -64(t6)
lw s11 -68(t6)
li s11 0
sw s11 -68(t6)
lw s11 -72(t6)
li s11 0
sw s11 -72(t6)
lw s11 -76(t6)
li s11 0
sw s11 -76(t6)
lw s11 -80(t6)
li s11 0
sw s11 -80(t6)
lw s11 -84(t6)
li s11 0
sw s11 -84(t6)
lw s11 -88(t6)
li s11 0
sw s11 -88(t6)
lw s11 -92(t6)
li s11 0
sw s11 -92(t6)
lw s11 -96(t6)
li s11 0
sw s11 -96(t6)
lw s11 -100(t6)
li s11 0
sw s11 -100(t6)
lw s11 -104(t6)
li s11 0
sw s11 -104(t6)
lw s11 -108(t6)
li s11 1
mv s0 s11
li s11 2
mv s1 s11
li s11 3
mv s2 s11
li s11 4
mv s3 s11
li s11 5
mv s4 s11
li s11 6
mv s5 s11
li s11 7
mv s6 s11
li s11 8
mv s7 s11
li s11 9
mv s8 s11
li s11 10
mv s9 s11
li s11 11
mv s10 s11
li s11 12
sw s0 -4(t6)
lw s0 -48(t6)
mv s0 s11
li s11 13
sw s0 -48(t6)
lw s0 -52(t6)
mv s0 s11
li s11 14
sw s0 -52(t6)
lw s0 -56(t6)
mv s0 s11
li s11 15
sw s0 -56(t6)
lw s0 -60(t6)
mv s0 s11
li s11 16
sw s0 -60(t6)
lw s0 -64(t6)
mv s0 s11
li s11 17
sw s0 -64(t6)
lw s0 -68(t6)
mv s0 s11
li s11 18
sw s1 -8(t6)
lw s1 -72(t6)
mv s1 s11
li s11 19
sw s2 -12(t6)
lw s2 -76(t6)
mv s2 s11
li s11 20
sw s3 -16(t6)
lw s3 -80(t6)
mv s3 s11
li s11 21
sw s4 -20(t6)
lw s4 -84(t6)
mv s4 s11
li s11 22
sw s5 -24(t6)
lw s5 -88(t6)
mv s5 s11
li s11 23
sw s6 -28(t6)
lw s6 -92(t6)
mv s6 s11
li s11 24
sw s7 -32(t6)
lw s7 -96(t6)
mv s7 s11
li s11 25
sw s8 -36(t6)
lw s8 -100(t6)
mv s8 s11
li s11 26
sw s9 -40(t6)
lw s9 -104(t6)
mv s9 s11
mv s11 s0
sw s0 -68(t6)
lw s0 -112(t6)
mv s0 s1
add s11 s11 s0
mv s0 s2
add s11 s11 s0
mv s0 s3
add s11 s11 s0
mv s0 s4
add s11 s11 s0
mv s0 s5
add s11 s11 s0
mv s0 s6
add s11 s11 s0
mv s0 s7
add s11 s11 s0
mv s0 s8
add s11 s11 s0
mv s9 s11
fsw fs5 -104(t5)
flw fs5 -108(t5)
li t0 0x3f800000
fmv.s.x fs5 t0
fmv.s fs0 fs5
li t0 0x40000000
fmv.s.x fs5 t0
fmv.s fs1 fs5
li t0 0x40400000
fmv.s.x fs5 t0
fmv.s fs2 fs5
li t0 0x40800000
fmv.s.x fs5 t0
fmv.s fs3 fs5
li s11 5
fcvt.s.w fs5 s11
fmv.s fs4 fs5
li t0 0x41700000
fmv.s.x fs5 t0
fmv.s fs11 fs5
li t0 0x41800000
fmv.s.x fs5 t0
fmv.s fs10 fs5
li t0 0x41880000
fmv.s.x fs5 t0
fmv.s fs9 fs5
li t0 0x41900000
fmv.s.x fs5 t0
fmv.s fs8 fs5
li t0 0x41980000
fmv.s.x fs5 t0
fmv.s fs7 fs5
li t0 0x41a00000
fmv.s.x fs5 t0
fmv.s fs6 fs5
li t0 0x41a80000
fmv.s.x fs5 t0
fsw fs0 -4(t5)
flw fs0 -84(t5)
fmv.s fs0 fs5
li t0 0x40c00000
fmv.s.x fs5 t0
fsw fs1 -8(t5)
flw fs1 -24(t5)
fmv.s fs1 fs5
li t0 0x40e00000
fmv.s.x fs5 t0
fsw fs1 -24(t5)
flw fs1 -28(t5)
fmv.s fs1 fs5
li t0 0x41000000
fmv.s.x fs5 t0
fsw fs1 -28(t5)
flw fs1 -32(t5)
fmv.s fs1 fs5
li t0 0x41100000
fmv.s.x fs5 t0
fsw fs1 -32(t5)
flw fs1 -36(t5)
fmv.s fs1 fs5
li t0 0x41200000
fmv.s.x fs5 t0
fsw fs1 -36(t5)
flw fs1 -40(t5)
fmv.s fs1 fs5
li t0 0x41300000
fmv.s.x fs5 t0
fsw fs1 -40(t5)
flw fs1 -44(t5)
fmv.s fs1 fs5
li t0 0x41400000
fmv.s.x fs5 t0
fsw fs1 -44(t5)
flw fs1 -48(t5)
fmv.s fs1 fs5
li t0 0x41500000
fmv.s.x fs5 t0
fsw fs1 -48(t5)
flw fs1 -52(t5)
fmv.s fs1 fs5
li t0 0x41600000
fmv.s.x fs5 t0
fsw fs1 -52(t5)
flw fs1 -56(t5)
fmv.s fs1 fs5
li s11 22
fcvt.s.w fs5 s11
fsw fs1 -56(t5)
flw fs1 -88(t5)
fmv.s fs1 fs5
li t0 0x41b80000
fmv.s.x fs5 t0
fsw fs2 -12(t5)
flw fs2 -92(t5)
fmv.s fs2 fs5
li t0 0x41c00000
fmv.s.x fs5 t0
fsw fs2 -92(t5)
flw fs2 -96(t5)
fmv.s fs2 fs5
li t0 0x41c80000
fmv.s.x fs5 t0
fsw fs2 -96(t5)
flw fs2 -100(t5)
fmv.s fs2 fs5
fmv.s fs5 fs9
fsw fs2 -100(t5)
flw fs2 -112(t5)
fmv.s fs2 fs8
fadd.s fs5 fs5 fs2
fmv.s fs2 fs7
fadd.s fs5 fs5 fs2
fmv.s fs2 fs6
fadd.s fs5 fs5 fs2
fmv.s fs2 fs0
fadd.s fs5 fs5 fs2
fmv.s fs2 fs1
fadd.s fs5 fs5 fs2
fsw fs0 -84(t5)
flw fs0 -104(t5)
fmv.s fs0 fs5
sw s0 -112(t6)
lw s0 -116(t6)
li s0 0
mv a0 s0
addi sp t5 -112
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
li a0 0
addi sp t5 -112
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
beq s3 zero func_110_label_49
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
beq s3 zero func_110_label_41
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
mv s2 s1
li s4 1
add s2 s2 s4
mv s1 s2
j func_110_label_15
func_110_label_41 :
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
mv s2 s0
li s4 1
add s2 s2 s4
mv s0 s2
j func_110_label_7
func_110_label_49 :
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
beq s4 zero func_99_label_54
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
beq s4 zero func_99_label_49
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
mv s2 s1
li s3 1
add s2 s2 s3
mv s1 s2
j func_99_label_12
func_99_label_49 :
mv s2 s0
li s3 1
add s2 s2 s3
mv s0 s2
j func_99_label_4
func_99_label_54 :
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
beq s4 zero func_88_label_52
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
beq s4 zero func_88_label_47
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
mv s2 s1
li s3 1
add s2 s2 s3
mv s1 s2
j func_88_label_12
func_88_label_47 :
mv s2 s0
li s3 1
add s2 s2 s3
mv s0 s2
j func_88_label_4
func_88_label_52 :
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
beq s4 zero func_81_label_48
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
beq s4 zero func_81_label_43
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
mv s2 s1
li s3 1
add s2 s2 s3
mv s1 s2
j func_81_label_12
func_81_label_43 :
mv s2 s0
li s3 1
add s2 s2 s3
mv s0 s2
j func_81_label_4
func_81_label_48 :
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
beq s4 zero func_73_label_50
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
beq s4 zero func_73_label_45
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
mv s2 s1
li s3 1
add s2 s2 s3
mv s1 s2
j func_73_label_12
func_73_label_45 :
mv s2 s0
li s3 1
add s2 s2 s3
mv s0 s2
j func_73_label_4
func_73_label_50 :
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
beq s4 zero func_65_label_50
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
beq s4 zero func_65_label_45
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
mv s2 s1
li s3 1
add s2 s2 s3
mv s1 s2
j func_65_label_12
func_65_label_45 :
mv s2 s0
li s3 1
add s2 s2 s3
mv s0 s2
j func_65_label_4
func_65_label_50 :
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
beq s4 zero func_57_label_50
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
beq s4 zero func_57_label_45
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
mv s2 s1
li s3 1
add s2 s2 s3
mv s1 s2
j func_57_label_12
func_57_label_45 :
mv s2 s0
li s3 1
add s2 s2 s3
mv s0 s2
j func_57_label_4
func_57_label_50 :
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
beq s4 zero func_49_label_50
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
beq s4 zero func_49_label_45
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
mv s2 s1
li s3 1
add s2 s2 s3
mv s1 s2
j func_49_label_12
func_49_label_45 :
mv s2 s0
li s3 1
add s2 s2 s3
mv s0 s2
j func_49_label_4
func_49_label_50 :
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
beq s5 zero func_38_label_96
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
beq s5 zero func_38_label_91
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
beq s5 zero func_38_label_86
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
mv s3 s2
li s4 1
add s3 s3 s4
mv s2 s3
j func_38_label_33
func_38_label_86 :
mv s3 s1
li s4 1
add s3 s3 s4
mv s1 s3
j func_38_label_13
func_38_label_91 :
mv s3 s0
li s4 1
add s3 s3 s4
mv s0 s3
j func_38_label_5
func_38_label_96 :
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
beq s5 zero func_27_label_84
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
beq s5 zero func_27_label_79
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
beq s5 zero func_27_label_74
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
mv s3 s2
li s4 1
add s3 s3 s4
mv s2 s3
j func_27_label_21
func_27_label_74 :
mv s3 s1
li s4 1
add s3 s3 s4
mv s1 s3
j func_27_label_13
func_27_label_79 :
mv s3 s0
li s4 1
add s3 s3 s4
mv s0 s3
j func_27_label_5
func_27_label_84 :
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
beq s4 zero func_19_label_59
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
beq s4 zero func_19_label_54
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
mv s2 s1
li s3 1
add s2 s2 s3
mv s1 s2
j func_19_label_12
func_19_label_54 :
mv s2 s0
li s3 1
add s2 s2 s3
mv s0 s2
j func_19_label_4
func_19_label_59 :
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
beq s4 zero func_11_label_59
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
beq s4 zero func_11_label_54
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
mv s2 s1
li s3 1
add s2 s2 s3
mv s1 s2
j func_11_label_12
func_11_label_54 :
mv s2 s0
li s3 1
add s2 s2 s3
mv s0 s2
j func_11_label_4
func_11_label_59 :
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
beq s4 zero func_4_label_48
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
beq s4 zero func_4_label_43
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
mv s2 s1
li s3 1
add s2 s2 s3
mv s1 s2
j func_4_label_12
func_4_label_43 :
mv s2 s0
li s3 1
add s2 s2 s3
mv s0 s2
j func_4_label_4
func_4_label_48 :
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
