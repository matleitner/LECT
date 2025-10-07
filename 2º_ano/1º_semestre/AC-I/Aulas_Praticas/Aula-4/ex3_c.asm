	.data
array:	.word	7692,23,5,234
	.eqv print_int10, 1
	.eqv SIZE, 4

	.text
	.globl main
# Mapa de registos
# p: $t0
# i:$t1
#  $t2
# soma: $t3 
main:	li	$t3, 0 		#soma = 0
	li	$t1, 0 		#i = 0
		
	la	$t0, array	#$t0 = p = array
	
while:	
	bge	$t1,SIZE,endw 	#while(i < SIZE)
	
	sll	$t2,$t1,2	#$t2 = i *4
	add	$t5,$t2, $t0
	lw	$t4, 0($t5)	#$t4 = array[i]
	add	$t3, $t3, $t4 	#soma = soma + array[i]
	addi	$t1, $t1, 1	#i++
		
	j while
	
endw:
	move	$a0, $t3
	li	$v0, print_int10 #print_int10(soma)
	syscall
	
	jr $ra

