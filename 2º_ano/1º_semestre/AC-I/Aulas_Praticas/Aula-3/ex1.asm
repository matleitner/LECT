	.data
str1: 	.asciiz "Introduza um numero: "
str2:   .asciiz  "Valor ignorado\n"
str3: 	.asciiz "A soma dos positivos é: "

#Mapa de registros:
# soma : $t0
# value: $t1
# i:     $t2	
	.eqv print_string, 4
	.eqv read_int, 5
	.eqv print_int10,1		
	.text
	.globl main
main:	li  $t0, 0
	li $t2, 0
for:    bge $t2, 5, endfor #while(i<0)
	la $a0, str1
	li $v0, print_string
	syscall # print_str(str1)
 	
 	li $v0, read_int
 	syscall
 	
 	move $t1, $v0  #value = read_int()
 	
	 	
if:	ble $t1, $0, else

	add $t0,$t0, $t1  #soma +=value
		
	j endif

else: 	la $a0, str2
	li $v0, print_string
	syscall
	j endif	

endif: addi $t2,$t2, 1 # i ++
	j for
endfor:
	la $a0, str3
	li $v0, print_string
	syscall
	or $a0, $0, $t0
	li $v0, print_int10
	syscall
	jr $ra