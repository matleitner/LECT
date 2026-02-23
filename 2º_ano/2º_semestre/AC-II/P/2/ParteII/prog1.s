				.data
				.equ resetCoreTimer, 12
				.equ readCoreTimer, 11
				.equ putChar, 3 
				.equ printInt, 6
				.text
				.globl main 
	
main:			addi $sp, $sp, -4
				sw $ra, 0($sp)

				li $t0, 0
				li $t1, 0
				li $t2, 0
		
				
while:			li $v0, putChar
				li $a0, '\r'
				syscall
				
				
				li $a0, 100 
				jal delay
			
				
				addi $t0, $t0, 1
					
if5:			rem $t5, $t0, 5
				bne $t5, 0, end_if5
				addi $t1, $t1, 1

end_if5:

if10:			rem $t5, $t0, 10
				bne $t5, 0, end_if10
				addi $t2, $t2, 1

end_if10:
				li $v0, printInt
				move $a0, $t0
				li $a1, 5 
				sll $a1, $a1, 16
				or $a1, $a1, 10
				syscall
				

				li $v0, putChar
				li $a0, ' '
				syscall
				

				li $v0, printInt
				move $a0, $t1
				li $a1, 5 
				sll $a1, $a1, 16
				or $a1, $a1, 10
				syscall

				li $v0, putChar
				li $a0, ' '
				syscall
				

				li $v0, printInt
				move $a0, $t2
				li $a1, 5 
				sll $a1, $a1, 16
				or $a1, $a1, 10
				syscall

				j while
endwhile:			

				lw $ra, ($sp)
				addi $sp, $sp, 4
				jr $ra
				
delay:          addi $sp,$sp, -8
				sw $s1, 0($sp)
				sw $s2, 4($sp)

				li $v0, resetCoreTimer          # 
                syscall                         # resetCoreTimer();
 
while_delay:    li $v0, readCoreTimer
                syscall 
                li $s2, 20000                   # t -> segundos = 20 000 000
                                                 # t -> ms = 20 000
                 mul $s1, $a0, $s2 
                 bge $v0, $s1, endwhile_delay
 
                 j while_delay
endwhile_delay:
             	 lw $s1, 0($sp)
				 lw $s2, 4($sp)
				 addi $sp, $sp, 8
                 jr $ra

