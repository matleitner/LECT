	.data

str1:	.asciiz "2020 e 2024 sao anos bissextos"
	.eqv print_int10, 1
	.text
	.globl main
	
# Mapa de registos
# res: $v0
# s: $a0
# *s: $t0
# digit: $t1
# Sub-rotina terminal: não devem ser usados registos $sx


atoi:	li $v0, 0  		# res = 0;
while:	lb $t0, 0($a0) 		# ehile(*s >= '0' && s*<='9'){
	blt $t0, '0',endw 	#
	bgt $t0, '9', endw	#
			# s++
			# *s++
	addiu $a0,$a0, 1
	addi  $t1, $t0, -48	# *s++ - '0'
	mulu $v0, $v0,10		# res = 10 * res;	
	addu $v0, $t1, $v0	#res = 10 * res + digit;	
	j while		
endw:
	jr $ra
	
	
	
	
	

main:	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	
	la $a0, str1
	jal atoi 
	move $a0, $v0
	li $v0, print_int10
	syscall
	
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	
	jr $ra