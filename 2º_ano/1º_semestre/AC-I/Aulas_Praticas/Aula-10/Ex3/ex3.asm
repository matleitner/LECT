	.data
	.eqv SIZE, 10 
	.eqv read_double, 7
	.eqv print_double, 3
arr:	.double 80
zero:	.float 0.0
	.text
	.globl main
	
# Mapa de registos 
# $a0 : array ( ponteiro ) / $a1 : nval 
# media : $f2
# soma  : $f4 
# array[i] : $f12
# i : $s0 
 
var:	addiu $sp, $sp, -16
	sw $ra, 0($sp)
	sw $s0, 4($sp) 
	sw $s1, 8($sp)
	sw $s2, 12($sp)		# $a0 : arr $a1 : nval 
	jal average		# -> $f0 
	cvt.s.d $f2, $f0		# f2 media = (float) average (array, nval);
	li $s0, 0		# $s0 : i 
	la $s1, zero		#
	l.s $f4, 0($s1)		# soma = 0.0
	move $s2, $a0		# $s2 :  &arr 
for7:	bge $s0, $a1, endfor7 	# i < nval
			
	sll $t1, $s0, 3		# 
	addu $t2, $s2, $t1
	l.d $f12, 0($t2) 
	cvt.s.d $f12, $f12
	sub.s $f12, $f12, $f2
	li $a0,2
	
	jal xtoy 
	add.s $f4, $f4,$f0
	addi $s0, $s0, 1
	j for7	
endfor7:	
	cvt.d.s $f2, $f4
	mtc1 $a1, $f4
	cvt.d.w $f4,$f4
	
	div.d $f0, $f2, $f4
	
	lw $ra, 0($sp)
	lw $s0, 4($sp) 
	lw $s1, 8($sp)
	lw $s2, 12($sp)
	addiu $sp, $sp, 16
	jr $ra
	
stdev:	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	
	jal var 
	mov.d $f12, $f0
	
	jal sqrt
	
	lw $ra, 0($sp) 
	addiu $sp, $sp, 4	
	jr $ra 	
main:	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	li $s0, 0
	la $s2, arr
for:	bge $s0, SIZE, endfor
	sll $s1, $s0, 3
	addu $s1, $s2, $s1
	li $v0,read_double
	syscall
	
	s.d $f0, 0($s1)
	
	
	addiu $s0,$s0,1		
	j for	
endfor:	la $a0, arr
	li $a1, SIZE
	jal average
	mov.d $f12, $f0
	li $v0, print_double
	syscall 
	
	li $v0, 11
	li $a0, '\n'
	syscall
	
	la $a0, arr
	li $a1, SIZE
	jal var
	mov.d $f12, $f0
	li $v0, print_double
	syscall
	
	li $v0, 11
	li $a0, '\n'
	syscall
	
	la $a0, arr
	li $a1, SIZE
	jal stdev 
	mov.d $f12, $f0
	li $v0, print_double 
	syscall
	
	li $v0, 11
	li $a0, '\n'
	syscall
	
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	jr $ra