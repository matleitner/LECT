 #float proc(double *array, double thd, double val, int n) {

#    int i;

#    double aux, sum;

#

#    sum = 0.0;

#    for (i = 0; i < n; i++) {

#        aux = array[i] + val;

#        if (aux > thd) {

#            array[i] = thd;

#            sum += thd;

#        } else {

#            array[i] = aux;

#            sum += aux;

#        }

#    }

#    return (float) (sum / (double) n);

#}


# array: $t0    

# thd:     $f12

# val:     $f14

# n:     $t1

# i:     $t2

# aux:     $f6

# sum:     $f8



    .data


sum:    .double 0.0

    

    .text

    .globl main    

    

proc:    or $t0, $0, $a0

    or $t1, $0, $a1

    la $t2, sum

    l.d $f8, 0($t2)

    

    li $t2, 0        # i = 0 

    

for:    bge $t2, $t1, endfor    #for (i = 0; i < n; i++) {

    

    sll $t3, $t2, 3        # i * 8

    addu $t3, $a0, $t3    # $t3 = &array[i]          

    

    l.d $f10, 0($t3)        # f10 = array[i]

    add.d $f6, $f10, $f14    # aux = array[i] + val

    

if:    c.le.d $f6, $f12        # if(aux > thd)

    bc1t else        #

    

    s.d $f12, 0($t3)        # array[i] = thd

    add.d $f8, $f8, $f12    # sum += thd;

    j endif

    

else:    s.d $f6, 0($t3)        # array[i] = aux

    add.d $f8, $f8, $f6    # sum += aux;

endif:        

    addi $t2, $t2, 1

    j for

endfor:

    mtc1 $a1, $f10        #

    cvt.d.w $f10, $f10    #

    div.d $f0, $f8, $f10    #

    cvt.s.d $f0, $f0        # return (float) (sum/ (double) n);

    

    jr $ra

    

main:    

    jal proc

    

    jr $ra 