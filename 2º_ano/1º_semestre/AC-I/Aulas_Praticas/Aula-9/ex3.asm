	.data
	.eqv SIZE, 10
	
a:	.space 80 
sum:	.float 0.0
	.eqv read_double, 7
	.eqv print_double, 3
	.text
	.globl main
	
# Mapa de registos
# $a0 : double* array
# $a1  : int n 
# $t0  :  i 
# $f2 : sum 
# $f4 : array[i]
# $f6 : (double) n
average:	
	addiu $sp,$sp, -16
	sw $s0, 0($sp)
	sw $s1, 4($sp)
	sw $s2, 8($sp)
	sw $s3, 12($sp)
		
	addi $s0, $a1, -1
	
	
	la $s1, sum 
	l.d $f2, 0($s1)
	
for:	blt $s0, 0, endfor
	sll $s2, $s0, 3		# i * 8
	add $s3, $a0, $s2	# &array[i]		
	l.d $f4, 0($s3)		# array[i]
	add.d $f2, $f2, $f4	# sum += array[i]	
	
	addi $s0, $s0, -1
	j for
		
endfor:	
	mtc1 $a1, $f6		# meter a1 num registo F

	cvt.d.w $f6, $f6		# converter inteiro para double
	div.d $f0, $f2, $f6	# sum / n
	
	lw $s0, 0($sp)		
	lw $s1, 4($sp)
	lw $s2, 8($sp)
	lw $s3, 12($sp)
	addiu $sp,$sp, 16
	jr $ra
	
main:	
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
	jal average 
	
	mov.d $f12, $f0
	syscall
	
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	li $v0, 0
	jr $ra
	
