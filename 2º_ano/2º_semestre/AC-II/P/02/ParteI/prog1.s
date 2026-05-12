#int main(void)
#{
#	int counter = 0;
#	while(1)
#	{
#		putChar('\r');	// cursor regressa ao inicio da linha no ecrã
#		printInt(counter, 10 | 4 << 16);
#		resetCoreTimer();
#		while(readCoreTimer() < 200000);
#		counter++;
#	}
#	return 0;
#}
# 1 
# a) tempo de  200 000 ticks sabendo que em 1s 20 000 0000 de ticks = 0,01 s, logo
# freq = 100Hz 

# b)
		.data
		.equ putChar, 3
		.equ printInt, 6
		.equ resetCoreTimer, 12
		.equ readCoreTimer, 11
		.text
		.globl main

main:	
		li $t0, 0				# int counter = 0;

while1:							# while(1)
		li $a0, '\r'		
		li $v0, putChar			# putChar('\r');
		syscall

		move $a0, $t0		
		li $a1, 4	
		sll $a1, $a1, 16
		or $a1, $a1, 10			# 10 | 4 << 16
		li $v0, printInt		# printInt(counter, 10 | 4 << 16 )
		syscall
		
		## Explicação mete num de digitos para os 16 bits mais significativos
		## e meter 10 nos 16 menos significativos


		li $v0, resetCoreTimer	# resetCoreTimer();
		syscall

while2:	li $v0, readCoreTimer	# readCoreTimer();
		syscall
		
		li $t1, 200000
		bge $v0, $t1, endwhile2	# while(readCoreTimer()< 200000){


		j while2

endwhile2:

		addi $t0, $t0, 1 		# counter++;

		j while1
endwhile1:

		li $v0, 0

		jr $ra

# c) 10Hz  T = 1 / 10 = 0.1  1 s - 20M ticks | 0.1 - 2M ticks    $t1 =  2 000 000
#    1 / 5Hz = 0.2         1s -> 20M ticks | 0.2s -> $t1 :  
# 									$t1 = 0.2 * 20M / 1 :  
#	 5Hz $t1= 4.000.000 ticks
# 	 1 Hz       $t1 = 20.000.000 
