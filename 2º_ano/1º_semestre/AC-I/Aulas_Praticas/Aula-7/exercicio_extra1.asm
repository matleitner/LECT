	.data
array:	.space 200
	.eqv print_string, 4
	.eqv print_int10, 1
	.eqv read_int, 5
	
str0:	.asciiz "Size of array :"
str1:	.asciiz "array["
str2:	.asciiz "] = "
str3:	.asciiz "Enter the value to be inserted: "
str4:	.asciiz "Enter the position: "
str5:	.asciiz "\nOriginal array: "
str6:	.asciiz "\nModified array: "

	.text
	.globl main 

# Mapa de registos	
# salvaguardar para $a0, $a1, $a2, 
# i : $t0
# array[] : $t1
# array_size : $t2
# insert_value : $t3
# insert_pos : $t4

insert:
    move $t5, $a3        # i = size
loop_ins:
    ble  $t5, $a2, done_shift
    sll  $t6, $t5, 2     # i * 4
    addu $t6, $t6, $a0   # &array[i]
    lw   $t7, -4($t6)    # carregar array[i-1]
    sw   $t7, 0($t6)     # guardar em array[i]
    addiu $t5, $t5, -1   # i--
    j    loop_ins
done_shift:
    sll  $t6, $a2, 2     # pos * 4
    addu $t6, $t6, $a0   # &array[pos]
    sw   $a1, 0($t6)     # array[pos] = value
    jr   $ra
    
print_array:
    move $t5, $a0
    li   $t6, 0          # i = 0
loop_prt:
    bge  $t6, $a1, end_prt
    lw   $a0, 0($t5)     # carregar valor
    li   $v0, print_int10
    syscall
    
    li   $v0, 11         # imprimir caractere (espaço)
    li   $a0, ' '
    syscall
    
    addiu $t5, $t5, 4    # próximo endereço
    addiu $t6, $t6, 1    # i++
    j    loop_prt
end_prt:
    jr   $ra
    
    	
    			
main:	addiu $sp, $sp, -4
	sw $ra, 0($sp)
	
	li $v0, print_string
	la $a0, str0 
	syscall
	
	li $v0, read_int
	syscall 
	move $t2, $v0
	
	la $t1, array
	
	li $t0, 0
	
	
for:	bge $t0, $t2, endfor
	
	li $v0, print_string
	la $a0, str1
	syscall 
	
	li $v0, print_int10 
	move $a0, $t0
	syscall
	
	li $v0, print_string
	la $a0, str2
	syscall
	
	sll $t3, $t0, 2
	
	addu $t3, $t1, $t3 
	
	li $v0, read_int
	syscall
	
	sw $v0, 0($t3)
	
		 
	addiu $t0,$t0, 1
	j for
endfor:	
	li $v0, print_string 
	la $a0, str3
	syscall
	
	li $v0, read_int
	syscall
	
	move $t3, $v0
	
	li $v0, print_string
	la $a0, str4
	syscall
	
	li $v0, read_int
	syscall
	
	move $t4, $v0
	
	li $v0, print_string
	la $a0, str5
	syscall
	
	move $a0, $t1
	move $a1, $t2 
	jal print_array
	
	move $a0, $t1
	move $a1, $t3
	move $a2, $t4
	move $a3, $t2
	
	jal insert
	li $v0, print_string
	la $a0, str6
	syscall
	
	move $a0, $t1
	addiu $a1, $t2, 1
	jal print_array
	
	li $v0, 0
	lw $ra, 0($sp)
	addiu $sp, $sp, 4 
	
	jr $ra
	
#array[] : $t1
# array_size : $t2
# insert_value : $t3
# insert_pos : $t4

	
 
	
	
	