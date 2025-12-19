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
# thd:	 $f2
# val:	 $f4
# n:	 $t1
# i:	 $t2
# aux:	 $f6
# sum:	 $f8

	.data
	
zero:	.double	0.0
	
	.text
	.globl	proc	
proc:					# float proc(double *array, double thd, double val, int n) {
	la	$t0, zero
	l.d	$f8, 0($t0)		# sum = 0.0;
	
	move	$t0, $a0		# double *array;
	mov.d	$f2, $f12		# double thd;
	mov.d	$f4, $f14		# double val;
	move	$t1, $a1		# int n;
	
	li	$t2, 0			# i = 0;
for:
	bge	$t2, $t1, endfor	# if(i >= n) goto endfor;
	
	sll	$t3, $t2, 3		# $t3 = 8 * i;
	addu	$t3, $t0, $t3		# $t3 = &array[i];
	l.d	$f10, 0($t3)		# $f10 = array[i];
	
	add.d	$f6, $f10, $f4		# aux = array[i] + val;
	
if:
	c.le.d	$f6, $f2		# if (thd >= aux) <=> if (aux <= thd)
	bc1t	 else			# goto else;
	
	s.d	$f2, 0($t3)		# array[i] = thd;
	add.d	$f8, $f8, $f2		# sum += thd;
	
	j 	endif
else:
	s.d	$f6, 0($t3)		# array[i] = aux;
	add.d	$f8, $f8, $f6		# sum += aux;
endif:
	addi	$t2, $t2, 1		# i++;
	j 	for
endfor:
	mtc1	$t1, $f16
	cvt.d.w	$f16, $f16		# $f16 = (double) n;
	div.d	$f0, $f8, $f16		# $f0 = sum / (double) n
	cvt.s.d	$f0, $f0		# $f0 = (float) $f0
	
	jr	$ra