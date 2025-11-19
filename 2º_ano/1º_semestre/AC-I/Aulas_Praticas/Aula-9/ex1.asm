	.data
k1:	.float 2.59375
k2:	.float 0.0
	.text
	.eqv read_int, 5
	.eqv print_float, 2
	
	.globl main
	
#Mapa de registos 
# $f2: res / $t0 : val
	
main:	

do:	li $v0, read_int		#do { val = read_int();
	syscall

	
	
	mtc1 $v0, $f2
	cvt.s.w $f2, $f2		# (float)val
	
	la $t1, k1
	l.s  $f4, 0($t1)
	mul.s $f2, $f4, $f2	# res = val * 2.59375
	li $v0, print_float 	# print_float( res ) 
	mov.s $f12, $f2
	syscall
	la $t1, k2		# 0.0
	l.s $f6, 0($t1)
	
	c.eq.s $f2, $f6		# while ( res != 0.0")
	bc1f do
	
	li $v0, 0
	jr $ra


# b) 7,78125 
# parte inteira 0111
# parte fracionaria 0.78125 
#      0.78125 * 2
# 1     .5625 * 2
# 1     .125 * 2
# 0     .25 * 2
# 0     .5 * 2
# 1     1.0 
# 0111.11001 * 2⁰
# 1.1111001 * 2²
# 127+2 = 129 
# 0 1000000	1 11110010000000000000000

