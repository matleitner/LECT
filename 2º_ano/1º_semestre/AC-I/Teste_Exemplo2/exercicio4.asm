	.data
AA:	.asciiz "#F47D3FA2"
BB:	.word   5
CC:	.word   0x52, 0x126C, 0x3A, 0x139A8, 0xABA, 0x7C38
	.align  2
DD:	.space  4

	.text
	.globl  main

main:   la      $t0, CC
        la      $t1, BB
        lw      $t1, 0($t1)
        sll     $t1, $t1, 2
        addu    $t1, $t0, $t1
        xor     $t2, $t2, $t2

L1:     lw      $t3, 0($t0)
        lw      $t4, 0($t1)
        sw      $t3, 0($t1)
        sw      $t4, 0($t0)
        andi    $t4, $t4, 0x0F
        add     $t2, $t2, $t4
        addiu   $t0, $t0, 4
        addiu   $t1, $t1, -4
        blt     $t0, $t1, L1

L2:     la      $t5, DD
        sw      $t2, 0($t5)
        la      $t3, AA
        lw      $v0, 0($t3)
        jr      $ra
