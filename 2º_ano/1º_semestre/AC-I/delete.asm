	.text
	.globl main
	
main:	li $t5, 0x81354AB3
	srl $t3, $t5, 1
	jr $ra