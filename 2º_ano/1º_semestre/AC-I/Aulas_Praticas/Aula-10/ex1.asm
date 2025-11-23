	.data
result:	.float 1.0
float:	.float 2.0
int:	.word  3
	.text
	.eqv print_float, 2
	.globl main
#Mapa de registos 
#$f12: x -> $f20 / $a0 : y -> $s0  / $t0 : i / result : $f0 / abs(y): $t1  

xtoy:	addiu $sp, $sp, -12
	sw $ra, 0($sp)
	s.s $f20, 4($sp)
	sw $s0, 8($sp)
			
	move $s0 , $a0		
	mov.s $f20, $f12		
	
	jal abs
	move $t1, $v0		# $t1 = abs(y)
			
	li $t0, 0		# i = 0
	la $t2, result		# 
	l.d $f0, 0($t2)		# $f0 = result
		
for:	bge $t0, $t1, endfor 	# i< abs(y)

if:	blez $s0, else
	mul.s $f0, $f0, $f20	# result*=x
	j endif	
else:	
	div.s $f0, $f0, $f20	# result/=x
	
endif:	addi $t0,$t0, 1
	j for
endfor:
	
	lw $s0, 8($sp)
	l.s $f20, 4($sp)
	lw $ra, 0($sp)
	addiu $sp, $sp, 12
	jr $ra
	
abs:	
if1:	bgez $a0, endif1
	sub $a0 , $0, $a0	# -val = 0 - val
	
endif1:	
	move $v0, $a0
	jr $ra
main:	
	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	
	la $t2, float
	l.s $f12, 0($t2)
	la $t2, int
	lw $a0, 0($t2)
	
	jal xtoy
	mov.s $f12, $f0 
	li $v0, print_float
	syscall
	
	lw $ra, 0($sp)
	addiu $sp, $sp, 4

	jr $ra
