	.data
	.eqv SIZE, 20
str:	.space 21
str1:	.asciiz "Introduza uma string: "
	
	.eqv print_string, 4
	.eqv read_string, 8
	.text
	.globl main
#Mapa de registros:
#p : $t0 /  
main:	la $t0, str 		#$t0 = p 
	li $v0, print_string	#print_string
	la $a0, str1		#
	syscall			#
				
	li $v0, read_string	# read_string
	la $a0, str		# buff
	li $a1, SIZE		# length
	syscall			#
	 
	la $t0, str		# p = str
	

while:	lb $t1, 0($t0)		# *p 
	beq $t1, '\0', endw	#while( *p != '\0' )
	addi $t1, $t1, -0x61	# *p = *p - 'a'
	addi $t1, $t1,  0x41	# *p = *p - 'a' + 'A'
	addi $t0,$t0,1		#  p++
	j while			#
endw:
	li $v0, print_string	# print_string
	la $a0, str		#
	syscall			#
	jr $ra			# end
