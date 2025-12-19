	.data
array:	.word	7692,23,5,234
	.eqv print_int10, 1
	.eqv SIZE, 4

	.text
	.globl main
# Mapa de registos
# p: $t0
# pultimo:$t1
# *p $t2
# soma: $t3 
main:	li	$t3, 0 		#soma = 0
	li	$t5, SIZE 	#temp = $t5 = SIZE
	addi	$t4,$t5,-1	#$t4 = SIZE-1
	sll	$t4,$t4,2	#$t4 = (SIZE-1)*4	
	la	$t0, array	#$t0 = p = array
	addu	$t1,$t0, $t4	#pultimo = array + (SIZE -1)
while:	
	bgtu	$t0,$t1,endw 	#while(p <= pultimo)
	lw	$t2, 0($t0)	#$t2 = *p
	add	$t3, $t3, $t2 	#soma = soma + (*p)
	addiu	$t0, $t0, 4	#p ++
		
	j while
	
endw:
	move	$a0, $t3
	li	$v0, print_int10 #print_int10(soma)
	syscall
	
	jr $ra
