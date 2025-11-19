	.data
xn:	.double 1.0
k1:	.double 0.5
zero:	.double 0.0
number:	.double 64
	.text
	.globl main
# Mapa de registos
# val : $f12
# i : $t0
# aux : $f2
# 

main:	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	la $t0, number
	l.d $f12, 0($t0)
	jal sqrt
	mov.d $f12, $f0
	
	li $v0, 3
	syscall
	
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	jr $ra


sqrt:	li $t0, 0
	la $t1, zero
	l.d $f4, 0($t1)		# f4 = 0.0
if:	c.le.d $f12, $f4		# f12 = val
	bc1t else
 	la $t1, xn		#
 	l.d $f6,0($t1)		# f6 = xn
 	
do:	mov.d $f2, $f6		# f2 = aux 
	div.d $f8, $f12, $f6	# val / xn
	add.d $f6, $f8, $f6	# xn + val / xn
	la $t1, k1		#
	l.d $f8, 0($t1)		# f8 = 0.5
	mul.d $f6, $f6, $f8	# 
	
	   
	c.eq.d $f2, $f6
	bc1t endif
	addi $t0, $t0, 1
	bge $t0, 25, endif
	j do
	
else:	
	mov.d $f6, $f4
endif:	
	mov.d $f0, $f6
	jr $ra
