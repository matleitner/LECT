
        .data
        .equ 1, UP
        .equ 0, DOWN
        .equ 3, putChar
        .equ 6, printInt
        .equ 1, inkey
        .text
        .globl main

main:       addiu   $sp, $sp, -4
            sw      $ra, 0($sp)


            lw      $ra, 0($sp)
            addiu   $sp, $sp, 4
            jr $ra


timeDone:
            li      $t0, 0
if_rst:     ble	    $a1, $0, else_reset	# if $t0 <= $t1 then goto target
            li      $v0, resetCoreTimer
            syscall
            move    $v0, $t0
        
            j endif_rst

else_rst:  
            li      $v0, readCoreTimer
            syscall
            move    $t5, $v0
if_curCnt:  mul     $t3, $a0, 20000
            ble     $t5, $t3, endif_curCnt
            div	    $t5, 20000		
            mflo    $v0
endif_curCnt:
endif_rst:  
            

            jr $ra
