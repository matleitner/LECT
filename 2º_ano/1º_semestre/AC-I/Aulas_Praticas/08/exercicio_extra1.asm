	.data
	.text
	.globl main 
	
# Mapa de registos
# dividendo -> $a0 / divisor -> $a1


divide:	sll $a1, $a1, 16
	andi $a0, $a0, 0xFFFF
	sll $a0, $a0, 1
	
	li $t0, 0
	
for:	bge $t0, 16, endfor
	
	li $t2, 0
	
if:	blt $a0, $a1, endif
	sub $a0, $a0, $a1
	li $t2, 1
endif:
	sll $a0, $a0, 1
	or $a0, $a0, $t2
	
	addi $t0, $t0, 1
	j for
endfor:

	srl $t3, $a0, 1
	li $t2, 0xFFFF0000
	and $t3, $t3, $t2
	
	andi $t4, $a0, 0xFFFF
	
	 
	or $v0, $t3, $t4
	jr $ra
	
	
main:	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	
	li $a0, 6
	li $a1, 3
	
	jal divide
	
	move $a0, $v0
	li $v0, 1
	syscall
	li $v0, 0
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	jr $ra
	 