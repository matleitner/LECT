	.data 

	.text
	.globl main 

main: 
	ori $t0, $0, 10 #%t0 = 10 antes era x
	ori $t2, $0, 8 #$t2 = 8
	add $t1, $t0, $t0 # $t1 = 2 * $t0 
	add $t1, $t1, $t2 # $t1 = $t1 + $t2  ==  y = 2*x +8
	
	jr $ra # fim programa
	 
