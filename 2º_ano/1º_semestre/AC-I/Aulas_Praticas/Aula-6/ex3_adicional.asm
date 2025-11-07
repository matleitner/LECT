	.data

	.eqv SIZE, 3
array:	.word str1, str2, str3
str1:	.asciiz "Array"
str2:	.asciiz "de"
str3:	.asciiz "ponteiros"
		
stringToPrint:	.asciiz "\nString #"
stringToPrint1:	.asciiz ": "
	.eqv print_string, 4 
	.eqv print_int10, 1
	.eqv print_char, 11
	
	.text
	.globl main
#Mapa de registos
# pp : $t0 / p : $t2  / $t3 : array / counterString : $t4 

main:	la $t0, array		# pp = array
	li $t4, 0	
	li $t5, SIZE		# $t5 = SIZE
	sll $t5, $t5, 2 	# 4 * SIZE
	add $t5, $t5, $t0	# ppUltimo = array + SIZE
	
for:	bge $t0, $t5, endf	# for ( pp< ppUltimo)
	la $a0, stringToPrint	#
	li $v0, print_string	#
	syscall			# print string 
	
	or $a0, $t4, $0
	li $v0, print_int10
	syscall			# print int10 

	li $v0, print_string
	la $a0, stringToPrint1
	syscall 		# print ": "
	lw $t6, 0($t0)		# $t6 -> endereço do array aka *array 
	
while:	lb $t7, 0($t6)		# $t7 -> **array ou seja a letra char
	beq $t7, '\0', endw	# while( **array != '\0')
	
	li $v0, print_char
	move $a0, $t7 
	syscall			# print char do array
	
	li $v0, print_char 
	li $a0, '-'
	syscall			# print '-'

	addi $t6, $t6,1		# *((*array)++)
	j while
endw:
	addi $t4, $t4, 1	# counter++
	addi $t0, $t0, 4 	# *array++
	j for 
endf:


	jr $ra
