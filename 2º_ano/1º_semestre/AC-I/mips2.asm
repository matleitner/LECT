
.data
# nada a colocar aqui, de momento
.text
.globl main
main:
or $t0,$0,val_x # $t0 = x (substituir val_x pelo
# valor de x pretendido)
or $t2,$0,8 # $t2 = 8
add $t1,$t0,$t0 # $t1 = $t0 + $t0 = x + x = 2 * x
add $t1,$t1,$t2 # $t1 = $t1 + $t2 = y = 2 * x + 8
jr $ra # fim do programa