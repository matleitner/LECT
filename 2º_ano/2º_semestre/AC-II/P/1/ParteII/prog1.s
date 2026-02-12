#int main(void)
#{
#	char c;
#	int cnt = 0;
#	do
#	{
#		c = getChar();
#		putChar( c );
#		cnt++;
#	} while( c != '\n' );
#	printInt(cnt, 10);
#	return 0;
#}

	.data
	.equ  getChar, 2
	.equ putChar, 3
	.equ printInt, 6
	.text
	.globl main

main:	li $t0, 0		# int cnt = 0;

do:		


		li $v0, getChar 	
		syscall
		
		move $a0, $v0
##		addi $a0, $a0, 1	# putChar(c+1)

		li $v0, putChar
		syscall
		
		addi $t0, $t0, 1	# cnt++;
		
while:	bne $a0, '\n', do

		li $v0, printInt
		move $a0, $t0
		li $a1, 10
		syscall

		li $v0, 0
		jr $ra
	
