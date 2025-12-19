	.data
	.text
	.globl main 
	
main: 	li $t1, 0x5
	srl $t0, $t1, 1
	xor $t1, $t1,$t0 
	jr $ra
	 