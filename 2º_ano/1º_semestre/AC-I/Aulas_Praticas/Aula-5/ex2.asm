	
	.data

lista:	.word	8,-4, 3, 5, 124, -15, 87, 9, 27, 15 # a diretiva ".word" alinha num endereço 
						    # múltiplo de 4	
str1:	.asciiz "\nConteudo do array:\n"
str2:	.asciiz "; "
	.text
	.eqv SIZE, 10
	.eqv print_string, 4
	.eqv print_int10, 1
	.globl main 
	
main:	li  $v0, print_string
	la  $a0, str1
	syscall			#print_string
	la  $t0, lista 		# p = lista
	li  $t3, SIZE  		# auxiliar para o addu $t2 = lista + SIZE
	sll $t3, $t3,2		# $t3 = $t3 * 4
	addu $t2, $t0, $t3	#$t2 = lista + SIZE ( $t3) 
while:	bgeu $t0,$t2,endw	# while( p < lista + SIZE){
	lw $t1, 0($t0)		# $t1 = *p
	
	#print int 10
	
	li $v0, print_int10	
	or $a0, $t1, $0 
	syscall
	
	#print string 
	
	li $v0, print_string
	la $a0, str2
	syscall
	
	addiu $t0, $t0, 4
	j while
endw:	jr $ra
# Mapa de registos
# p: $t0
# *p: $t1 (Registo temporário para guardar o valor
# armazenado em memória)
# lista+Size: $t2 

