
	.data
ma:	.float 0.0
	.eqv SIZE, 10
	.align 3
r:	.space 80
	.eqv read_double,7
	.eqv print_double, 3

	.text
	.globl main
                                                        
r:	addiu $sp, $sp, -16
		sw $ra, 0($sp)
		sw $s0, 4($sp)
		sw $s1, 8($sp)
		sw $s2, 12($sp)
		move $s0, $a0		#s0 = double *array
		move $s1, $a1		#s1 = nval
		
		
		jal average 
		cvt.s.d $f2,$f0 		# $f2 = average(array,nval) 	
		li $s2, 0		# i $t4
		la $t1, soma
		l.s $f4, 0($t1)		
r7:	bge $s2, $s1, endfor7
		sll $t5, $s2, 3
		addu $t6, $s0, $t5
		l.d $f6, 0($t6)
		cvt.s.d $f6, $f6
		sub.s  $f12, $f6, $f2 
		
		
		li $a0, 2
		jal xtoy
		add.s $f4, $f4, $f0	
		addi $s2, $s2, 1
		j for7
dfor7:	
		cvt.d.s $f4 ,$f4
		mtc1    $s1, $f8
		
		cvt.d.w $f8, $f8
		
		div.d $f0, $f4, $f8
		lw $ra, 0($sp)
		lw $s0, 4($sp)
		lw $s1, 8($sp)
		lw $s2, 12($sp)
