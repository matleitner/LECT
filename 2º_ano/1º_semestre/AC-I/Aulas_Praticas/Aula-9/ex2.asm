	.data
	
k1:	.double 5.0
k2:	.double 9.0
k3:	.double 32.0

	.eqv read_double,7
	.eqv print_double, 3
	.text
	.globl main
#Mapa de registos 	

f2c:	la $t0, k3		#$t0 = k3
	l.d $f2, 0($t0)		# f2 = 32.0
	sub.d $f0, $f12, $f2	# f0 = f12 - 32.0
	
	la $t0, k1		#$t0 = k1
	l.d $f2, 0($t0)		# f2 = 5
	la $t0,k2
	l.d $f4, 0($t0)		# f4 = 9
	
	
	mul.d $f0, $f2,$f0	# f0 = 5/9 * f0 
	div.d $f0, $f0, $f4	# f2 = 5/9
	jr $ra
			
main:	addiu $sp,$sp, -4
	sw $ra, 0($sp)
	li $v0, read_double
	syscall
	mov.d $f12, $f0
	jal f2c
	
	li $v0, print_double
	mov.d $f12, $f0
	syscall
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	jr $ra


