#include <stdio.h>
#
#int main(int argc, char *argv[]){
#	int countChars = 0;
#	int length = 0 ;
#	char* stringMaior;
#	int biggestChar = 0;
#	for(int i = 1; i< argc; i++){
#		int j = 0;
#
#		do{
#			if(argv[i][j] !='\0'){
#				length++;				
#				if(('a'<=argv[i][j]  && 'z'>=argv[i][j]) || ('Z'>=argv[i][j] && 'A' <=argv[i][j])) countChars++;
#			j++;
#			}  
#			
#}while(argv[i][j] != '\0');	
#	
#		if(biggestChar <length) {
#			stringMaior = argv[i]; 
#			biggestChar = length;			
#		
#		
#		}
#		printf("Numero de caracteres de (%s): %d\n", argv[i], length);	
#		printf("Numero de letras de (%s): %d\n", argv[i], countChars);
#	
#		length = 0;
#		countChars = 0;
#}
#	printf("String maior destas todas é: %s\n", stringMaior);
#		
#	 
#
#
#}
	.data 
str1:	.asciiz "Numero de caracteres de"
	.text
	.globl main
#Mapa de registros 
# i : $t0 / j : $t1 / countChars : $t2 / length : $t3 / stringMaior : $t4 / biggest : $t5 
  
main:	li $t0, 0 			# i = 0 
	li $t2, 0 			# countChars = 0 
	li $t3, 0 			# length = 0
	li $t5, 0 			# biggestChar = 0 
	move $t8, $a0	
for:	bge $t0, $t8, endf		#for(int i; i<argc; i++)
	li  $t1, 0			# j = 0	
	
	sll  $t6, $t0, 2		# $t6 = i *4
	addu $t6, $t6, $a1		# $t6 = argv + i*4
	lw   $t6, 0($t6)
			# $t6 = *(argv + i*4)
do:
if1:	addu $t9, $t6, $t1		# $t6 = *(argv + i*4) + j	
	lb $t7, 0($t9)	
				# $t7 = *($t6)	
	beq $t7, $0, endif1		#if ( argv[i][j] != '\0')
	addi $t3, $t3,1			# length++ 	
	
if2:	
or1:	blt $t7, 'a', or2		# argv[i][j] < 'a' o and fica estragado 
	bgt $t7, 'z', or2 		# argv[i][j] < 'z' o and dá 0 resta o lado direito do or
	addi $t2, $t2, 1			
or2:	blt $t7, 'A', endif2		#
	bgt $t7, 'Z', endif2		#
	addi $t2,$t2, 1			#
	
endif2:

	addi $t1, $t1, 1
endif1:
while:	bne $t7, '\0', do

if3: 	bge $t5, $t3, endif3
	move  $t4, $t6
	move $t5, $t3
	
endif3:
	li $v0, 4
	la $a0, str1
	syscall
	li $v0, 11
	li $a0, ' '
	syscall
	li $v0, 11
	li $a0, '"'
	syscall
	move $a0, $t6	
	li $v0, 4	
	syscall 
	li $v0, 11
	li $a0, '"'
	syscall
	li $v0, 11
	li $a0, ','
	syscall
	li $v0, 11
	li $a0, ' '
	syscall
	li $v0, 1
	move $a0, $t3
	syscall
	li $v0, 11
	li $a0, ' '
	syscall
	li $v0, 1
	move $a0, $t2
	syscall
	li $v0, 11
	li $a0, ' '
	syscall

	li $t3, 0
	li $t2, 0 
	addi $t0, $t0, 1		# i++
	
	li $v0, 11
	li $a0, '\n'
	syscall
	
	j for 	
endf:
	li $v0, 4
	move $a0, $t4
	syscall
	jr $ra

