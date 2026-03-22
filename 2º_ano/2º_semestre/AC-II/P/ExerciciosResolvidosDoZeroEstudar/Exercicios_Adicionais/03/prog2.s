        .data
        .equ    0xBF88, ADDR_BASE_HIGH
        
        .equ    0x6040, TRISB
        .equ    0x6050, PORTB
        .equ    0x6060, LATB

        .equ    0x60C0, TRISD
        .equ    0x60D0, PORTD
        .equ    0x60E0, LATD
    

        .equ    0x6100, TRISE
        .equ    0x6110, PORTE
        .equ    0x6120, LATE

        .text

        .globl main


main:   addiu   $sp, $sp, -8
        sw      $ra, 0($sp)
        sw      $s0, 4($sp)
        li      $s0, 0

        lui     $t0, ADDR_BASE_HIGH
        
        lw      $t1, TRISD($t0)
        andi    $t1, $t1, 0xFFFE
        sw      $t1, TRISD($t0)
        
        lw      $t1, TRISE($t0)
        andi    $t1, $t1, 0xFFFE
        sw      $t1, TRISE($t0)
while:

        lw      $t1, LATE($t0) 
        andi    $t1, $t1, 0xFFFE
        or      $t1, $t1, $s0
        sw      $t1, LATE($t0)

        lw      $t3, LATD($t0)
        andi    $t3, $t3, 0xFFFE
        or      $t3, $t3, $s0
        sw      $t3, LATD($t0)
        

        ##      Para a a)
        #li      $a0, 500
        #jal     delay
        ##

        li      $v0, resetCoreTimer
        syscall

wait:   li      $v0, readCoreTimer
        syscall

        blt     $v0, 214000, wait



        xori    $s0, $s0, 0x0001    
        j       while


        lw      $ra, 0($sp)
        lw      $s0, 4($sp)
        addiu   $sp, $sp, 8

        jr $ra

delay:  
        li      $v0, resetCoreTimer
        syscall

Wdelay: li      $v0, readCoreTimer
        syscall
        mul     $t5, $a0, 20000
        blt     $v0, $t5, Wdelay 
        jr      $ra