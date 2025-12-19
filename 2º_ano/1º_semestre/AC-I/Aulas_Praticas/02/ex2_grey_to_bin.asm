	.data
	.text
	.globl main
	
main: 	li $t0, 0x64
	srl $t1, $t0, 4
	xor  $t0, $t0, $t1
	srl $t1, $t0, 2
	xor $t0, $t0, $t1
	srl $t1, $t0,1
	xor $t1, $t0, $t1
	jr $ra
	
	