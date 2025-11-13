	.data
str1:	.space 33
buf:	.space 33
	.eqv print_string, 4
	.eqv read_int, 5
	.text
	.globl main



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
##---------------------------##

# Mapa de registos
# n:$a0 -> $s0
# b:$a1 -> $s1
# s:$a2 -> $s2
# p: $s3
# digit: $t0
# Sub-rotina intermédia
toascii:
	addi $a0, $a0, 48
if:	ble $a0, 57, endif	
	addi $a0, $a0, 7
endif:
	move $v0, $a0
	jr $ra
	
itoa:	addiu $sp, $sp, -16
	
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)
	sw $s2, 12($sp)
	
	move $s0, $a0	# $s0 = n		
	move $s1, $a1	# $s1 = b
	move $s2, $a2 	# $s2 = s
	move $s3, $a2	#  $s3 = p = s
do:	rem $t0, $s0, $s1
	div $s0, $s0, $s1
	
	move $a0, $t0
	jal toascii
	sb $v0, 0($s3)
		
	addiu $s3, $s3,1
	bgt $s0, 0, do
	li $t5, '\0'
	sb $t5, 0($s3)
	move $a0, $s2
	jal strev
	
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	lw $s2, 12($sp)
	addiu $sp, $sp, 16
	
	jr $ra
	
print_int_ac1:	
	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	
	
	
	jal itoa
	
	move $a0, $v0
	li $v0, print_string
	syscall
	 
	lw $ra, 0($sp)
	addiu $sp , $sp, 4
	jr $ra
	
main:	addiu $sp, $sp, -4
	sw $ra, 0($sp)
do2:	li $v0, read_int
	syscall
	move $a0, $v0
	
	
#	li $a1, 2
#	la $a2, str1
	
#	jal itoa
	
#	move $a0, $v0
#	li $v0, print_string
#	syscall
#	move $a0, $t8
#	
#	la $a2, str1
#	li $a1, 8
	
#	jal itoa
	
#	move $a0, $v0
#	li $v0, print_string
#	syscall
	
#	move $a0, $t8
	#la $a2, str1
	#li $a1, 16
	
	#jal itoa 
	
	#move $a0, $v0
	#li $v0, print_string
	#syscall
	
	la $a2, buf
	li $a1, 16
	
	jal print_int_ac1
	
	bne $t8, 0, do2	
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	jr $ra
