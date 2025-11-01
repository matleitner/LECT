#void main(void)
#
#	static int[] = {8, 4, 15, -1987, 327, -9, 27, 16};
#	int i, v;
#
#	i = 0;
#	do {
#		v = val[i];
#		val[i] = val[i+SIZE/2];
#		val[i+SIZE/2] = v;
#	} while(++i < (SIZE / 2));
#
#	print_string("Result is: ");
#	i = 0;
#	do {
#		print_int10(val[i++);
#		print_char(',');
#	} while (i < SIZE);
#}
#Mapa de registos
#$t0 = i
#v = $t1
#val = $t2
	.data
str1:	.asciiz "Result is: "
	
	.eqv print_int10, 1
	.eqv print_char, 11
	.eqv print_string,4
	.eqv SIZE, 8

	.align 2
val:	.word 8,4,15,-1987,327,-9,27,16
	
	.text
	.globl main


main:	li $t0, 0		# i = 0
	la $t2, val		# $t2 = val[0]

do:	
	sll $t3, $t0, 2 	# $t3 = i * 4
	add $t3, $t3, $t2	# $t3 = val[0] +i*4
	
	lw $t1, 0($t3)		#v = val[i]
	li $t4, SIZE		#$t4 = SIZE	
	
	srl $t4, $t4, 1		#$t4 = SIZE * 4 
	sll $t7, $t4, 2
	add $t6, $t3, $t7	#$t4 = i + SIZE /2
	lw $t5, 0($t6) 		#$t5 = val[i +SIZE/2]
	sw $t5, 0($t3)		# val[i] = val[i+SIZE/2]
	sw $t1, 0($t6)		# val[i +SIZE/2] = v
	

while:	addi $t0, $t0,1
	blt $t0, $t4, do
	
	li $v0, print_string
	la $a0, str1
	syscall

	li $t0, 0
do1:
	li $v0, print_int10
	sll $t1, $t0,2
	add $t1, $t1,$t2
	lw $a0, 0($t1)
	addi $t0,$t0,1
	syscall

	li $v0, print_char
	li $a0, ','  
	syscall
	blt $t0, SIZE, do1

	jr $ra

