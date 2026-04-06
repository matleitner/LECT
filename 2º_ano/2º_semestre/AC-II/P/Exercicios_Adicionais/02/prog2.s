        .data
        .equ 1000, ONE_SEC
        .equ 3, putChar

        .text
        .globl main

main:
        addiu   $sp, $sp, -4
        sw      $ra, 0($sp)

        li      $t0, 1          # reset = 1

loop:
        li      $a0, ONE_SEC    # ms = 1000
        move    $a1, $t0        # reset

        jal     timeDone

        beq     $v0, $0, no_print   # se 0 → ainda não passou tempo

        # passou 1 segundo → imprime '\n'
        li      $a0, '\n'
        li      $v0, putChar
        syscall

        li      $t0, 1          # reset = 1
        j       loop

no_print:
        li      $t0, 0          # reset = 0
        j       loop


        lw      $ra, 0($sp)
        addiu   $sp, $sp, 4
        jr      $ra


timeDone:
            li      $v0, 0
if_rst:     ble	    $a1, $0, else_reset	# if $t0 <= $t1 then goto target
            li      $v0, resetCoreTimer
            syscall
            li      $v0, 0
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
