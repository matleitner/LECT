	.equ ADDR_BASE_HI, 0xBF88
	.equ TRISE, 0x6100
	.equ PORTE, 0X6110
	.equ LATE,  0x6120

	.equ TRISD, 0x60C0
	.equ PORTD, 0x60D0
	.equ LATD, 0x60E0
	.data
	.text
	.globl main 

main:
		
		lui $t0, ADDR_BASE_HI
		lw $t1, TRISE($t0) 
		# configurar TRISE RE8 = 0 saida 

		andi $t1, $t1, 0xFFFE
		sw $t1, TRISE($t0)
		
		lw $t1, TRISD($t0)
		# configurar TRISB RD8 = 1 entrada 
		ori $t1, $t1, 0x0100
		
		sw $t1, TRISD($t0)
		
		
while:
		# And do portD é o input sem clicar fica a 1 clica fica 0 

		# LAT é o output que o LATE fica (LAT E é os ledzinhos da placa)
		#     0 1 

		# 1   1 0
		 
		
		lw $t2, PORTD($t0)
		andi $t2, $t2, 0x0100
		xor $t2, $t2, 0xFFFF
		
		lw $t1, LATE($t0)

		ori $t1,$t1, 0x0001 	
		srl $t2, $t2, 8
		and $t1, $t1, $t2
		sw $t1, LATE($t0)	

		
		j while

		li $v0, 0
		jr $ra

