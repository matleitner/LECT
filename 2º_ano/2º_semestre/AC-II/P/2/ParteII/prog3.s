#int main(){
#	int count10Hz = 0;
#	int count5Hz = 0;
#	int count1Hz = 0;
#
#	int ms_10Hz = 100;   	// 10Hz (o maior)
#	int multiplo_5Hz  = 2;  // quando count10Hz faz 5 o 5hz aumenta 1
#	int m_1Hz  = 10;		//
#		
#	
#	while(1){
#		char c = inkey();
#		if(c == 'A'){
#			
#			ms_10Hz = ms_10Hz / 2;
#			
#
#		}elseif (c=='R'){
#
#			int ms_10Hz = 100;   	// 10Hz (o maior)
#		}
#
#		...
#		
#	}
#
#
#}



				.data
				.equ inkey, 1
				.equ resetCoreTimer, 12
				.equ readCoreTimer, 11
				.equ putChar, 3 
				.equ printInt, 6
				.text
				.globl main 
	
main:			addi $sp, $sp, -4
				sw $ra, 0($sp)

				li $t0, 0			# contador 10Hz	
				li $t1, 0			# contador 5hz
				li $t2, 0			# contador 1Hz
				li $t4, 100			# tempo em ms da maior frequencia
				li $t5, 5 			# multiplos metade da maior freq
				li $t6, 10 			# mult. 1/10 da maior freq
					
							
				# 100 ms 10 Hz  1000ms 1Hz   200 ms 5Hz 3
				
while:			beq $t0, 100, endwhile
				
				li $v0, putChar
				li $a0, '\r'
				syscall
				

				li $v0, inkey
				syscall
				move $t3, $v0			# $t3 é o que guarda o char
				beq $t3, $0, endif
if_A:			
				li $t9, 'A'
				bne $t3, $t9, if_N
				sra $t4, $t4, 1

if_N:
				li $t9, 'N'
				bne $t3, $t9, endif
				li $t4, 100
endif:

				
				
				move $a0, $t4
				jal delay
			
				
				addi $t0, $t0, 1
					
if5:			rem $t7, $t0, $t5
				bne $t7, $0, end_if5
				addi $t1, $t1, 1

end_if5:

if10:			rem $t8, $t0, $t6
				bne $t8, $0, end_if10
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

