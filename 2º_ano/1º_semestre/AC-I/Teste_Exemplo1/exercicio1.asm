#void main(void)
#{
#	int val, n = 0, min=0x7FFFFFFF, max=0x80000000;
#	
#	print_string("Digite até 20 inteiros (zero para terminar):");
#
#	do {
# 		val = read_int();
#		if (val != 0) {
#			if ( val > max)	
#				max = val;
#			if (val < min)
#				min = val;
#		}
#		n++;
#	} while( (n < 20) && (val != 0) );
#
#	print_string("Máximo/mínimo são: ");
#	print_int10(max);
#	print_char(':');
#	print_int10(min);
#}

#Mapa de registos
# val = $t0
# n = $t1
# min = $t2
# max = $t3
	.data
	.eqv print_string, 4
	.eqv read_int, 5
	.eqv print_int10, 1
	.eqv print_char, 11

str1:	.asciiz "Digite até 20 inteiros (zero para terminar):"
str2:	.asciiz "Máximo/mínimo são: "
	.text
	.globl main

main:	li $t2, 0x80000000	#max = 0x80000000
	li $t3, 0x7FFFFFFF	#min = 0x7FFFFFFF
	li $t1, 0		#n = 0
	li $v0, print_string	#print_string()
	la $a0, str1
	syscall

do:	li $v0, read_int	#read_int()
	syscall			#
	move $t0, $v0		#$t0 = val, read_int()
if1:	beq $t0, 0, else1	# if $t0 == 0 goto else  

if2:	ble $t0, $t2, if3	#if $t0 <= max goto if3
	or $t2, $t0,$0		# $t2 = $t0	
if3:	bge $t0, $t3, else1	# if $t0 >= $t3 goto else1 
	or $t3, $t0, $0		#$t3 = $t0

else1:	
	addi $t1, $t1, 1

while:  bge $t1, 20, endw	#se n>=20  acaba logo o while mas se n<20 é preciso verificar o val!=0
	bne $t0, 0, do		#val != 0 volta ao do
endw:
	li $v0, print_string
	la $a0, str2
	syscall
	li $v0, print_int10
	move $a0, $t2
	syscall
	li $v0, print_char
	li $a0, ':'
	syscall
	li $v0, print_int10
	move $a0, $t3
	syscall
	jr $ra
