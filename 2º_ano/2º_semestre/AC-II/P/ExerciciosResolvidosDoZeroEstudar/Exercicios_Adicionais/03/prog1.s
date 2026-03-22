        .data   
        .equ    0xBF88, ADDR_BASE_HIGH
        
        .equ    0x6040, TRISB
        .equ    0x6050, PORTB
        .equ    0x6060, LATB

        .equ    0x6100, TRISE
        .equ    0x6110, PORTE
        .equ    0x6120, LATE


        .text
        .globl main

main:   lui     $t0, ADDR_BASE_HIGH

        lw      $t1, TRISB($t0)
        ori     $t1, $t1, 0x000F        # 1 entrada
        sw      $t1, TRISB($t0)

        lw      $t1, TRISE($t0)
        andi    $t1, $t1, 0xFFC3        # 11 00 0011
        sw      $t1, TRISE($t0)         

while:  lw      $t1, PORTB($t0)
        
        andi    $t2, $t1, 0x0001
        xori	$t2, $t2, 0x0001		
        sll     $t2, $t2, 2

        andi    $t3, $t1, 0x0002
        sll     $t3, $t3, 2
        
        
        or      $t2, $t2, $t3

        andi    $t4, $t1, 0x0004
        sll     $t4, $t4, 2

        or      $t2, $t2, $t4
        
        andi    $t5, $t1, 0x0008
        xori    $t5, $t5, 0x0008
        sll     $t5, $t5, 2

        or      $t2, $t2, $t5
        lw      $t1, LATE($t0)
        andi    $t1, $t1, 0xFFC3        #    1100 0011
        or      $t2, $t1, $t2 
        sw      $t2, LATE($t0)

        j       while
###        OU      ###
while1:
        lw      $t1, PORTB($t0)

        andi    $t1, $t1, 0x000F
        xori    $t1, $t1, 0x0009

        sll     $t2, $t1, 2

        lw      $t1, LATE($t0)
        andi    $t1, $t1, 0xFFC3        #    1100 0011
        or      $t2, $t1, $t2 
        sw      $t1, LATE($t0)

        jr      $ra
