	.data
str1:	.asciiz "Introduza um número "
str2:	.asciiz "\nO valor em binário é:"
#char1:	.byte '1'
#char2:	.byte '0' 
	
	.eqv print_string, 4
	.eqv print_char, 11
	.eqv read_int, 5
	.text
	.globl main
	
#$t0 = value readint
#$t1 = bit 
#$t2 = i 

main: 	li $t2, 0
	la $a0, str1
	li $v0, print_string
	syscall
	
	li $v0, read_int
	syscall
	or $t0, $0, $v0
	la $a0, str2
	li $v0, print_string
	syscall
		
for: 	bge $t2, 32, endfor
	li $t3, 0x80000000
	and $t1, $t0, $t3
	#addi $t5, $t2,1 
	rem $t4, $t2, 4
ifdiv4: bne $t4, 0, if
	beq $t2, 0, if
	li $a0, 32
	li $v0, print_char
	syscall
	
if:	beq $t1,0,else
	li $v0, print_char
	li $a0, '1'
	syscall
	j endif
else:	 
	li $v0, print_char
	li $a0, '0'
	syscall
	j endif
	
endif: 	sll $t0, $t0,1
	addi $t2,$t2,1
	j for
	

endfor:
	
	jr $ra
