.data
decl_1 : 
.asciz "test print\n"
decl_2 : 
.asciz "Hello World!\n"
decl_3 : 
.asciz "\n"
decl_4 : 
.asciz "\n"
decl_5 : 
.asciz "test add\n"
decl_6 : 
.asciz "10+5 = "
decl_7 : 
.asciz "\n"
decl_8 : 
.asciz "10.0+5 = "
decl_9 : 
.asciz "\n"
decl_10 : 
.asciz "test tableau\n"
decl_11 : 
.asciz "tableau z[3][1][2] = "
decl_12 : 
.asciz "\n"
decl_13 : 
.asciz "tableau y[3][1][2] = "
decl_14 : 
.asciz "\n"
decl_15 : 
.asciz "test for while\n"
decl_16 : 
.asciz "for i<80 n = "
decl_17 : 
.asciz "\n"
decl_18 : 
.asciz "while i<50 n = "
decl_19 : 
.asciz "\n"
decl_20 : 
.asciz "test opération sur les entiers\n"
decl_21 : 
.asciz "a : "
decl_22 : 
.asciz "\n"
decl_23 : 
.asciz "b : "
decl_24 : 
.asciz "\n"
decl_25 : 
.asciz "b - a : "
decl_26 : 
.asciz "\n"
decl_27 : 
.asciz "b * a : "
decl_28 : 
.asciz "\n"
decl_29 : 
.asciz "b / a : "
decl_30 : 
.asciz "\n"
decl_31 : 
.asciz "b % a : "
decl_32 : 
.asciz "\n"
decl_33 : 
.asciz "-a : "
decl_34 : 
.asciz "\n"
decl_35 : 
.asciz "test opération sur les flottants\n"
decl_36 : 
.asciz "f : "
decl_37 : 
.asciz "\n"
decl_38 : 
.asciz "g : "
decl_39 : 
.asciz "\n"
decl_40 : 
.asciz "g - f : "
decl_41 : 
.asciz "\n"
decl_42 : 
.asciz "g * f: "
decl_43 : 
.asciz "\n"
decl_44 : 
.asciz "g / f: "
decl_45 : 
.asciz "\n"
decl_46 : 
.asciz "-f: "
decl_47 : 
.asciz "\n"
decl_48 : 
.asciz "test if else opération logique\n "
decl_49 : 
.asciz "ok\n"
decl_50 : 
.asciz "error\n"
decl_51 : 
.asciz "error\n"
decl_52 : 
.asciz "ok\n"
decl_53 : 
.asciz "ok\n"
decl_54 : 
.asciz "error\n"
decl_55 : 
.asciz "ok\n"
decl_56 : 
.asciz "error\n"
decl_57 : 
.asciz "error\n"
decl_58 : 
.asciz "ok\n"
decl_59 : 
.asciz "test if else opérateur relationnel\n "
decl_60 : 
.asciz "ok\n"
decl_61 : 
.asciz "error\n"
decl_62 : 
.asciz "error\n"
decl_63 : 
.asciz "ok\n"
decl_64 : 
.asciz "error\n"
decl_65 : 
.asciz "ok\n"
decl_66 : 
.asciz "ok\n"
decl_67 : 
.asciz "error\n"
decl_68 : 
.asciz "error\n"
decl_69 : 
.asciz "ok\n"
decl_70 : 
.asciz "ok\n"
decl_71 : 
.asciz "error\n"
decl_72 : 
.asciz "ok\n"
decl_73 : 
.asciz "error\n"
decl_74 : 
.asciz "ok\n"
decl_75 : 
.asciz "error\n"
decl_76 : 
.asciz "error\n"
decl_77 : 
.asciz "ok\n"
decl_78 : 
.asciz "error\n"
decl_79 : 
.asciz "ok\n"
decl_80 : 
.asciz "ok\n"
decl_81 : 
.asciz "error\n"
decl_82 : 
.asciz "error\n"
decl_83 : 
.asciz "ok\n"
decl_84 : 
.asciz "ok\n"
decl_85 : 
.asciz "error\n"
decl_86 : 
.asciz "ok\n"
decl_87 : 
.asciz "error\n"
decl_88 : 
.asciz "test fonction multiply entier et float\n"
decl_89 : 
.asciz "4*5 = "
decl_90 : 
.asciz "\n"
decl_91 : 
.asciz "4.3 * 5.2 = "
decl_92 : 
.asciz "\n"
decl_93 : 
.asciz "test fonction avec 8 arguments\n"
decl_94 : 
.asciz "c = "
decl_95 : 
.asciz "\n"
decl_96 : 
.asciz "f = "
decl_97 : 
.asciz "\n"
decl_98 : 
.asciz "test récurcivité (4!)\n"
decl_99 : 
.asciz "factoriel "
decl_100 : 
.asciz " = "
decl_101 : 
.asciz "\n"
.text
start_end :
li a0 0
li a1 0
jal func_32
li a7 93
ecall
func_32 :
mv t6 sp
addi sp sp -80
mv t5 sp
addi sp sp -60
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
li s2 0
li s3 0
li s4 0
li s5 0
li s6 0
li s7 0
li s8 0
li s9 0
addi sp sp -960
mv s0 sp
mv s10 s0
li t0 0x0
fmv.s.x fs6 t0
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
fsw fs6 0(s10)
addi s10 s10 4
addi sp sp -600
mv s1 sp
mv s10 s1
li s11 0
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
sw s11 0(s10)
addi s10 s10 4
la t2 decl_1
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s11 10
mv s2 s11
li t0 0x41200000
fmv.s.x fs6 t0
fmv.s fs0 fs6
la t2 decl_2
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_3
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
fmv.s fa0 fs6
jal func_3
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_4
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_5
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s11 10
mv s2 s11
li s11 5
mv s3 s11
mv s11 s2
sw s9 -40(t6)
lw s9 -52(t6)
mv s9 s3
add s11 s11 s9
mv s4 s11
la t2 decl_6
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s4
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_7
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li t0 0x41200000
fmv.s.x fs6 t0
fmv.s fs0 fs6
li s11 5
fcvt.s.w fs6 s11
fmv.s fs1 fs6
fmv.s fs6 fs0
fmv.s fs8 fs1
fadd.s fs6 fs6 fs8
fmv.s fs2 fs6
la t2 decl_8
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
fmv.s fa0 fs6
jal func_3
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_9
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_10
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s11 4
mv s4 s11
mv s11 s4
mv s9 s1
sw s3 -16(t6)
lw s3 -56(t6)
li s3 1
sw s4 -20(t6)
lw s4 -60(t6)
li s4 60
mul s3 s3 s4
add s9 s9 s3
li s3 2
li s4 12
mul s3 s3 s4
add s9 s9 s3
li s3 2
li s4 4
mul s3 s3 s4
add s9 s9 s3
sw s11 0(s9)
li s11 5
mv s9 s1
li s3 2
li s4 60
mul s3 s3 s4
add s9 s9 s3
li s3 3
li s4 12
mul s3 s3 s4
add s9 s9 s3
li s3 1
li s4 4
mul s3 s3 s4
add s9 s9 s3
sw s11 0(s9)
mv s9 s1
li s3 1
li s4 60
mul s3 s3 s4
add s9 s9 s3
li s3 2
li s4 12
mul s3 s3 s4
add s9 s9 s3
li s3 2
li s4 4
mul s3 s3 s4
add s9 s9 s3
lw s11 0(s9)
mv s3 s1
li s4 2
sw s8 -36(t6)
lw s8 -64(t6)
li s8 60
mul s4 s4 s8
add s3 s3 s4
li s4 3
li s8 12
mul s4 s4 s8
add s3 s3 s4
li s4 1
li s8 4
mul s4 s4 s8
add s3 s3 s4
lw s9 0(s3)
add s11 s11 s9
mv s9 s1
li s3 3
li s4 60
mul s3 s3 s4
add s9 s9 s3
li s3 1
li s4 12
mul s3 s3 s4
add s9 s9 s3
li s3 2
li s4 4
mul s3 s3 s4
add s9 s9 s3
sw s11 0(s9)
la t2 decl_11
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s9 s1
li s3 3
li s4 60
mul s3 s3 s4
add s9 s9 s3
li s3 1
li s4 12
mul s3 s3 s4
add s9 s9 s3
li s3 2
li s4 4
mul s3 s3 s4
add s9 s9 s3
lw s11 0(s9)
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_12
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li t0 0x4089999a
fmv.s.x fs6 t0
fmv.s fs3 fs6
fmv.s fs6 fs3
mv s9 s0
li s3 1
li s4 120
mul s3 s3 s4
add s9 s9 s3
li s3 2
li s4 24
mul s3 s3 s4
add s9 s9 s3
li s3 2
li s4 4
mul s3 s3 s4
add s9 s9 s3
fsw fs6 0(s9)
li t0 0x40a66666
fmv.s.x fs6 t0
mv s9 s0
li s3 2
li s4 120
mul s3 s3 s4
add s9 s9 s3
li s3 3
li s4 24
mul s3 s3 s4
add s9 s9 s3
li s3 1
li s4 4
mul s3 s3 s4
add s9 s9 s3
fsw fs6 0(s9)
mv s9 s0
li s3 1
li s4 120
mul s3 s3 s4
add s9 s9 s3
li s3 2
li s4 24
mul s3 s3 s4
add s9 s9 s3
li s3 2
li s4 4
mul s3 s3 s4
add s9 s9 s3
flw fs6 0(s9)
mv s3 s0
li s4 2
li s8 120
mul s4 s4 s8
add s3 s3 s4
li s4 3
li s8 24
mul s4 s4 s8
add s3 s3 s4
li s4 1
li s8 4
mul s4 s4 s8
add s3 s3 s4
flw fs8 0(s3)
fadd.s fs6 fs6 fs8
mv s9 s0
li s3 3
li s4 120
mul s3 s3 s4
add s9 s9 s3
li s3 1
li s4 24
mul s3 s3 s4
add s9 s9 s3
li s3 2
li s4 4
mul s3 s3 s4
add s9 s9 s3
fsw fs6 0(s9)
la t2 decl_13
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s9 s0
li s3 3
li s4 120
mul s3 s3 s4
add s9 s9 s3
li s3 1
li s4 24
mul s3 s3 s4
add s9 s9 s3
li s3 2
li s4 4
mul s3 s3 s4
add s9 s9 s3
flw fs6 0(s9)
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
fmv.s fa0 fs6
jal func_3
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_14
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_15
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s11 0
mv s5 s11
mv s11 s5
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s11 0
mv s2 s11
func_32_label_1069 :
mv s11 s2
li s9 80
li s10 1
blt s11 s9 func_32_label_1074
li s10 0
func_32_label_1074 :
beq s10 zero func_32_label_1082
mv s10 s5
addi s11 s10 1
mv s5 s11
mv s10 s2
addi s11 s10 1
mv s2 s11
j func_32_label_1069
func_32_label_1082 :
la t2 decl_16
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s5
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_17
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s11 0
mv s5 s11
li s11 0
mv s2 s11
func_32_label_1095 :
mv s11 s2
li s9 50
li s10 1
blt s11 s9 func_32_label_1100
li s10 0
func_32_label_1100 :
beq s10 zero func_32_label_1108
mv s10 s5
addi s11 s10 1
mv s5 s11
mv s10 s2
addi s11 s10 1
mv s2 s11
j func_32_label_1095
func_32_label_1108 :
la t2 decl_18
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s5
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_19
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_20
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s11 2
mv s6 s11
li s11 9
mv s7 s11
la t2 decl_21
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s6
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_22
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_23
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s7
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_24
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s7
mv s9 s6
sub s11 s11 s9
sw s0 -4(t6)
lw s0 -36(t6)
mv s0 s11
la t2 decl_25
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_26
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s7
mv s9 s6
mul s11 s11 s9
mv s0 s11
la t2 decl_27
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_28
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s7
mv s9 s6
div s11 s11 s9
mv s0 s11
la t2 decl_29
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_30
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s7
mv s9 s6
rem s11 s11 s9
mv s0 s11
la t2 decl_31
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_32
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s6
neg s11 s11
mv s0 s11
la t2 decl_33
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_34
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_35
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li t0 0x40e00000
fmv.s.x fs6 t0
fmv.s fs0 fs6
li t0 0x41000000
fmv.s.x fs6 t0
fmv.s fs1 fs6
la t2 decl_36
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
fmv.s fa0 fs6
jal func_3
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_37
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_38
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs1
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
fmv.s fa0 fs6
jal func_3
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_39
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs1
fmv.s fs8 fs0
fsub.s fs6 fs6 fs8
fmv.s fs2 fs6
la t2 decl_40
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
fmv.s fa0 fs6
jal func_3
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_41
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs1
fmv.s fs8 fs0
fmul.s fs6 fs6 fs8
fmv.s fs2 fs6
la t2 decl_42
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
fmv.s fa0 fs6
jal func_3
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_43
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs1
fmv.s fs8 fs0
fdiv.s fs6 fs6 fs8
fmv.s fs2 fs6
la t2 decl_44
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
fmv.s fa0 fs6
jal func_3
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_45
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs0
fneg.s fs6 fs6
fmv.s fs2 fs6
la t2 decl_46
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
fmv.s fa0 fs6
jal func_3
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_47
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_48
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s11 1
mv s6 s11
li s11 1
mv s7 s11
mv s10 s6
mv s11 s7
snez s10 s10
snez s11 s11
and s10 s10 s11
beq s10 zero func_32_label_1299
la t2 decl_49
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1302
func_32_label_1299 :
la t2 decl_50
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1302 :
li s11 0
mv s7 s11
mv s10 s6
mv s11 s7
snez s10 s10
snez s11 s11
and s10 s10 s11
beq s10 zero func_32_label_1314
la t2 decl_51
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1317
func_32_label_1314 :
la t2 decl_52
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1317 :
li s11 1
mv s7 s11
mv s10 s6
mv s11 s7
snez s10 s10
snez s11 s11
or s10 s10 s11
beq s10 zero func_32_label_1329
la t2 decl_53
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1332
func_32_label_1329 :
la t2 decl_54
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1332 :
li s11 0
mv s7 s11
mv s10 s6
mv s11 s7
snez s10 s10
snez s11 s11
or s10 s10 s11
beq s10 zero func_32_label_1344
la t2 decl_55
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1347
func_32_label_1344 :
la t2 decl_56
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1347 :
li s11 0
mv s6 s11
mv s10 s6
mv s11 s7
snez s10 s10
snez s11 s11
or s10 s10 s11
beq s10 zero func_32_label_1359
la t2 decl_57
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1362
func_32_label_1359 :
la t2 decl_58
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1362 :
la t2 decl_59
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s11 1
mv s6 s11
li s11 2
mv s7 s11
mv s11 s6
mv s9 s7
li s10 1
blt s11 s9 func_32_label_1374
li s10 0
func_32_label_1374 :
beq s10 zero func_32_label_1379
la t2 decl_60
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1382
func_32_label_1379 :
la t2 decl_61
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1382 :
mv s11 s6
mv s9 s7
li s10 1
bgt s11 s9 func_32_label_1387
li s10 0
func_32_label_1387 :
beq s10 zero func_32_label_1392
la t2 decl_62
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1395
func_32_label_1392 :
la t2 decl_63
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1395 :
mv s11 s6
mv s9 s7
li s10 1
beq s11 s9 func_32_label_1400
li s10 0
func_32_label_1400 :
beq s10 zero func_32_label_1405
la t2 decl_64
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1408
func_32_label_1405 :
la t2 decl_65
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1408 :
li s11 1
mv s7 s11
mv s11 s6
mv s9 s7
li s10 1
beq s11 s9 func_32_label_1415
li s10 0
func_32_label_1415 :
beq s10 zero func_32_label_1420
la t2 decl_66
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1423
func_32_label_1420 :
la t2 decl_67
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1423 :
mv s11 s6
mv s9 s7
li s10 1
bne s11 s9 func_32_label_1428
li s10 0
func_32_label_1428 :
beq s10 zero func_32_label_1433
la t2 decl_68
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1436
func_32_label_1433 :
la t2 decl_69
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1436 :
mv s11 s6
mv s9 s7
li s10 1
ble s11 s9 func_32_label_1441
li s10 0
func_32_label_1441 :
beq s10 zero func_32_label_1446
la t2 decl_70
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1449
func_32_label_1446 :
la t2 decl_71
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1449 :
mv s11 s6
mv s9 s7
li s10 1
bge s11 s9 func_32_label_1454
li s10 0
func_32_label_1454 :
beq s10 zero func_32_label_1459
la t2 decl_72
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1462
func_32_label_1459 :
la t2 decl_73
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1462 :
li t0 0x3f800000
fmv.s.x fs6 t0
fmv.s fs4 fs6
li t0 0x40000000
fmv.s.x fs6 t0
fmv.s fs0 fs6
fmv.s fs6 fs4
fmv.s fs8 fs0
li s10 1
flt.s t0 fs6 fs8
bnez t0 func_32_label_1471
li s10 0
func_32_label_1471 :
beq s10 zero func_32_label_1476
la t2 decl_74
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1479
func_32_label_1476 :
la t2 decl_75
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1479 :
fmv.s fs6 fs4
fmv.s fs8 fs0
li s10 1
fgt.s t0 fs6 fs8
bnez t0 func_32_label_1484
li s10 0
func_32_label_1484 :
beq s10 zero func_32_label_1489
la t2 decl_76
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1492
func_32_label_1489 :
la t2 decl_77
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1492 :
fmv.s fs6 fs4
fmv.s fs8 fs0
li s10 1
feq.s t0 fs6 fs8
bnez t0 func_32_label_1497
li s10 0
func_32_label_1497 :
beq s10 zero func_32_label_1502
la t2 decl_78
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1505
func_32_label_1502 :
la t2 decl_79
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1505 :
li t0 0x3f800000
fmv.s.x fs6 t0
fmv.s fs0 fs6
fmv.s fs6 fs4
fmv.s fs8 fs0
li s10 1
feq.s t0 fs6 fs8
bnez t0 func_32_label_1512
li s10 0
func_32_label_1512 :
beq s10 zero func_32_label_1517
la t2 decl_80
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1520
func_32_label_1517 :
la t2 decl_81
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1520 :
fmv.s fs6 fs4
fmv.s fs8 fs0
li s10 1
feq.s t0 fs6 fs8
beqz t0 func_32_label_1525
li s10 0
func_32_label_1525 :
beq s10 zero func_32_label_1530
la t2 decl_82
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1533
func_32_label_1530 :
la t2 decl_83
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1533 :
fmv.s fs6 fs4
fmv.s fs8 fs0
li s10 1
fle.s t0 fs6 fs8
bnez t0 func_32_label_1538
li s10 0
func_32_label_1538 :
beq s10 zero func_32_label_1543
la t2 decl_84
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1546
func_32_label_1543 :
la t2 decl_85
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1546 :
fmv.s fs6 fs4
fmv.s fs8 fs0
li s10 1
fge.s t0 fs6 fs8
bnez t0 func_32_label_1551
li s10 0
func_32_label_1551 :
beq s10 zero func_32_label_1556
la t2 decl_86
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
j func_32_label_1559
func_32_label_1556 :
la t2 decl_87
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
func_32_label_1559 :
la t2 decl_88
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s11 4
mv s6 s11
li s11 5
mv s7 s11
mv s9 s6
mv s3 s7
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
sw a1 -8(sp)
addi sp sp -8
mv a1 s3
mv a0 s9
jal func_6
mv s11 a0
lw a1 0(sp)
lw a0 4(sp)
addi sp sp 8
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s0 s11
la t2 decl_89
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_90
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li t0 0x4089999a
fmv.s.x fs6 t0
fmv.s fs5 fs6
li t0 0x40a66666
fmv.s.x fs6 t0
fmv.s fs4 fs6
fmv.s fs8 fs5
fmv.s fs9 fs4
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
sw a1 -8(sp)
addi sp sp -8
fmv.s fa1 fs9
fmv.s fa0 fs8
jal func_10
fmv.s fs6 fa0
lw a1 0(sp)
lw a0 4(sp)
addi sp sp 8
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs0 fs6
la t2 decl_91
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
fmv.s fa0 fs6
jal func_3
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_92
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_93
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s9 1
li s3 1
li s4 1
li s8 1
sw s1 -8(t6)
lw s1 -68(t6)
li s1 1
sw s2 -12(t6)
lw s2 -72(t6)
li s2 1
sw s6 -28(t6)
lw s6 -76(t6)
li s6 1
sw s7 -32(t6)
lw s7 -80(t6)
li s7 1
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
sw a1 -8(sp)
sw a2 -12(sp)
sw a3 -16(sp)
sw a4 -20(sp)
sw a5 -24(sp)
sw a6 -28(sp)
sw a7 -32(sp)
addi sp sp -32
mv a7 s7
mv a6 s6
mv a5 s2
mv a4 s1
mv a3 s8
mv a2 s4
mv a1 s3
mv a0 s9
jal func_14
mv s11 a0
lw a7 0(sp)
lw a6 4(sp)
lw a5 8(sp)
lw a4 12(sp)
lw a3 16(sp)
lw a2 20(sp)
lw a1 24(sp)
lw a0 28(sp)
addi sp sp 32
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s0 s11
la t2 decl_94
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_95
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li t0 0x3f800000
fmv.s.x fs8 t0
li t0 0x3f800000
fmv.s.x fs9 t0
li t0 0x3f800000
fmv.s.x fs10 t0
li t0 0x3f800000
fmv.s.x fs11 t0
fsw fs1 -8(t5)
flw fs1 -48(t5)
li t0 0x3f800000
fmv.s.x fs1 t0
fsw fs2 -12(t5)
flw fs2 -52(t5)
li t0 0x3f800000
fmv.s.x fs2 t0
fsw fs3 -16(t5)
flw fs3 -56(t5)
li t0 0x3f800000
fmv.s.x fs3 t0
fsw fs4 -20(t5)
flw fs4 -60(t5)
li t0 0x3f800000
fmv.s.x fs4 t0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
sw a1 -8(sp)
sw a2 -12(sp)
sw a3 -16(sp)
sw a4 -20(sp)
sw a5 -24(sp)
sw a6 -28(sp)
sw a7 -32(sp)
addi sp sp -32
fmv.s fa7 fs4
fmv.s fa6 fs3
fmv.s fa5 fs2
fmv.s fa4 fs1
fmv.s fa3 fs11
fmv.s fa2 fs10
fmv.s fa1 fs9
fmv.s fa0 fs8
jal func_23
fmv.s fs6 fa0
lw a7 0(sp)
lw a6 4(sp)
lw a5 8(sp)
lw a4 12(sp)
lw a3 16(sp)
lw a2 20(sp)
lw a1 24(sp)
lw a0 28(sp)
addi sp sp 32
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs0 fs6
la t2 decl_96
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
fmv.s fs6 fs0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
fmv.s fa0 fs6
jal func_3
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_97
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_98
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s11 4
mv s5 s11
mv s9 s5
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s9
jal func_4
mv s11 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
sw s0 -36(t6)
lw s0 -40(t6)
mv s0 s11
la t2 decl_99
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s5
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_100
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mv s11 s0
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_2
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
la t2 decl_101
mv s11 t2
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s11
jal func_1
mv s10 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
li s10 0
mv a0 s10
addi sp t5 -60
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
addi sp sp 960
addi sp sp 600
li a0 0
addi sp t5 -60
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
func_23 :
mv t6 sp
addi sp sp 0
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
fsw ft1 -32(t6)
fmv.s fs0 fa0
fsw ft1 -28(t6)
fmv.s fs1 fa1
fadd.s fs0 fs0 fs1
fsw ft1 -24(t6)
fmv.s fs1 fa2
fadd.s fs0 fs0 fs1
fsw ft1 -20(t6)
fmv.s fs1 fa3
fadd.s fs0 fs0 fs1
fsw ft1 -16(t6)
fmv.s fs1 fa4
fadd.s fs0 fs0 fs1
fsw ft1 -12(t6)
fmv.s fs1 fa5
fadd.s fs0 fs0 fs1
fsw ft1 -8(t6)
fmv.s fs1 fa6
fadd.s fs0 fs0 fs1
fsw ft1 -4(t6)
fmv.s fs1 fa7
fadd.s fs0 fs0 fs1
fmv.s fa0 fs0
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
func_14 :
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
sw t2 -28(t6)
mv s1 a1
add s0 s0 s1
sw t2 -24(t6)
mv s1 a2
add s0 s0 s1
sw t2 -20(t6)
mv s1 a3
add s0 s0 s1
sw t2 -16(t6)
mv s1 a4
add s0 s0 s1
sw t2 -12(t6)
mv s1 a5
add s0 s0 s1
sw t2 -8(t6)
mv s1 a6
add s0 s0 s1
sw t2 -4(t6)
mv s1 a7
add s0 s0 s1
mv a0 s0
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
func_10 :
mv t6 sp
addi sp sp 0
mv t5 sp
addi sp sp -16
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
fsw ft1 -32(t6)
fmv.s fs1 fa0
fsw ft1 -28(t6)
fmv.s fs2 fa1
fmul.s fs1 fs1 fs2
fmv.s fs0 fs1
fmv.s fs3 fs0
fmv.s fa0 fs3
addi sp t5 -16
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
addi sp t5 -16
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
func_6 :
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
sw t2 -32(t6)
mv s1 a0
sw t2 -28(t6)
mv s2 a1
mul s1 s1 s2
mv s0 s1
mv s3 s0
mv a0 s3
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
func_4 :
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
sw t2 -32(t6)
mv s0 a0
li s1 0
li s2 1
beq s0 s1 func_4_label_5
li s2 0
func_4_label_5 :
beq s2 zero func_4_label_9
li s2 1
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
j func_4_label_17
func_4_label_9 :
sw t2 -32(t6)
mv s2 a0
sw t2 -32(t6)
mv s1 a0
li s3 1
sub s1 s1 s3
sw ra -4(sp)
sw t5 -8(sp)
sw t6 -12(sp)
addi sp sp -12
sw a0 -4(sp)
addi sp sp -4
mv a0 s1
jal func_4
mv s0 a0
lw a0 0(sp)
addi sp sp 4
lw t6 0(sp)
lw t5 4(sp)
lw ra 8(sp)
addi sp sp 12
mul s2 s2 s0
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
func_4_label_17 :
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
