 #double prcells(int size, t_cell *tc) {

#    double tmp, result = 1.0;

#    int i;

#

#    for (i = 0; i < size; i++) {

#        tmp = (double)tc[i].ns / 3.597;

#        result += tmp;

#        tc[i].xpt = tmp;

#        tc[i].sum = (int)result - 1;

#    }

#    return result;

#}


# Copie a estrutura para o topo da área de resposta  

# e substitua xx pelo valor adequado

# typedef struct 

# {                  Alignment  Size   Offset

#    char smp[17];      1     17     0

#    double xpt;        8         8      17 -> 24

#    int ns;            4         4      32

#    char id;           1         1      36 

#    int sum;           4         4      37-> 40

#} t_cell       max(1,4,8) = 8   44      48 


# double prcells( int size -> $a0, t_cell *tc -> $a1)

# tmp : $f2

# result : $f4

# i : $t0

# &tc[i] : $t1



    .data

result:    .double 1.0

d:    .double 3.597

    .text

    .globl prcells

    

prcells:    

    la $t0, result        #

    l.d $f4, 0($t0)        # double result = 0.0

    

    li $t0, 0        # int i = 0

    

for:    bge $t0, $a0, endfor

    mul $t1, $t0, 48

    addu $t1, $a1, $t1    # &tc[i]

    lw $t2, 32($t1)        # tc[i].ns

    

    mtc1 $t2, $f6        

    cvt.d.w $f6, $f6        # (double) tc[i].ns 

    

    la $t3, d

    l.d $f8, 0($t3)

    div $f2, $f6, $f8    # tmp = (double) tc[i].ns / 3.597

    

    add.d $f4, $f4, $f2    # result += tmp

    

    s.d $f2, 24($t1)        # tc[i].xpt = tmp

    

    cvt.w.d $f10, $f4    # 

    mfc1 $t4, $f10        #

    addi $t4, $t4, -1    # (int) result - 1

    sw $t4, 40($t1)        # tc[i].sum = (int) result

    

    addi $t0, $t0, 1     # i++    

    j for

endfor:    


    mov.d $f0, $f4

    

    jr $ra 