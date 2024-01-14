# test à faire
# addition entiers 
../main -o out/add_int.s data/add_int.c
# addition floats
../main -o out/add_float.s data/add_float.c
# addition beaucoup de floats/entiers + cast int to float
../main -o out/lot_of_vars.s data/lot_of_vars.c
# soustraction, multiplication, division, modulo 2 entiers + negatif
../main -o out/op_int.s data/op_int.c
# soustraction, multiplication, division 2 floats + negatif
../main -o out/op_float.s data/op_float.c
# op if (&&, ||, !)
../main -o out/if_op.s data/if_op.c
# if < > <= >= == != + float + if else
../main -o out/if_op2.s data/if_op2.c
# while for
../main -o out/while_for.s data/while_for.c
# tableaux multi-dimensionnels entiers et floats
../main -o out/tab.s data/tab.c
# matice

# fonctions
../main -o out/fonctions.s data/fonctions.c

# fonctions avec beaucoup de parametres
../main -o out/fonctions2.s data/fonctions2.c
# fonctions recursives factoriel
../main -o out/factoriel.s data/factoriel.c

# printf printmat printint printfloat
../main -o out/print.s data/print.c

#tous les test dans un même fichier
../main -o out/all.s -c data/all.c