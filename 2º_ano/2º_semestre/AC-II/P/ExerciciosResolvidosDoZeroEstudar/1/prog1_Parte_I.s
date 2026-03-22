#int main(void)
#{
#printStr("AC2 – Aulas praticas\n");
#// system call
#return 0;
#}

        .equ printStr
        .data
msg:    .asciiz  "AC-2 - Aulas praticas\n";
        .text
        .globl main

main:   la $a0, msg
        li $v0, printStr
        syscall

        li $v0, 0
        jr $ra

        



