	.data

array:	.word str1,str2,str3
	.eqv SIZE, 3
	.eqv print_string, 4
	.eqv print_char, 11
str1:	.asciiz "Array"
str2:	.asciiz "de"
str3:	.asciiz "inteiros"

	.text
	.globl main

#i : $t0
#p : $t1
#pultimo : $t2

main:	la $t1, array  #$t1 = array = p
	li $t0, SIZE
	sll $t0, $t0,2
	addu $t2, $t1, $t0 #pulotimo = array + SIZE
	
for:	bge $t1, $t2, endfor #p < pultimo
	lw $a0, 0($t1)	  	#$ a0 = array[i]
	li $v0, print_string 
	syscall
	addi $t1, $t1, 4
	li $v0, print_char
	li $a0, '\n'
	syscall
	j for
endfor:		
	
	
	jr $ra
