#void main(void) {
#	static int a[N], b[N];
#	int n_even = 0;
#	int n_odd = 0;
#	int *p1, *p2;
#
#	for (p1 = a; p1 < (a + N); p1++) {
#       	*p1 = read_int();
#	}
#
#    	for (p1 = a, p2 = b; p1 < (a + N); p1++) {
#       	if ( (*p1 % 2) != 0) {
#			*p2++ = *p1;
#            		n_odd++;
#        	} 
#		else 
#            		n_even++;
#    	}
#
#    	for (p2 = b; p2 < (b + n_odd); p2++) {
#        	print_int10(*p2);
#    	}
#}

# Mapa de registos
# n_even: 	$t0
# n_odd: 	$t1
# p1: 		$t2
# p2: $t3


	.data 
	.eqv N, 5
  	.align 2
a:	.space 140
boe:	.space 140



	
	.eqv read_int,5
	.eqv print_int10,1
	
	
    	.text
	
	.globl main

main:	li $t0, 0		#n_even = 0
	li $t1, 0		#n_odd = 0
	la $t2, a		#$t2 = a
	li $t5, N 		#$t5 = N
	sll $t5, $t5, 2		#$t5 = N*2
	add $t5, $t2, $t5	#$t5 = N*2 + a
	
for1:	bge $t2, $t5, endf1		#for p<(a+N)
	li $v0, read_int	#
	syscall			# read_int -> $v0
	sw $v0, 0($t2)		# *p1 = read_int
	addiu $t2, $t2, 4	# p1++
	j for1

endf1:
	la $t2, a		# p1 = $t2 = a
	la $t3, boe		# p2 =$t3 = b  
for2:	bge $t2, $t5, endf2	# 

iff2:	lw $t4, 0($t2)
	rem $t6, $t4, 2
	beq $t6, 0,elsef2
	sw $t4, 0($t3)
	addiu $t3, $t3, 4
	addi  $t1, $t1, 1
elsef2:
	addi $t0, $t0, 1
	addiu $t2, $t2, 4
	j for2
endf2:	
	la $t3, boe	
	sll $t1, $t1, 2
	addu $t6, $t3, $t1
for3:
	
	bge $t3, $t6, endf3
	li $v0, print_int10
	lw $a0, 0($t3)
	syscall
	addiu $t3, $t3,4
	j for3  
endf3:		

	jr $ra

