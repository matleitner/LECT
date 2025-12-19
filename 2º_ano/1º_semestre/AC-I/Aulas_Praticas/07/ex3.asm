	.data
	.eqv print_string, 4
str1:	.asciiz "I serodatupmoC rentieL"
str2:	.space 31
str3:	.asciiz "String too long... "
	.eqv STR_MAX_SIZE, 30 
	.eqv print_int10, 1
	
	.text
	
	.globl main
	
	
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
		
strlen:	li $t1, 0 	  # len = 0;
while2:	lb $t0, 0($a0) 	  # while(*s++!= '\0') leitura
	addiu $a0, $a0, 1  # incremento
	beq $t0,'\0', endw2 # comparação
	addi $t1, $t1, 1	  # len++;
	j while2
endw2:	move $v0, $t1	
	jr $ra 


strev:	addiu $sp, $sp, -16
	sw    $ra, 0($sp) #reserva espeço na stack
	sw    $s0, 4($sp) # guarda endereço de retorno
	sw    $s1, 8($sp) # guarda valor dos registos
	sw    $s2, 12($sp)# $s0, $s1 e $s2
	move  $s0, $a0    # registo "callee-saved"
	move  $s1, $a0    # p1 = str 
	move  $s2, $a0 	 # p2 = str
while3:	lb    $t0, 0($s2) # while (*p2 != '\0') {
	beq   $t0, '\0', endw3
	addi  $s2,$s2,1	 # p2++;
	
	
	j while3
endw3:
	addi  $s2,$s2, -1 #p2--

while4:	bge   $s1, $s2, endw4
	move  $a0, $s1
	move  $a1, $s2 
	jal exchange
	addiu $s1, $s1, 1
	addiu $s2, $s2, -1
	j while4
	
	 
endw4:	
	move $v0, $s0
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	lw $s2, 12($sp)
	addiu $sp, $sp, 16
	jr $ra



exchange:	lb $t0, 0($a0)
	lb $t1, 0($a1)
	sb $t0, 0($a1)
	sb $t1, 0($a0)
	
	
	jr $ra
	
	
main:	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	la $a0, str1
	la $a1, str2
	jal strlen
	
if:	bgt $v0, STR_MAX_SIZE, else
	la $a0, str2
	la $a1, str1 
	jal strcopy
	
	li $a0, '\n'
	li $v0, 11
	syscall
	la $a0, str2
	jal strev
	move $a0, $v0
	li $v0, print_string
	syscall
	li $s7, 0
	j endif
else: 
	la $a0, str3
	li $v0, print_string
	syscall
	
	la $a0, str1
	jal strlen
	move $a0, $v0
	li $v0, print_int10
	syscall 
	li $s7, 1
	
endif:
	
	move $v0, $s7
	lw $ra, 0($sp)
	addiu $sp, $sp, 4



	jr $ra
	
