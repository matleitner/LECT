	.data
str:	.asciiz "ITED - orievA ed edadisrevinU"
	.eqv print_string, 4
	.text
	.globl main
	
#Mapa de registos:
# str:	$a0 -> $s0 (argumento é passado em $a0)
# p1: 	$s1 (registo callee-saved)
# p2:	$s2 (regosto callee-saved)
#

exchange:	lb $t0, 0($a0)
	lb $t1, 0($a1)
	sb $t0, 0($a1)
	sb $t1, 0($a0)
	
	
	jr $ra
	
strev:	addiu $sp, $sp, -16
	sw    $ra, 0($sp) #reserva espeço na stack
	sw    $s0, 4($sp) # guarda endereço de retorno
	sw    $s1, 8($sp) # guarda valor dos registos
	sw    $s2, 12($sp)# $s0, $s1 e $s2
	move  $s0, $a0    # registo "callee-saved"
	move  $s1, $a0    # p1 = str 
	move  $s2, $a0 	 # p2 = str
while1:	lb    $t0, 0($s2) # while (*p2 != '\0') {
	beq   $t0, '\0', endw1
	addi  $s2,$s2,1	 # p2++;
	
	
	j while1
endw1:
	addi  $s2,$s2, -1 #p2--

while2:	bge   $s1, $s2, endw2
	move  $a0, $s1
	move  $a1, $s2 
	jal exchange
	addiu $s1, $s1, 1
	addiu $s2, $s2, -1
	j while2
	
	 
endw2:	
	move $v0, $s0
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	lw $s2, 12($sp)
	addiu $sp, $sp, 16
	jr $ra

main:	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	
	la $a0, str
	jal strev
	move $a0, $v0
	li $v0, print_string
	syscall
	
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	jr $ra
	


		
