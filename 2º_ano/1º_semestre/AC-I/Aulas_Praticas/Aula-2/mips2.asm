	.data
	.text
	.globl main
	
main: 
	ori $t0,$0, 0x0F1E  #$t0 = 0x0F1E 
	nor $t1, $0, $t0    # $t1  = ~$t0
	jr $ra