	.data
	.eqv SIZE, 10
	
a:	.space 80 
sum:	.float 0.0
	.eqv read_double, 7
	.eqv print_double, 3
	.text
	.globl main
# Mapa de registos 	
#  p  : $a0	
#  n  : $a1
# max : $f0
# *p  : $f2
#  u  : $t0 

max:	addi $sp, $sp, -4
	sw $s0, 0($sp)
	sll $a1, $a1, 3		
	addi $s0, $a1, -8	# double *u = p+n-1 
	addu $s0, $s0, $a0	#
	
	l.d $f0, 0($a0)		# $f0 : max  
	addiu $a0, $a0, 8	# p++
	
for:	bgt $a0, $s0, endfor	# dor(; p<= u; p++)
	l.d $f2, 0($a0)		# $f2 = *p 
	
if:	c.le.d $f0, $f2		# if (max < *p ) 
	bc1f endif
	mov.d $f0, $f2		# max = *p
	
endif:
	addi $a0, $a0, 8		# p++
	j for 
endfor:	
	
	# f0 já é o max
	
	lw $s0, 0($sp)
	addi $sp, $sp, 4
	jr $ra
		
main:
            ###-----------------------### 
	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	la $t2, a
	
	li $t0, 0 
for1:	bge $t0, SIZE, endfor1
	sll $t1, $t0, 3
	addu $t1, $t2, $t1
	
	li $v0, read_double
	syscall
	
	s.d $f0, 0($t1)
	addi $t0, $t0,1
	j for1
	
endfor1:	
	li $v0 , print_double
	move $a0, $t2
	li $a1, SIZE
	jal max 
	
	mov.d $f12, $f0
	syscall
	
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	li $v0, 0
	jr $ra
