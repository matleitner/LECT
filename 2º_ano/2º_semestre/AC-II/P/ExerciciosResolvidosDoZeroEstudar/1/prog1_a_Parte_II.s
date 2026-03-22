#int main(void)
#   {
#   char c;
#   int cnt = 0;
#   do
#   {
#       c = getChar();
#       putChar( c );
#       cnt++;
#   } while( c != '\n' );
#   printInt(cnt, 10);
#   return 0;
#}


        .data
        .equ    2, getChar
        .equ    3, putChar 
        .equ    6, printInt
        .text
        .globl main


main:   li $t0, 0 

do:     li $v0, getChar
        syscall

        move $t1, $v0

        li $v0, putChar
        move $a0, $t1
        syscall

        addi $t0, $t0, 1

        bne $t1, '\n', do 
        
        # OU
        # li $t2, '\n'
        # bne $t1, $t2, do

        li $v0, printInt
        move $a0, $t0
        li $a1, 10
        syscall

        li $v0, 0
        syscall

        jr $ra
