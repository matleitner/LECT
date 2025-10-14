	.data
	.eqv SIZE, 10	
	.align 2
lista:	.space 40
	.eqv SIZE, 10
	.eqv print_string, 4
	.eqv read_int, 5 
str1:	.asciiz "\nIntroduza um numero: "
	.text
	.globl main
	
	
# Mapa
# $t0 = p
# $t1 = *p
# $t2 = lista + size 

main:		la $t0, lista
		li $t3, SIZE
		sll $t3, $t3, 2
		addu $t2, $t3, $t0
whileReadInt:	bgeu $t0, $t2, endwri

		li $v0, read_int
		syscall 

		sw $v0, 0($t0)
		addiu $t0, $t0, 4
		
		j whileReadInt
endwri:
		
		jr $ra