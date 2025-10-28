	.data
	.eqv print_int10, 1
str:	.asciiz "Arquitetura de Computadores I"
	.text
	.globl main
	
	
main:	la $a0, str
	
	jal strlen
	
	move $a0, $v0 
	li $v0, print_int10
	syscall

	
strlen:	li $t1, 0 	  # len = 0;

while:	lb $t0, 0($a0) 	  # while(*s++!= '\0') leitura
	
	addiu $a0, $a0, 1  # incremento
	
	beq $t0,'\0', endw # comparação
	
	addi $t1, $t1, 1	  # len++;
	
	j while
	
endw:	move $v0, $t1
	
	jr $ra 

	