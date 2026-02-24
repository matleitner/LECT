	.equ ADDR_BASE_HI, 0xBF88
	.equ TRISE, 0x6100
	.equ PORTE, 0X6110
	.equ LATE,  0x6120

	.equ TRISB, 0x6040
	.equ PORTB, 0x6050
	.equ LATB, 0x6060
	.data
	.text
	.globl main 

main:
		lui $t0, ADDR_BASE_HI
		lw $t1, TRISE($t0) 
		andi $t1, $t1, 0xFFFE
		sw $t1, TRISE($t0)
		
		lw $t1, TRISB($t0)
		ori $t1, $t1, 0x0001
		sw $t1, TRISB($t0)

		
while:

		lw $t2, PORTB($t0)
		andi $t2, $t2, 0x0001

		lw $t1, LATE($t0)
		andi $t1, $t1, 0xFFFE
		xor $t1, $t2, 0x1
#		xor   0   1

#        0    0   1
#        1    1   0
#
		sw $t1, LATE($t0)

		
		j while
		
		li $v0, 0
		jr $ra

