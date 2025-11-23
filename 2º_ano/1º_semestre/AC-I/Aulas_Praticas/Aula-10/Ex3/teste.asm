	.data
soma:	.float 0.0
	.eqv SIZE, 10
arr:	.space 80
	.eqv read_double,7
	.eqv print_double, 3
	
	.text
	.globl main

var:	addiu $sp, $sp, -12
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)
	
	move $s0, $a0		#s0 = double *array
	move $s1, $a1		#s1 = nval
	
	
	jal average 
	cvt.d.s $f2,$f0 		# $f2 = average(array,nval) 	
	li $t4, 0		# i $t4
	la $t1, soma
	l.s $f4, 0($t1)		
for7:	bge $t4, $s1, endfor7
	sll $t5, $t4, 3
	addu $t6, $s1, $t5
	l.d $f6, 0($t6)
	cvt.s.d $f6, $f6
	sub.s  $f12, $f6, $f2 
	li $a0, 2
	add.s $f4, $f4, $f0	
	addi $t4, $t4, 1
	j for7
endfor7:	
	cvt.d.s $f4 ,$f4
	mtc1    $s1, $f8
	
 	cvt.d.w $f8, $f8
	
	div.d $f0, $f4, $f8
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	addiu $sp, $sp, 12
	jr $ra
	
stdev:	addiu $sp, $sp, -12
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)
	move $s0, $a0
	move $s1, $a1
	
	jal var
	mov.d $f12, $f0
	jal sqrt
	
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	addiu $sp, $sp, 12
	jr $ra
	
	
main:	addiu $sp, $sp, -12
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)
	
	li $s0, 0
	la $a0, arr
	li $a1, SIZE
	
for_main:	bge $s0, SIZE, endfor_main
	sll $t8, $s0, 3
	addu $t8, $a0, $t8
	li $v0, read_double
	syscall
	sw $v0, 0($t8)
	addi $s0, $s0, 1
	j for_main
endfor_main:	
	jal average
	li $v0, print_double
	mov.d $f12, $f0
	
	jal var
	mov.d $f12, $f0
	syscall 
	
	jal stdev
	mov.d $f12, $f0
	syscall
	
	li $v0, 0
	
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	addiu $sp, $sp, 12
	jr $ra