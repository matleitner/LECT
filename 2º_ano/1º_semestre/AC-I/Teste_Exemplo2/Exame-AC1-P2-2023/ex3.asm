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
#    char smp[17];   1		17	0
#    double xpt;     8		8	17->24
#    int ns;         4		4	32
#    char id;        1		1	36   
#    int sum;        4		4	37->40    
# } t_cell;          8		44->48   

#size:	$t0
#tc:   	$t1
#tmp:	$f2
#result:$f4
#i:	$t3

	.data
	
one:	.double	1.0
val:	.double	3.597

	.text
	.globl	prcells
prcells:
	la	$t0, one
	l.d	$f4, 0($t0)		# result = 1.0;
	
	li	$t3, 0			# i = 0;
	move	$t0, $a0		
	mulu	$t4, $t0, 48		# size;
	move	$t1, $a1
for:
	bge	$t3, $t0, endfor	# if (i >= size) goto endfor;
	
	mulu	$t5, $t3, 48		# 44 * i;
	addu	$t5, $t1, $t5		# &tc[i];
	
	lw	$t6, 32($t5)		# tc[i]->ns;
	mtc1	$t6, $f6
	cvt.d.w	$f6, $f6		# $f6 = (double)tc[i]->ns;
	la	$t6, val
	l.d	$f8, 0($t6)		# $f8 = 3.597;
	div.d	$f2, $f6, $f8		# tmp = (double)tc[i].ns / 3.597;
	
	add.d	$f4, $f4, $f2		# result += tmp;
	
	s.d	$f2, 24($t5)		# tc[i].xpt = tmp;
	
	cvt.w.d	$f10, $f4
	mfc1	$t6, $f10		# $t6 = (int)result
	addi	$t6, $t6, -1		# $t6 = (int)result - 1
	sw	$t6, 40($t5)		# tc[i].sum = (int)result - 1
	
	addi	$t3, $t3, 1		# i++;
	j 	for
endfor:
	mov.d	$f0, $f4		# return result;
	jr	$ra