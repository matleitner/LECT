	.data
	.eqv SIZE, 3
	.eqv print_string, 4
	.eqv print_char, 11
	.eqv print_int10, 1
array:	.word str1,str2,str3

str1:	.asciiz "Array"
str2:	.asciiz "de"
str3:	.asciiz "ponteiros"
str4:	.asciiz "\nString #"
str5:	.asciiz ": "	
	.text
	.globl main

# i : $t0
# j : $t1
# array[i][j] : $t3


main:	li $t0, 0

for:	bge $t0, SIZE, endfor	
	li $v0, print_string
	la $a0, str4
	syscall
	
	li $v0, print_int10
	or $a0, $t0, $0
	syscall
	
	li $v0, print_string
	la $a0, str5
	syscall
	
	li $t1, 0
	
	
	
while:	
	
	la $t3, array	 	#$t3 = &array[0]
	
	sll $t2, $t0, 2
	addu $t3,$t3, $t2	# $t3 = &array[i]
	
	lw $t3, 0($t3)   	#$t3 = array[i] = array[i][0]
	addu $t3, $t3, $t1	#$t3 = &array[i][j]
	lb $t3, 0($t3)		#$t3 = array[i][j]
	beq $t3, '\0', endw
	
	or $a0, $0, $t3
	li $v0, print_char
	syscall
	
	li $a0, '-'
	li $v0, print_char
	syscall
	
	addi $t1, $t1, 1
	
	j while

endw:	

	
	
	addi $t0, $t0,1
	j for
	

endfor:

	jr $ra
	