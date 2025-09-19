	.data
	.text
	.globl main
	
main: 

	ori $t0, $0,2 # $t2 = x, 2,3,4,5
	ori $t2, $0, 8 # 8 do -8
	add $t1, $t0, $t0 # $t1 = 2 * $t2, $t1 = 2 * x
	sub $t1, $t1,$t2 #  $t1 = $t1 - $t2, $t1 = 2x - 8
	jr $ra
	
	