	.data
str1:	.asciiz "Nr. de parametros: "
str2:	.asciiz "\nP"
str3:	.asciiz ": "
	
	.eqv print_string, 4
	.eqv print_int10, 1 
	
	.text
	.globl main
	
# i = $t2
# $a0 = $t0 = argc
# argv  = $t1 = $a1
main:	li $t2, 0 #i = 0
	or $t0, $a0, $0
	or $t1, $a1, $0
	li $v0, print_string
	la $a0, str1
	syscall   	 #print string
	

	
	
	li $v0, print_int10
	or $a0, $t0, $0		#print agrc
	syscall 
	
for:	bge $t2, $t0, endfor
	li $v0, print_string
	la $a0, str2
	syscall 		
	
	li $v0, print_int10
	or $a0, $0, $t2
	syscall
	
	li $v0, print_string
	la $a0, str3
	syscall 

	sll $t3, $t2, 2		#&argv[0] + i *4
	add $t4, $t1, $t3
	
	lw $a0, 0($t4)		#print (*argv[i])
	li $v0, print_string	
	syscall  

	addi $t2, $t2, 1
	j for
endfor:	

	jr $ra
