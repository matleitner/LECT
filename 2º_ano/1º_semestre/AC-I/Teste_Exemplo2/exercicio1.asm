##define SIZE 15
#
#int toi(char *);
#int avz(int *, int);
#
#int func1(int *fl, int k, char *av[])
#{
#    int i;
#    int res;
#
#    if ((k >= 2) && (k <= SIZE)) {
#        i = 2;
#        do {
#            fl[i] = toi(av[i]);
#            i++;
#        } while (i < k);
#        res = avz(fl, k);
#        print_int10(res);
#    } else {
#        print_string("Invalid argc");
#        res = -1;
#    }
#    return res;
#}

# Mapa de registos:
#	$a0->$s0 : int *fl
#	$a1->$s1 : int k
#	$a2->$s2 : char **av ou seja é um array de strings
#

	.data
	.eqv SIZE, 15
	.eqv print_string, 4
	.eqv print_int10, 1
str0:	.asciiz "Invalid argc"
	
	.text
	.globl func1 


func1:	addiu $sp, $sp, -24			# salva guardar os registos 
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)
	sw $s2, 12($sp)
	sw $s3, 16($sp)
	sw $s4, 20 ($sp)
	move $s0, $a0				# s1 -> pontiero p fl 
	move $s1, $a1 				# s2 -> k 
	move $s2, $a2				# s3 -> ponteiro p array de strings 


if:	blt $s1, 2, else		# if (((k >= 2) && (k <= SIZE)) {
	bgt $s1, SIZE, else	#

	li $s4, 2		#i = 2

do:									# do {
	# *av -> ponteiro p o char da primeira string, se for **av é o primeiro char 
	# da primeira string 
	
	sll $t1, $s4, 2		# $t1 : i * 4 
	addu $a0, $s2, $t1	# $a0 -> av+i*4
	 
	lw $a0, 0($a0)		# $a0 -> *(av+ i*4)
	jal toi		# fl[i] = toi(av[i]); 
	
	addu $s3, $s0, $t1	# fl[i]
	sw $v0, 0($s3) 		# 
	
	addiu $s4, $s4, 1	# i++
while:	blt $t0, $s1, do		#} while (i < k);
			
	move $a0, $s0		# 
	move $a1, $s1		#
	jal avz		# res = avz(fl, k);
	move $t3, $v0		# v0 -> t3 	
	move $a0, $t3		# 
	
	li $v0, print_int10 	# print_int10(res)
	syscall
	move $v0, $t3		# res = avz(fl, k);	
	j endif
else:			#} else {

	la $a0, str0		#
	li $v0, print_string 	#
	syscall		# print_string("Invalid argc"); 
	li $v0, -1		# res = -1
endif:
	
	lw $ra, 0($sp)
        	lw $s0, 4($sp)
        	lw $s1, 8($sp)
	lw $s2, 12($sp)
	sw $s3, 16($sp)
	sw $s4, 20 ($sp)
	addiu $sp, $sp, 24
	jr $ra
