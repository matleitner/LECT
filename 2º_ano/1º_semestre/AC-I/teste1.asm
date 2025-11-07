	.data
# nada a colocar aqui, de momento
	.eqv SIXZE, 213
	.text
	.globl main
main: ori $t0,$0, 11 # $t0 = x (substituir val_x pelo
# valor de x pretendido)
#	ori $t2,$0,8 # $t2 = 8
#	add $t1,$t1,$t2 # $t1 = $t1 + $t2 = y = 2 * x + 8
	beq $t0, $t0, end1
end1:
	bne $t0, SIXZE, end
end:		
	jr $ra # fim do programa
