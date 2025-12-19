	.data
	.eqv TRUE, 1
	.eqv FALSE, 0
array:	.double 1.2, 3.2, 3.1, 21.3, 0.0
	.text
	.globl main 
	
median:	

do:	# do {
	li $t1, FALSE	# houveTroca = FALSE
	li $t0, 0	# i = 0
	addi $t2, $a1, -1	# nval -1
for:	bge $t0, $t2, endfor	# for(int i = 0; i< nval -1; i ++){
	sll $t3, $t0, 3
	add $t3, $a0, $t3
	l.d $f2, 0($t3)		# f2 -> array[i]

			#
	l.d $f6, 8($t3)		# f6 -> array[i+1]
	
if:	c.le.d $f2, $f6
	bc1t endif
	mov.d $f4, $f2
	s.d $f6, 0($t3)
	s.d $f4, 8($t3)
	li $t1, TRUE
endif:	
	
	addi $t0, $t0, 1
	j for
endfor:

while:	beq $t1, TRUE, do

	
	div $t5, $a1, 2
	sll $t5, $t5, 3
	add $t5, $a0, $t5
	l.d $f0, 0($t5)
	jr $ra
	
	 
main:	addiu $sp, $sp, -4 
	sw $ra, 0($sp)

	la $a0, array
	li $a1, 5 
	jal median
	
	li $v0, 3
	mov.d $f12, $f0
	syscall
	
	
	lw $ra, 0 ($sp)
	addiu $sp, $sp, 4
	jr $ra 