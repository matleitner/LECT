	.data
AA:	.asciiz "#F47D3FA2"	# 10 bytes 1001003c
BB:	.word   5		# 4 -> 14  1001003c + 12 -> 10010048
CC:	.word   0x52, 0x126C, 0x3A, 0x139A8, 0xABA, 0x7C38 # 4 * 6 -> 38  10010048 + 4 = 1001004c      
	.align  2		# 40
DD:	.space  4		# 44

	.text
	.globl  main

main:   la      $t0, CC	# 00400038   li = lui -> ori + 8  +1448 
        la      $t1, BB	#00400040   $t0 = &CC 
        lw      $t1, 0($t1)	#00400048  
        sll     $t1, $t1, 2	#0040004c
        addu    $t1, $t0, $t1	#00400050    $t1 = 1001004c + 5 * 4 = 50 + 10 = 10010060   
        xor     $t2, $t2, $t2	#00400054    $t2 = 0

L1:     lw      $t3, 0($t0)	#00400058    $t3 = CC[i]
        lw      $t4, 0($t1)	#0040005c    $t4 = CC[5-i]
        sw      $t3, 0($t1)	#00400060    cc[5-i] = CC[i] 
        sw      $t4, 0($t0)	#00400064    CC[i] = CC[5-i] 
        andi    $t4, $t4, 0x0F	#00400068    $t4 = CC[5-i] and 0x0F
        add     $t2, $t2, $t4	#0040006c    $t2 = ultimo byte de CC[5-i]
        addiu   $t0, $t0, 4	#00400070    i++
        addiu   $t1, $t1, -4	#00400074    j--
        blt     $t0, $t1, L1	#00400078     while(&CC < &CC[5-i]) -> slt 0040007c -> bne 00400080 

L2:     la      $t5, DD	#00400080 
        sw      $t2, 0($t5)
        la      $t3, AA
        lw      $v0, 0($t3)
        jr      $ra



# 0x52, 0x126C, 0x3A, 0x139A8, 0xABA, 0x7C38
# 4c    50       54     58       5c    60
# 


# DD no final é 8 + A + 8 = 1A 
