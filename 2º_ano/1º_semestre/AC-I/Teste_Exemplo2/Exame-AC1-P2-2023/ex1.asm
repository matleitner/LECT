#int checkp(int);

#int treat(int *array, int low, int high) {
#    int i, npr;
#    int *p = array;
#
#    for (i = low + 1, npr = 0; i < high; i++) 
#    {
#        if (checkp(i) == 1) {
#            *array = i;
#            array++;
#            npr++;
#        }
#    }
#    *(p + npr) = npr;
#    return npr;
#}

# array: $s0
# low  : $s1
# high : $s2
# i    : $s3
# npr  : $s4
# p    : $s5

	.data
	
	.text
	.globl	treat
treat:						# int treat(int *array, int low, int high) {
	addiu	$sp, $sp, -28			# salvaguarda de registos...
	sw	$ra, 0($sp)
	sw	$s0, 4($sp)
	sw	$s1, 8($sp)
	sw	$s2, 12($sp)
	sw	$s3, 16($sp)
	sw	$s4, 20($sp)
	sw	$s5, 24($sp)
	
	move	$s0, $a0			# int* array;
	move	$s1, $a1			# int low;
	move	$s2, $a2			# int high;
	
	move	$s5, $s0			# int* p = array;
	
	addi	$s3, $s1, 1			# int i = low + 1;
	li	$s4, 0				# int npr = 0;
for:
	bge	$s3, $s2, endfor		# if(i >= high) goto endfor;
	
	move	$a0, $s3
	jal	checkp				# ($v0 =) checkp(i);
if:
	bne	$v0, 1, endif			# if(checkp(i) != 1) goto endif;
	
	sw	$s3, 0($s0)			# *array = i;
	addiu	$s0, $s0, 4			# array++;
	addi	$s4, $s4, 1			# npr++;
endif:
	addi	$s3, $s3, 1			# i++;
	j	for
endfor:
	sll   	$t0, $s4, 2     		# $t0 = npr * 4
	addu  	$t0, $s5, $t0   		# $t0 = p + npr*4
	sw    	$s4, 0($t0)     		# *(p + npr) = npr
	
	lw	$ra, 0($sp)			# repor registos e repor stack.
	lw	$s0, 4($sp)
	lw	$s1, 8($sp)
	lw	$s2, 12($sp)
	lw	$s3, 16($sp)
	lw	$s4, 20($sp)
	lw	$s5, 24($sp)
	addiu	$sp, $sp, 28
	
	move	$v0, $s4			# return npr;
	
	jr	$ra				# }