	.data
str1:	.asciiz "Introduza um número "
str2:	.asciiz "\nO valor em binário é:"	
	
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
	syscall #print(str)
	
	li $v0, read_int
	syscall #read_int()
	or $t0, $0, $v0   #value = $t0
	la $a0, str2
	li $v0, print_string
	syscall
		
for: 	bge $t2, 32, endfor
	li $t3, 0x80000000
	and $t1, $t0, $t3
	#addi $t5, $t2,1 
	rem $t4, $t2, 4 #$t4 = $t2 % 4,resto 
	bne $t4, 0, next_step
	beq $t2, 0, next_step
	li $a0, 32  #ASCII ' '
	li $v0, print_char
	syscall
next_step:	li $t3, 0x80000000
		and $t1, $t0, $t3  #bit = 0x80000000 & value
		srl $t1, $t1, 31 #$t1 = bit >> 31
	
		ori $t1, $t1,0x30 # t1 = 0x30 + bit ($t1) 
		li $v0, print_char
		or $a0, $0, $t1
		syscall
		sll $t0, $t0, 1
		addi $t2,$t2,1
		j for
	

endfor:
	
	jr $ra
