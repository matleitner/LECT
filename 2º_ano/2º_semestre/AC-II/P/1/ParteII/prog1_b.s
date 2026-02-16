#int main(void)
#{
#	char c;
#	int cnt = 0;
#	while(1) {
#		c = inkey();
#		if( c == 'R' )
#			cnt = 0;
#		putChar('\r');
#		printInt(cnt, 10 | 3 << 16); // ver nota 3 na página seguinte
#		cnt = (cnt + 1) & 0xFF;
#		wait(4);
#	}
#	return 0;
#}
#void wait(int ts)
#{
#	int i;
#	for(i=0; i < 515000 * ts; i++); // wait approximately ts/10 seconds
#}


	.data

	.equ inkey, 1
	.equ putChar, 3
	.equ printInt, 6
	.text
	.globl main

main:			addi $sp, $sp, -4
				sw $ra, 0($sp)
					
				li $t2, 0				# $t2 = cnt



while:									# while(1)	
				li $v0, inkey			# 
				syscall					#
				move $t3, $v0			# c = inkey() $t3
				
				############### Extra
				beq $t3, '\n', end_while 
				###############
				
if:				bne $t3, 'R', endif		# if(c == 'R')
				li $t2, 0				# cnt = 0;
endif:
				li $v0, putChar			# 
				li $a0, '\r'			#
				syscall
				
				move $a0, $t2			# cnt como argumento 
				li $t4, 3				# $t4 = 3
				sll $t4, $t4, 16		# $t4 = 3 << 16
				or $t4, $t4, 10			# $t4 = 10 || 3 << 16
				move $a1, $t4
				li $v0, printInt		# printInt(cnt, 10 || 3 << 16)
				syscall
				
				addi $t2, $t2, 1		# cnt+1
				and $t2, $t2, 0xFF		# cnt = (cnt +1) & 0xff
				li $a0, 4				# wait(4)
				jal wait

				j while 				
end_while:
				li $v0, 0
				lw $ra, 0($sp)
				addi $sp, $sp, 4

				jr $ra

wait:			
				li $t0, 0			# i = 0;
				li $t1, 515000 		
				mul $t1, $t1, $a0	

for_wait:		bge $t0, $t1, endfor_wait
				addi $t0, $t0, 1
				j for_wait
endfor_wait:	jr $ra
