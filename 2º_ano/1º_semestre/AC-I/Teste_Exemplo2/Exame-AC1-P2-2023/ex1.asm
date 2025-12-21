#int checkp(int);

#int treat(int *array, int low, int high) {
#    int i, npr;
#    int *p = array;
#
#    for (i = low + 1, npr = 0; i < high; i++) 
#    {
#        if (checkp(i) == 1) {
#            *array = i;
#            array++;
#            npr++;
#        }
#    }
#    *(p + npr) = npr;
#    return npr;
#}

# array: $s0
# low  : $s1
# high : $s2
# i    : $s3
# npr  : $s4
# p    : $s5

    .data


    .text
    .globl main
    
treat:    	addiu $sp, $sp, -28
    	sw $ra, 0($sp)
    	sw $s0, 4($sp)
    	sw $s1, 8($sp)
    	sw $s2, 12($sp)
    	sw $s3, 16($sp)
   	sw $s4, 20($sp) 
   	sw $s5, 24($sp)
  	move $s0, $a0        # s0 -> array
  	move $s1, $a1        # s1 -> low
  	move $s2, $a2        # s2 -> high
     
   	move $s5, $s0
    
    	addiu $s3, $s1, 1   	 # i = low + 1
    	li $s4, 0        	# npr = 0
    
for:    	bge $s3, $s2, endfor    # for (i = low + 1, npr = 0; i < high; i++) 
    
    	move $a0, $s3        	#
    	jal checkp		#
if:    	bne $v0, 1, endif    	# if(checkp(i) == 1) {
    	sw $s3, 0($s0)		# array = i;
 	addiu  $s0, $s0, 4    	# array++;
    	addi $s4, $s4, 1      	# npr++;
endif:
	addi $s3, $s3, 1        	# i++
     	j for 
endfor: 
	sll $t0, $s4, 2
    	addu $s5, $s5, $t0
	sw $s4, 0($s5)
    
	move $v0, $s4
      
    	lw $ra, 0($sp)
    	lw $s0, 4($sp)
    	lw $s1, 8($sp)
    	lw $s2, 12($sp)
    	lw $s3, 16($sp)
    	lw $s4, 20($sp) 
    	lw $s5, 24($sp)
	addiu $sp, $sp, 28

    	jr $ra