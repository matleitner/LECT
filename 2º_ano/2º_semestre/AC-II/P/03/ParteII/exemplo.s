		.equ ADDR_BASE_HI, 0xBF88
		.equ TRISE, 0x6100
		.equ PORTE, 0x6110
		.equ LATE, 0x6120
		
		.equ TRISB, 0X6040
		.equ PORTB, 0X6050
		.equ LATB, 0X6060
		.equ readCoreTimer, 11
		.equ resetCoreTimer, 12
		.data
		.text
		.globl main

main:
		lui $t0, ADDR_BASE_HI
		lw $t1, TRISE($t0)
		andi $t1, $t1, 0xFFE1
		sw $t1, TRISE($t0)
		
		lw $t1, TRISB($t0)
		# 0001 1110
		ori $t1, $t1, 0x001E
		sw $t1, TRISB($t0)

		li $t2, 0

while:
		lw $t1, LATE($t0)
		andi $t1, $t1, 0xFFE1
		sll $t3, $t2, 1
		or $t1, $t1, $t3
		sw $t1, LATE($t0)
		
		li $v0, resetCoreTimer
		syscall

wait:	li $v0, readCoreTimer
		syscall
		blt $v0, 4347826, wait

		addi $t2, $t2, 1 
		andi $t2, $t2, 0x000F

		j while

