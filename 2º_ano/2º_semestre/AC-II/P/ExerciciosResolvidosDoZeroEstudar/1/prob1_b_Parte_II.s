#int main(void)
#{
#    char c;
#    int cnt = 0;
#    while(1) {
#        c = inkey();
#        if( c == 'R' )
#            cnt = 0;
#        putChar('\r');
#        printInt(cnt, 10 | 3 << 16); // ver nota 3 na página seguinte
#        cnt = (cnt + 1) & 0xFF;
#        wait(4);
#    }
#    return 0;
#}
#void wait(int ts)
#{
#    int i;
#    for(i=0; i < 515000 * ts; i++); // wait approximately ts/10 seconds
#}

        .data
        .equ    1, inkey
        .equ    3, putChar
        .equ    6, printInt

        .text   
        .globl main

main:   addiu   $sp, $sp, -4
        sw      $ra, 0($sp)

        li      $t0, 0              # int cnt = 0;


while:                              # while(1)
        li      $v0, inkey          # inkey()
        syscall                     #

        move    $t1, $v0            # c = inkey()
if:     bne     $t1, 'R', endif     # if(c == 'R')
        li      $t0, 0              # cnt = 0;

endif:
        li      $v0, putChar        # 
        li      $a0, '\r'           # 
        syscall                     #

        move    $a0, $t1            # 1º argumento de printInt 

        li      $t2, 3              # 2º argumento de printInt
        sll     $t2, $t2, 16        # 3 << 16
        or      $t2, $t2,  10       # 10 | 3 << 16

        li      $v0, printInt       # 0000 0000 bits para definir a base   
                                    # 0000 0000 bits para definir o numero 
                                    # de digitos a apresentar          
        syscall

        addi $t0, $t0, 1            # (cnt + 1)
        andi $t0, $t0, 0xFF         # cnt = (cnt + 1) & 0xFF (contador de módulo FF)
        
        li $a0, 4
        jal wait


        j while
        lw      $ra, 0($sp)
        addiu   $sp, $sp, 4
        

        jr $ra


wait:   addiu $sp, $sp, -8
        sw $s0, 0($sp)
        sw $s1, 4($sp)
        
        li $s0, 0
        

for:    mul $s1, $a0, 51500
        bge $s0, $s1, endfor
        addi $s0, $s0, 1
endfor:
        lw $s0, 0($sp)
        lw $s1, 4($sp)
        addiu $sp, $sp, 8
        jr $ra