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
		# configurar TRISE RE0 = 0 entrada

		andi $t1, $t1, 0xFFFE
		sw $t1, TRISE($t0)
		
		lw $t1, TRISB($t0)
		# configurar TRISB RB0 = 1 saida	
		ori $t1, $t1, 0x0001
		
		sw $t1, TRISB($t0)

		
while:
		# And do portB é o input
		# LAT é o output que o LATE fica (LAT E é os ledzinhos da placa)
		
		lw $t2, PORTB($t0)
		andi $t2, $t2, 0x0001
		

		lw $t1, LATE($t0)
		andi $t1, $t1, 0xFFFE
		or $t1, $t1, $t2
		sw $t1, LATE($t0)

		
		j while
		
		li $v0, 0
		jr $ra

