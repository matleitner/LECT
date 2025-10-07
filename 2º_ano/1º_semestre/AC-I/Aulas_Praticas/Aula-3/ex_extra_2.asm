	.data
	
str1: 	.asciiz "Introduza dois numeros: "
str2:	.asciiz "Resultado: "
	.eqv print_string, 4
	.eqv read_int, 5
	.eqv print_int10, 1
	.text
	.globl main
	
#res = $t0 
#i = $t1
#mdor = $t2 
#mdo = $t3

main:	li $t0, 0
	li $t1, 0
	li $v0, print_string
	la $a0, str1
	syscall #print str1
	
	li $v0, read_int
	syscall 
	
	li $t5, 0x0F
	and $t2, $t5, $v0 # mdor = $v0 and 0x0F
	li $v0, read_int  
	syscall
	
	
	and $t3, $t5, $v0 # mdo = new ($v0) and 0x0F
		
condition_while_a:	
	beq $t2, $0, endw # if $t2 mdor != 0 need to check the 2nd condition 
condition_while_b:	
	bge $t1,4, endw # if $t1 i is less than four we "do" whats in the whie
			
if:	li $t6, 0x00000001 # just puting hexa dec in a register
	and $t4,$t2, $t6   # mdor and 0x00000001
	beq $t4, $0, endif # if that and is equal to zero we dont do that add operation
	add $t0, $t0, $t3


endif:
	sll $t3, $t3,1 #mdo = mdo << 1
	srl $t2,$t2,1 # mdor = mdor>>1
	addi $t1,$t1,1	# i ++
	j condition_while_a # go again to the while conditions

endw:
	li $v0, print_string
	la $a0, str2
	syscall #print string resultado 
	
	li $v0, print_int10
	or $a0, $t0, $0
	syscall # print the result
	jr $ra
	
	