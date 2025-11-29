	.data
str1:	.asciiz "\nN. Mec: "
str2:	.asciiz "\nNome: "
str3:	.asciiz "\nNota: " 
str4:	.asciiz "Primeiro Nome: "
str5:	.asciiz "Ultimo nome: "
str6:	.asciiz "Nota : "
	
	.align 2
stg:	.space 44
	#.word 72343
	#.asciiz "Napoleao"	# 9 bytes
	#.space 9		# 18 - 9 = 9
	#.asciiz "Bonaparte"	# 10 bytes
	#.space 5		# 15 - 10 = 5
	#.align 2 
	#.float 5.1
	.text
	.globl main
	
	
main:	
# Preencher estrutura
	
	la $a0, str1 
	li $v0, 4
	syscall 
	la $t0, stg
	
	#Read int 
	li $v0, 5
	syscall
	#store
	sw $v0, 0($t0)
	#######
	
	la $a0, str4
	li $v0, 4		# 
	syscall 
	#read first name
	li $v0, 8 
	# store
	addi $a0, $t0, 4
	li $a1, 14
	syscall
	
	 

	
	######
	la $a0, str5
	li $v0, 4
	syscall
	
	# read last name 
	li $v0, 8 
	li $a1, 17
	addi $a0, $t0, 22		# buffer para o read_str saber onde guardar os chars
	syscall

	# read float	
	la $a0, str6
	li $v0, 4
	syscall
	  
	li $v0, 6 
	syscall
	
	s.s $f0, 40($t0)
	
	
# Ler estrutura
	la $a0, str1 
	li $v0, 4
	syscall 
	
	li $v0, 36 	
		
	la $t0, stg		# $t0 = &stg
	
	lw $a0, 0($t0) 		# 
	syscall
	
	la $a0, str2 
	li $v0, 4		# 
	syscall 
	addi $a0, $t0, 22
	
	li $v0, 4		# 
	syscall 
	
	li $a0, ',' 
	li $v0, 11
	syscall
	
	addi $a0, $t0, 4
	li $v0, 4		# 
	syscall 
	
	
	li $v0, 4 
	la $a0, str3
	syscall
	
	li $v0, 2
	addi $t1, $t0, 40
	
	l.s $f12, 0($t1)
	syscall
	
	li $v0, 0
	
	jr $ra