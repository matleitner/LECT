	.data
question_prompt:	.asciiz "Introduza 2 numeros "
answer:	.asciiz "\nA soma dos dois numeros e': "
	.eqv print_string, 4
	.eqv print_int, 1
	.eqv read_int, 5
	.text
	.globl main
#ORI so funciona com constantes (imidiate)

main:	#print
	la $a0, question_prompt #$a0 = "Introduza 2 numeros"
	ori $v0,$0, print_string #$v0 = 4 
	syscall 
	
	#read int a stored at $t0 
	ori $v0, $0, read_int #$v0 = 5
	syscall
	or $t0, $v0, $0 #$t0 = input
	
	#read int b stored at $t1
	ori $v0, $0, read_int
	syscall
	or $t1, $v0, $0
	
	#print anwser
	la $a0, answer
	ori $v0,$0, print_string
	syscall
	
	add $t2, $t0, $t1
	
	or $a0,$0, $t2
	ori $v0,$0, print_int
	syscall
	
	jr $ra
	