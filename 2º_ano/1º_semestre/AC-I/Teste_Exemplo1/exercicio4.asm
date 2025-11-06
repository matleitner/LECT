#	Para facilitar análise! Pode abrir o "painel" do segmento de dados e de texto para analisar, na aba "Execute".

	.data			# 0x10010000
X1:	.asciiz	"TEST1"
	.align 	2
X2:	.space	20	#10000 + 8  8 9 A B C D E F 10 11 12 13 14 15 16 17 18 19 1A 1B 1C 1D	
X3:
	.text			# 0x00400000
	.globl	main
main:	la	$t4, X2
	li	$t8,2
	ori	$t5, $0, 4
	xor	$t0, $t0, $t0
	xor	$t1, $t1, $t1
L1:	beq	$t0, $t5, L2
	add	$t2, $t0, $t0
	add	$t3, $t2, $t2
	addu	$t3, $t3, $t4
	sw	$t2, 0($t3)
	add	$t1, $t1, $t2
	addi	$t0, $t0, 1
	j 	L1
L2:	sw	$t1, 4($t3)
	addiu	$t3, $t3, 4
	#li	$t7, 0x1001000C
	#lw 	$t7, 0($t7)
	#li	$v0, 1
	#move	$a0, $t7
	#syscall
	jr	$ra
