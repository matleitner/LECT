#typedef struct {
#    int acc;
#    unsigned char nm;
#    double grade;
#    char quest[14];
#    int cq;
#} t_kvd;
#
#double func3(int nv, t_kvd *pt)
#{
#    int i, j;
#    double sum = 0.0;
#
#    for (i = 0; i < nv; i++, pt++) {
#        j = 0;
#        do {
#            sum += (double) pt->quest[j];
#            j++;
#        } while (j < pt->nm);
#
#        pt->acc = (int) (sum / pt->grade);
#    }
#    return (pt->grade * (double) pt->cq);
#}



# struct	alinhamento	dimensão	offset
#	acc	4		4		0
#	nm	1		1		4
# grade	8		8		5->*8*
#	quest[14]	1		14		16
#	cq	4		4		4		30->32 
#	t_kvd	8	40

#	Mapa de registos:
#	int nv -> $a0, t_kvd *pt -> $a1
#	i: $t0
# j : $t1
# sum : $f2

	.data
sum:	.double 0.0

	.text
	.globl func3


func3:	l.d $f2, sum		# double sum = 0.0;
		li $t0, 0 		# i = 0

for:	bge $t0, $a0, endfor		#for (i = 0; i < nv; i++, pt++) {

		li $t1, 0		# j = 0

do:	#do {

		addiu $t3, $a1, 16		# pt->quest

		addu $t3, $t3, $t1		# pt->quest[j]
		lb $t3, 0($t3)				#
 
		mtc1 $t3, $f4		# 
		cvt.d.w $f4, $f4		# (double) pt->quest[j]
		add.d $f2, $f2, $f4 # sum += (double) pt->quest[j]
		
		addiu $t1, $t1, 1		# j++;
		
while:	lbu $t4, 4($a1)
		blt $t1, $t4, do	#} while (j < pt->nm);
		
		l.d $f6, 8($a1)		# pt->grade

		div.d $f8, $f2, $f6		# sum / pt->grade
		cvt.w.d $f8, $f8		# (int) sum / pt->acc
		mfc1 $t4, $f8		# 
		sw $t4, 0($a1) 	# pt->acc = (int) (sum/pt->grade)
		addiu $a1, $a1, 40	# pt++
		addiu $t0, $t0, 1 # i++
		j for

endfor:
	addiu $a1, $a1, -40
	l.d $f2, 8($a1)		# $f2 : pt->grade 
	lw $t0, 32($a1)		# $t0 : pt-> cq
			
	mtc1 $t0, $f4			# 
	cvt.d.w $f4, $f4		# (double) pt->cq 
	
	mul.d $f0, $f2, $f4		# return (pt->grade * (double) pt->cq);

	jr $ra
