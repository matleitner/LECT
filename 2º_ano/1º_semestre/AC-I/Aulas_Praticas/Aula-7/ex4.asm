	.data
str1:	.asciiz "Arquitetura de "
str2:	.space 50

str4:	.asciiz "Computadores I"
str3:	.asciiz "\n"
	.eqv print_string, 4
	.text
	.globl main
#0 chat gpt ez clap L bozzo 


strcat:	addiu $sp, $sp, -8
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	
while1:	lb $t0, 0($a0) # char *p = dst
	beq $t0, '\0', endw1
	
	addi $a0, $a0, 1
	j while1
	 
endw1: 	
	jal strcopy
	
	lw $v0, 4($sp)	
	lw $ra, 0($sp)
	addiu $sp, $sp,8
	jr $ra
	
strcopy:	li $t0, 0 	# $t0 = i = 0
	move $t1, $a0 	# dst
	move $t3, $a1 	# src
do:	lb $t2, 0($t3)
	sb $t2, 0($t1)     # dst[i] = src[i]		
while:	addi $t0,$t0,1
	add $t1, $t0,$a0
	add $t3, $t0, $a1
	bne $t2, '\0', do 
	move $v0, $a0 
	jr $ra
	
main:	
	la $a0, str2
	la $a1, str1
	jal strcopy
	
	move $a0, $v0
	li $v0, print_string
	syscall
	
	# print("\n")	
	
	la $a0, str3
	li $v0, 4
	syscall
 	
	
	la $a0, str2
	la $a1, str4
	jal strcat
	move $a0, $v0
	li $v0, print_string
	syscall
	
	li $v0, 0
	
	jr $ra 