	.data
soma:	.float 0.0
	.eqv SIZE, 10
	.align 3
arr:	.space 80
	.eqv read_double,7
	.eqv print_double, 3
	
	.text
	.globl main

var:	addiu $sp, $sp, -16
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)
	sw $s2, 12($sp)
	move $s0, $a0		#s0 = double *array
	move $s1, $a1		#s1 = nval
	
	
	jal average 
	cvt.s.d $f2,$f0 		# $f2 = average(array,nval) 	
	li $s2, 0		# i $t4
	la $t1, soma
	l.s $f4, 0($t1)		
for7:	bge $s2, $s1, endfor7
	sll $t5, $s2, 3
	addu $t6, $s0, $t5
	l.d $f6, 0($t6)
	cvt.s.d $f6, $f6
	sub.s  $f12, $f6, $f2 
	
	
	li $a0, 2
	jal xtoy
	add.s $f4, $f4, $f0	
	addi $s2, $s2, 1
	j for7
endfor7:	
	cvt.d.s $f4 ,$f4
	mtc1    $s1, $f8
	
 	cvt.d.w $f8, $f8
	
	div.d $f0, $f4, $f8
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	lw $s2, 12($sp)
	addiu $sp, $sp, 16
	jr $ra
	
stdev:	addiu $sp, $sp, -12
	sw $ra, 0($sp)
	sw $s0, 4($sp)
	sw $s1, 8($sp)
	move $s0, $a0
	move $s1, $a1
	
	jal var
	mov.d $f12, $f0
	jal sqrt
	
	lw $ra, 0($sp)
	lw $s0, 4($sp)
	lw $s1, 8($sp)
	addiu $sp, $sp, 12
	jr $ra
	
	
main:
    addiu $sp, $sp, -16
    sw    $ra, 12($sp)
    sw    $s0, 8($sp)
    sw    $s1, 4($sp)

    li    $s0, 0          # index i
    la    $s1, arr        # $s1 = base do array
    li    $s2, SIZE

for_main:
    bge   $s0, $s2, endfor_main

    sll   $t8, $s0, 3     # offset = i * 8
    addu  $t8, $s1, $t8   # endereço = base + offset

    li    $v0, read_double
    syscall               # read_double -> $f0

    s.d   $f0, 0($t8)     # grava double corretamente

    addi  $s0, $s0, 1
    j     for_main
endfor_main:

    # --- imprimir average ---
    la    $a0, arr
    li    $a1, SIZE
    jal   average         # average retorna double em $f0
    mov.d $f12, $f0
    li    $v0, print_double
    syscall
    li $v0, 11
    li $a0, '\n'
    syscall
    # --- imprimir variance (ou var) ---
    la    $a0, arr
    li    $a1, SIZE
    jal   var             # var retorna double em $f0
    mov.d $f12, $f0
    li    $v0, print_double
    syscall
    li $v0, 11
    li $a0, '\n'
    syscall
    # --- imprimir stdev ---
    la    $a0, arr
    li    $a1, SIZE
    jal   stdev           # stdev retorna double em $f0
    mov.d $f12, $f0
    li    $v0, print_double
    syscall
    li $v0, 11
    li $a0, '\n'
    syscall
    
    li    $v0, 0

    lw    $ra, 12($sp)
    lw    $s0, 8($sp)
    lw    $s1, 4($sp)
    addiu $sp, $sp, 16
    jr    $ra