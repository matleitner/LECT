#typedef struct 	       |	Alinhamento	Dimensões	Offset
#{	       |	
# char a1[10];	       |	     1              10              0
# double g;             |	     8               8             10->16
# int a2[2];            |              4               8             24   
# char v;               |              1               1             32
# float k;              |              4               4             36
#} uvw;		     8              40

#typedef struct 	       |	Alinhamento	Dimensões	Offset
#{	       |	
# char a1[14];	       |	     1              14              0
# int i;                |	     4               4             16
# double g;             |              8               8             24   
# char a2[17];          |              1              17             32
# xyz;	       |              8 	   49->56	 

	.data

	.align 3
a1:	.asciiz "$t1"
	.align 3
g:	.double 3.141592653589
a2:	.word 291, 756
v:	'X'
k:	.float 1.983
	
	.text
	.globl main
	
	
f1:	
	la 