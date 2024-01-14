.data
.text
start_end :
li a0 0
li a1 0
jal func_0
li a7 93
ecall
func_0 :
mv t6 sp
addi sp sp -12
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
li s0 5
li s1 6
add s2 s0 s1
mv a0 s2
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