	.data
	.eqv SIZE, 10
	.eqv FALSE, 0
	.eqv TRUE,  1
lista:	.word 4,1,2,3,45,6,8,7,6,3
	.text
	.globl main
	
# Mapa de registros
# houveTroca = $t0 / aux = $t1 / p = $t2 / pUltimo = $t3

main: 	la $t3, lista
	li $t4, SIZE
	addi $t4, $t4, -1
	sll $t4, $t4, 2
	addu $t3, $t3, $t4


	
do:	li $t0, FALSE
	la $t2, lista
for:	bge $t2, $t3,endfor
if:	lw $t4, 0($t2)
	lw $t5, 4($t2)
	bge $t4, $t5, endif
	move $t1, $t4
	sw $t5, 0($t2)
	sw $t1, 4($t2)
	li $t0, TRUE
endif:
	
	addi $t2, $t2,4
	j for
endfor:	
	
	beq $t0, TRUE, do
	 
	jr $ra
	

