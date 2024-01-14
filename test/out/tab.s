.data
decl_1 : 
.asciz "a = "
decl_2 : 
.asciz "\n"
decl_3 : 
.asciz "b = "
decl_4 : 
.asciz "\n"
.text
start_end :
li a0 0
li a1 0
jal func_4
li a7 93
ecall
func_4 :
mv t6 sp
addi sp sp -36
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
li t0 0x0
fmv.s.x fs0 t0
li s2 0
addi sp sp -960
mv s0 sp
mv s3 s0
li t0 0x0
fmv.s.x fs1 t0
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
fsw fs1 0(s3)
addi s3 s3 4
addi sp sp -600
mv s1 sp
mv s3 s1
li s4 0
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
sw s4 0(s3)
addi s3 s3 4
li s4 4
mv s2 s4
mv s4 s2
mv s5 s1
li s6 1
li s7 60
mul s6 s6 s7
add s5 s5 s6
li s6 2
li s7 12
mul s6 s6 s7
add s5 s5 s6
li s6 2
li s7 4
mul s6 s6 s7
add s5 s5 s6
sw s4 0(s5)
li s4 5
mv s5 s1
li s6 2
li s7 60
mul s6 s6 s7
add s5 s5 s6
li s6 3
li s7 12
mul s6 s6 s7
add s5 s5 s6
li s6 1
li s7 4
mul s6 s6 s7
add s5 s5 s6
sw s4 0(s5)
mv s5 s1
li s6 1
li s7 60
mul s6 s6 s7
add s5 s5 s6
li s6 2
li s7 12
mul s6 s6 s7
add s5 s5 s6
li s6 2
li s7 4
mul s6 s6 s7
add s5 s5 s6
lw s4 0(s5)
mv s6 s1
li s7 2
li s8 60
mul s7 s7 s8
add s6 s6 s7
li s7 3
li s8 12
mul s7 s7 s8
add s6 s6 s7
li s7 1
li s8 4
mul s7 s7 s8
add s6 s6 s7
lw s5 0(s6)
add s4 s4 s5
mv s5 s1
li s6 3
li s7 60
mul s6 s6 s7
add s5 s5 s6
li s6 1
li s7 12
mul s6 s6 s7
add s5 s5 s6
li s6 2
li s7 4
mul s6 s6 s7
add s5 s5 s6
sw s4 0(s5)
la t2 decl_1
mv s4 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s4
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s5 s1
li s6 3
li s7 60
mul s6 s6 s7
add s5 s5 s6
li s6 1
li s7 12
mul s6 s6 s7
add s5 s5 s6
li s6 2
li s7 4
mul s6 s6 s7
add s5 s5 s6
lw s4 0(s5)
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s4
jal func_2
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_2
mv s4 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s4
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li t0 0x4089999a
fmv.s.x fs1 t0
fmv.s fs0 fs1
fmv.s fs1 fs0
mv s5 s0
li s6 1
li s7 120
mul s6 s6 s7
add s5 s5 s6
li s6 2
li s7 24
mul s6 s6 s7
add s5 s5 s6
li s6 2
li s7 4
mul s6 s6 s7
add s5 s5 s6
fsw fs1 0(s5)
li t0 0x40a66666
fmv.s.x fs1 t0
mv s5 s0
li s6 2
li s7 120
mul s6 s6 s7
add s5 s5 s6
li s6 3
li s7 24
mul s6 s6 s7
add s5 s5 s6
li s6 1
li s7 4
mul s6 s6 s7
add s5 s5 s6
fsw fs1 0(s5)
mv s5 s0
li s6 1
li s7 120
mul s6 s6 s7
add s5 s5 s6
li s6 2
li s7 24
mul s6 s6 s7
add s5 s5 s6
li s6 2
li s7 4
mul s6 s6 s7
add s5 s5 s6
flw fs1 0(s5)
mv s6 s0
li s7 2
li s8 120
mul s7 s7 s8
add s6 s6 s7
li s7 3
li s8 24
mul s7 s7 s8
add s6 s6 s7
li s7 1
li s8 4
mul s7 s7 s8
add s6 s6 s7
flw fs3 0(s6)
fadd.s fs1 fs1 fs3
mv s5 s0
li s6 3
li s7 120
mul s6 s6 s7
add s5 s5 s6
li s6 1
li s7 24
mul s6 s6 s7
add s5 s5 s6
li s6 2
li s7 4
mul s6 s6 s7
add s5 s5 s6
fsw fs1 0(s5)
la t2 decl_3
mv s4 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s4
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s5 s0
li s6 3
li s7 120
mul s6 s6 s7
add s5 s5 s6
li s6 1
li s7 24
mul s6 s6 s7
add s5 s5 s6
li s6 2
li s7 4
mul s6 s6 s7
add s5 s5 s6
flw fs1 0(s5)
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
la t2 decl_4
mv s4 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s4
jal func_1
mv s3 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
addi sp sp 960
addi sp sp 600
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
