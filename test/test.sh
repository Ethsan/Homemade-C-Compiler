# test à faire
cd -P -- "$(dirname -- "$0")" && pwd -P
cd ..
# addition entiers 
./main -o test/out/add_int.s test/data/add_int.c
# addition floats
./main -o test/out/add_float.s test/data/add_float.c
# addition beaucoup de floats/entiers + cast int to float
./main -o test/out/lot_of_vars.s test/data/lot_of_vars.c
# soustraction, multiplication, division, modulo 2 entiers + negatif
./main -o test/out/op_int.s test/data/op_int.c
# soustraction, multiplication, division 2 floats + negatif
./main -o test/out/op_float.s test/data/op_float.c
# op if (&&, ||, !)
./main -o test/out/if_op.s test/data/if_op.c
# if < > <= >= == != + float + if else
./main -o test/out/if_op2.s test/data/if_op2.c
# while for
./main -o test/out/while_for.s test/data/while_for.c
# tableaux multi-dimensionnels entiers et floats
./main -o test/out/tab.s test/data/tab.c
# matice

# fonctions
./main -o test/out/fonctions.s test/data/fonctions.c

# fonctions avec beaucoup de parametres
./main -o test/out/fonctions2.s test/data/fonctions2.c
# fonctions recursives factoriel
./main -o test/out/factoriel.s test/data/factoriel.c

# printf printmat printint printfloat
./main -o test/out/print.s test/data/print.c

#tous les test dans un même fichier
./main -o test/out/all.s -c test/data/all.c
