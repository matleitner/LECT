# int main
# {
# 	int value 
# 	while(1) {
#			printStr("\nIntroduza um inteiro (sinal e módulo): ");
#			value = readInt10();
#			printStr("\nValor em base 10 (signed): ");
#			printInt10(value);
#			printStr("\nValor em base 2: ");
#			printInt(value, 2);
#			printStr("\nValor em base 2, formatado: ");
#			printInt(value, 2 | 32 << 16);
#			printStr("\nValor em base 16: ");
#			printInt(value, 16);
#			printStr("\nValor em base 10 (unsigned): ");
#			printInt(value, 10);
#			printStr("\nValor em base 10 (unsigned), formatado: ");
#			printInt(value, 10 | 5 << 16); // ver nota 3
# 	}
# 	return 0;
# }

		.data
		.equ printStr, 8
		.equ printInt10, 7
		.equ printInt, 6
		.equ readInt10, 5	
str:	.asciiz "\nInstroduza um inteiro (sinal e módulo): "
str1:	.asciiz "\nValor em base 10 (signed):"
str2:	.asciiz "\nValor em base 2:"
str3:	.asciiz "\nValor em base 2, formatado: "
str4:	.asciiz "\nValor em base 16: "
str5:	.asciiz "\nValor em base 10 (unsigned): "
str6:	.asciiz "\nValor em base 10 (unsigned), formatado: "
		.text

		.globl main

main:	

while:	li $v0, printStr
		la $a0, str
		syscall
			
		li $v0, readInt10
		syscall
		move $t0, $v0
		beq $v0, 69, end_while

		li $v0, printStr
		la $a0, str1
		syscall

	
		li $v0, printInt10
		move $a0, $t0
		syscall


		li $v0, printStr
		la $a0, str2
		syscall
		
		
		li $v0, printInt
		move $a0, $t0
		li $a1, 2
		syscall


		li $v0, printStr
		la $a0, str3
		syscall
		

		li $v0, printInt
		move $a0, $t0
		li $a1, 32
		sll $a1, $a1, 16
		or $a1, $a1, 2
		syscall

		li $v0, printStr
		la $a0, str4
		syscall
		

		li $v0, printInt
		move $a0, $t0
		li $a1, 16 
		syscall


		li $v0, printStr
		la $a0, str5
		syscall
		
		li $v0, printInt
		move $a0, $t0
		li $a1, 10 
		syscall
		

		li $v0, printStr
		la $a0, str6
		syscall


		li $v0, printInt
		move $a0, $t0
		li $a1,5 
		sll $a1, $a1, 16
		or $a1, $a1, 10
		syscall
		j while
end_while:

		li $v0, 0

		jr $ra

