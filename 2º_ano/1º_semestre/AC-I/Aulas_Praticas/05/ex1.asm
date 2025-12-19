	.data
	.eqv SIZE, 5	
	.eqv print_string, 4
	.eqv read_int, 5 
str1:	.asciiz "\nIntroduza um numero: "
	.align 2
lista:	.space 20 
	.text
	.globl main

# i: $t0
# lista: $t1
# lista + i: $t2
	
main: 	li $t0,0 		#i = 0;
while:	bge $t0, SIZE, endw 	#while ( i < SIZE ){
 	li $v0, print_string
 	la $a0, str1
 	syscall			#print_string
 	
 	la $t1,lista		# $t1 = lista ou (&lista[0])
 	sll $t2, $t0, 2		# $t2 = 4 * i
 	addu $t2, $t1, $t2	# $t2 = lista + (i*4)
 	
 		
 	li $v0, read_int	# read_int
 	syscall			# escrever o input no array
 	sw $v0, 0($t2)		
 	addi $t0, $t0, 1 	# i++
 	j while			# saltar para o while
 	
 	
endw:	jr $ra