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
#$t3 = 0x80000000
#$t4 resto de $t2 por 4
#$t5 = ands..
#$t6 = flags
	
	
main: 		li $t2, 0 #i = 0	
	
		la $a0, str1
		li $v0, print_string
		syscall #print(str)
	
		li $v0, read_int
		syscall #read_int()
		or $t0, $0, $v0   #value = $t0
		
		la $a0, str2
		li $v0, print_string
		syscall #print string 2
		li $t6, 0 #flag = 0
		
for: 		bge $t2, 32, endfor # if i >= 32 
		srl $t1,$t0, 31 # $t1 que é o bit= value ($t0)>> 31  
		rem $t4, $t2,4
		
if_flag:	bne $t6, 0, if_rest
		beq $t1, 0, else_flag # if bit != 0
		li $t6,1 #flag = 1

if_rest:	
		bne $t4, 0, next_step #if $t4 que é o i%4 != 0 vai para o next step
		li $a0, 32
		li $v0, print_char
		syscall #print char
next_step:
		li $t3, 0x30#$t3 = 0x30
		add $t5, $t1, $t3
		or $a0, $t5, $0
		li $v0, print_char
		syscall
		
	

else_flag: 	
		sll $t0, $t0,1
		addi $t2, $t2, 1
		j for 
endfor: 	
	jr $ra
