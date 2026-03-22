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

            li      $t1, UP             # int state = UP;
            li      $t0, 0              # int cnt = 0;
do:         li      $v0, putChar        # putChar('\r')
            li      $a0, '\r'           #
            syscall

            li      $v0, printInt       #
            move    $a0, $t0            #
            li      $a1, 3              # 
            sll     $a1, $a1, 16        #
            or      $a1, $a1, 10        #
            syscall 

            li      $v0, putChar        # putChar('\r')
            li      $a0, '\r'           #
            syscall

            li      $v0, printInt       #
            move    $a0, $t0            #
            li      $a1, 2              # 
            sll     $a1, $a1, 16        #
            or      $a1, $a1, 8         #
            syscall

            li      $a0, 5              #
            jal     wait                #


            li      $v0, inkey          #
            syscall                     #

            move    $t2, $v0            #

if_1:       bne     $t2, '+', else_if
            li      $t1, UP
            j endif_1
else_if:    bne     $t2, '-', endif_1
            li      $t1, DOWN
endif_1:    

if_2:       bne     $t1, UP, else_2
            addi    $t0, $t0, 1
            andi    $t0, $t0, 0xFF

            j endif_2
else_2:     addi    $t0, $t0, -1
            andi    $t0, $t0, 0xFF
endif_2:

            bne     $t2, 'q', do

            li      $v0, 0
            syscall
            
            lw      $ra, 0($sp)
            addiu   $sp, $sp, 4
            jr      $ra



wait:       addiu   $sp, $sp, -8
            sw      $s0, 0($sp)
            sw      $s1, 4($sp)
        
            li      $s0, 0
        

for:        mul     $s1, $a0, 51500
            bge     $s0, $s1, endfor
            addi    $s0, $s0, 1
endfor:
            lw      $s0, 0($sp)
            lw      $s1, 4($sp)
            addiu   $sp, $sp, 8
            jr      $ra