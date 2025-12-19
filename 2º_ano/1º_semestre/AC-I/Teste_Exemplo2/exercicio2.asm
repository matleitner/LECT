#float func2(float *a, float t, int n)
#{
#    float oldg = -1.0;
#    float g = 1.0;
#    float s = 0.0;
#    int k;
#
#    for (k = 0; k < n; k++) {
#        while ((g - oldg) > t) {
#            oldg = g;
#            g = (g + a[k]) / t;
#        }
#        s = s + g;
#        a[k] = g;
#    }
#    return s / (float) n;
#}

# f0 return 
# f12 args

# f2 - f18 posso usar como temporario 
# f20 - f31 é inalterável 

# Mapa de registos: 
# func2(float *a -> $a0 , float t -> $f12, int n -> $a1) 
# oldg -> $f2
# g = $f4 
# s = $f6 
# k = $t0

	.data 
oldg:	.float -1.0
g:	.float 1.0
s:	.float 0.0

	.text
	.globl func2

func2:	la $t0, oldg
	l.s $f2, 0($t0)		# float oldg = -1.0;
	la $t0, g
	l.s $f4, 0($t0)		# float g = 1.0;
	la $t0, s
	l.s $f6, 0($t0)		# float s = 0.0;
	li $t0, 0		# k = 0		
for:	bge $t0, $a1, endfor		# for (k = 0; k < n; k++) {

	sll $t1, $t0,2		# $t1 = k * 4
	addu $t1, $a0, $t1 	# $f10 = a[k] 
	l.s $f10, 0($t1)		#

while:	sub.s $f8, $f4, $f2		#while ((g - oldg) > t) {
	c.lt.s $f12, $f8		# 
	bc1f endwhile		#

	mov.s $f2, $f4		# oldg = g

	add.s $f4, $f4, $f10		#(g + a[k]) 
	div.s $f4, $f4, $f12		#  g = (g + a[k]) / t;
	j while
endwhile:		 
	add.s $f6, $f6, $f4		#s = s + g;
	s.s $f4, 0($t1)		#a[k] = g;

	addiu $t0, $t0, 1		# k++
	j for
		
endfor:		
	mtc1 $a1, $f10
	cvt.s.w $f10, $f10
		
	div.s $f0, $f6, $f10		#return s / (float) n;
	jr $ra
