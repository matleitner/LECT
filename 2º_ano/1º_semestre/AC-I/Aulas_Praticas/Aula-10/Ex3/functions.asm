	.data
result:	.float 1.0
xn:	.float 1.0 
zero:	.double 0.0
k1:	.double 0.5
sum:	.double 0.0
	.text
	.globl xtoy, average, sqrt
	
	
	
xtoy:	addiu $sp, $sp, -12
	sw $ra, 0($sp)
	s.s $f20, 4($sp)
	sw $s0, 8($sp)

	move $s0 , $a0
	mov.s $f20, $f12
	
	jal abs
	move $t1, $v0
	
	li $t0, 0		# i = 0
	la $t2, result		# 
	l.s $f0, 0($t2)		# $f0 = result
		
for3:	bgt $t0, $t1, endfor3 	# i< abs(y)

if3:	blez $s0, else3
	mul.s $f0, $f0, $f20
	j endif3	
else3:	
	div.s $f0, $f0, $f20
endif3:	addi $t0,$t0, 1
	j for3
endfor3:
	
	lw $s0, 8($sp)
	l.s $f20, 4($sp)
	lw $ra, 0($sp)
	addiu $sp, $sp, 12
	jr $ra
	
abs:	
if4:	bgez $a0, endif4
	sub $a0 , $0, $a0	# -val = 0 - val
	
endif4:	
	move $v0, $a0
	jr $ra
	
	
average:	
	addiu $sp,$sp, -16
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
		
	addi $s0, $a1, -1
	
	
	la $s1, sum 
	l.d $f2, 0($s1)
	
for5:	blt $s0, 0, endfor5
	sll $s2, $s0, 3		# i * 8
	add $s3, $a0, $s2	# &array[i]		
	l.d $f4, 0($s3)		# array[i]
	add.d $f2, $f2, $f4	# sum += array[i]	
	
	addi $s0, $s0, -1
	j for5
		
endfor5:	
	mtc1 $a1, $f6		# meter a1 num registo F
	#cvt.d.s $f2, $f2
	cvt.d.w $f6, $f6		# converter inteiro para double
	div.d $f0, $f2, $f6	# sum / n
	
	lw $s0, 0($sp)		
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	addiu $sp,$sp, 16
	jr $ra

sqrt:	li $t0, 0
	la $t1, zero
	l.d $f4, 0($t1)		# f4 = 0.0
if6:	c.le.d $f12, $f4		# f12 = val
	bc1t else6
 	la $t1, xn		#
 	l.d $f6,0($t1)		# f6 = xn
 	
do6:	mov.d $f2, $f6		# f2 = aux 
	div.d $f8, $f12, $f6	# val / xn
	add.d $f6, $f8, $f6	# xn + val / xn
	la $t1, k1		#
	l.d $f8, 0($t1)		# f8 = 0.5
	mul.d $f6, $f6, $f8	# 
	
	   
	c.eq.d $f2, $f6
	bc1t endif6
	addi $t0, $t0, 1
	bge $t0, 25, endif6
	j do6
	
else6:	
	mov.d $f6, $f4
endif6:	
	mov.d $f0, $f6
	jr $ra