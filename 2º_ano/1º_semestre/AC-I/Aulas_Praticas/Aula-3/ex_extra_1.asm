	.data
str1:	.asciiz "Introduza um número: "
str2:	.asciiz "\nValor em código de Gray: "
str3:	.asciiz "\nValor em código Binário: " 	
	.eqv print_string, 4
	.eqv print_int16, 34
	
	.eqv read_int,5 
	
	.text
	.globl main
	
#gray = $t0
#bin = $t1
#mask = $t2
main:	la $a0, str1
	li $v0, print_string
	syscall #print string intro
	li $v0, read_int
	syscall #read int 
	or $t0, $zero, $v0 # grey($t0) = read_int()
	srl $t2, $t0, 1 # mask($t2) = read_int >> 1 
	or $t1, $t2, $zero # bin ($t1) = grey
while: 	beq $t2, 0, endw
	xor $t1, $t1,$t2
	srl $t2, $t2, 1
	j while

endw:	#printar string  gray:
	la $a0, str2
	li $v0, print_string
	syscall
	#printar numero em gray
	li $v0, print_int16
	or $a0, $0,$t0
	syscall
	#printar string binario:
	la $a0, str3
	li $v0, print_string
	syscall
	#printar numero binario 
	li $v0, print_int16
	or $a0, $0, $t1
	syscall
	
	jr $ra  