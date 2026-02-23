#void delay(unsigned int ms)
#{
#	resetCoreTimer();
#	while(readCoreTimer() < K * ms);
#}



	.data
	.equ resetCoreTimer, 12
	.equ readCoreTimer, 11
	.equ printInt, 6
	.equ putChar, 3
	.text 
	.globl main

main:			addi $sp, $sp, -4
				sw $ra, 0($sp)
				li $t1, 0
while:			beq $t1, 10, end_while
				
				li $v0, putChar
				li $a0, '\r'
				syscall

				li $v0, printInt
				move $a0, $t1
				li $a1, 2
				sll $a1, $a1, 16
				ori $a1, $a1, 10
				syscall

				li $a0, 1000
				jal delay

				addi $t1, $t1, 1
				j while
end_while:		
							
				lw $ra, 0($sp)
				addi $sp, $sp, 4
				li $v0, 0 
				jr $ra
					

delay:			li $v0, resetCoreTimer			# 
				syscall							# resetCoreTimer();

while_delay:	li $v0, readCoreTimer
				syscall	
				li $t2, 20000					# t -> segundos = 20 000 000
												# t -> ms = 20 000
				mul $t0, $a0, $t2 
				bge $v0, $t0, endwhile_delay

				j while_delay
endwhile_delay:
			
				jr $ra
