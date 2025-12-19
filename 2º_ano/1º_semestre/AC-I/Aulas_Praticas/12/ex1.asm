#	student	alinhamento 	dimensão	offset
#	id_number	     4              4	   0
#	first_name[18]        1             18	   4
#	last_name[15]         1 	  15	  22
#	grade (float)         4	   4              37->40
			 #44   
	.data
	
	.eqv MAX_STUDENTS, 4
str1:	.asciiz "N. Mec:"
str2:	.asciiz "Primeiro Nome: "
str3:	.asciiz "Ultimo Nome: "
str4:	.asciiz "Nota: "
str_main:	.asciiz "\nMedia: "
media:	.float 7
 	.align 2 
st_array:	.space 176
	.align 2
#p:	.space 44
#pmax:	.space 44	
	.eqv print_string, 4
	.eqv read_string, 8
	.eqv read_int, 5
	.eqv read_float, 6
	.eqv print_intu10, 1
	.eqv print_float, 2
	.text
	.globl main

read_data:	addiu $sp, $sp, -12
	sw $ra, 0 ($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)
	move $s0, $a0
	move $s1, $a1
	
	# student *st -> $a0 / int ns -> $a1 / 
	# i : $t0 / 
	li $t0, 0
for_read_data:	bge $t0, $s1, endfor_read_data
	mul $t1, $t0, 44
	addu $t1, $t1, $s0
	#$t1 = st[i] 
	#Nº mec
	
	li $v0, print_string
	la $a0, str1
	syscall
	li $v0, read_int 
	syscall
	sw $v0, 0($t1)		# offset 0 => st.id_number
	#First name
	li $v0, print_string
	la $a0, str2
	syscall
	
	li $v0, read_string
	addi $a0, $t1, 4		# offset 4 => st.first_name 
	li   $a1, 18
	syscall
	
	#Last name
	li $v0, print_string
	la $a0, str3
	syscall 
	li $v0, read_string
	addi $a0, $t1, 22	# offset 22 => st.last_name 
	li   $a1, 15
	syscall
	#Nota 
	li $v0, print_string
	la $a0, str4
	syscall
	
	li $v0, read_float
	syscall
	s.s $f0,  40($t1)
	addi $t0, $t0, 1
	
	j for_read_data
endfor_read_data:

	lw $ra, 0 ($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	addiu $sp, $sp, 12
	jr $ra 
	
#         student *max(student *st, int ns, float *media)

#         Mapade registros p : $t0 / pmax : $t3 / max_grade : $f2 / sum _ $f4 / $t2 : ns + st / 
max:	addiu $sp, $sp, -16 
	
	sw $ra, 0($sp)
	sw $s0, 4($sp)		#$s0->$a0	st
	sw $s1, 8($sp)		#$s1->$a1	ns
	sw $s2, 12($sp)		#$s2->$a2	media
	move $s0, $a0
	move $s1, $a1
	move $s2, $a2	
	
	move $t0, $s0		# student *p
	li $t1, -20		
	mtc1 $t1, $f2		# max_grade = -20
	cvt.s.w $f2, $f2
	mtc1 $0, $f4		# sum = $f4 
	mul $t2, $s1, 44
	add $t2, $t2, $s0	# st + ns 
for_max:	bge $t0, $t2, endfor_max	# p<(st+ns)
	
	l.s $f6, 40($t0)
	add.s $f4, $f4, $f6 
if_max: 	c.lt.s  $f2, $f6
	bc1f endif_max
	mov.s $f2, $f6
	move $t3, $t0
endif_max:
	addi $t0, $t0, 44
	j for_max
endfor_max:	
	mtc1 $s1, $f8
	cvt.s.w $f8, $f8
	div.s $f8, $f4, $f8
	s.s $f8, 0($s2)
	move $v0, $t3
	lw $ra, 0 ($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	lw $s2, 12($sp)
	addiu $sp, $sp, 16
	
	jr $ra
	
print_student:	
	addiu $sp, $sp, -8
	sw $ra, 0 ($sp)
	sw $s0, 4($sp)
	
	move $s0, $a0
	li $v0, 11 
	li $a0, '\n'
	syscall
	lw $a0, 0($s0) 
	li $v0, print_intu10
	syscall
	
	li $v0, 11 
	li $a0, '\n'
	syscall
	
	addi $a0, $s0, 4
	li $v0, print_string
	syscall
	 
	li $v0, 11 
	li $a0, '\n'
	syscall
	 
	addi $a0, $s0, 22
	li $v0, print_string 
	syscall
	
	li $v0, 11 
	li $a0, '\n'
	syscall
	
	
	li $v0, print_float
	l.s $f12, 40($s0)
	syscall
	
	
	li $v0, 11 
	li $a0, '\n'
	syscall
	lw $ra, 0 ($sp)
	lw $s0, 4($sp)
	
	addiu $sp, $sp, 8
	jr $ra						
	
main:	addiu $sp, $sp, -4
	sw $ra, 0($sp)

	la $a0, st_array
	li $a1, MAX_STUDENTS
	jal read_data
	
	la $a2, media
	li $a1, MAX_STUDENTS
	la $a0, st_array
	jal max
	move $t5, $v0
	
	li $v0, print_string
	la $a0, str_main
	syscall
	
	l.s  $f12, 0($a2) 
	li $v0, print_float
	syscall
	li $v0, 11 
	li $a0, '\n'
	syscall
	move $a0, $t5
	jal print_student
	li $v0, 0	
	lw $ra, 0($sp)
	addiu $sp, $sp, 4
	
	jr $ra
	
	 
