	.data
	
	
	
	.eqv 	SIZE, 20
	.eqv 	read_string, 8
	.eqv 	print_int10, 1
str:	.space  21  #SIZE + 1 

	.text
	.globl main

#Mapa de registos
#num:	$t0
#i:	$t1
#str: 	$t2
#str+i:	$t3
#str[i]:$t4

main:	la 	$a0, str	#$a0 = &(str[0])
	li 	$a1, SIZE
	li 	$v0, read_string
	syscall			#read_string(str,SIZE)
	
	li	$t0, 0		#num = 0
	li	$t1, 0		#i = 0

while:				#while(str[i] != '\0'{
	la 	$t2, str	# $t2 = &(str[0])
	addu	$t3, $t2, $t1	# $t3 = &(str[i])
	
	lb	$t4, 0($t3)	# $t4 = str[i]
	
	beq $t4, '\0', endw

if:	blt $t4, '0', endif  			# if ( str[i] >= '0') 
	bgt $t4, '9', endif			# and (str[i] <= '9')
	addi $t0, $t0,1				# num ++
endif:	
	addi $t1, $t1, 1
	j while			#}
endw:
	move $a0, $t0
	li $v0, print_int10
	syscall
	jr $ra
	