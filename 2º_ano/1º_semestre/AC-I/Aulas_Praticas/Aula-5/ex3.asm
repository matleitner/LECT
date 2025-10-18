	.data
	.eqv SIZE, 10	
str1:	.asciiz "\nIntroduza um numero: "
str2:	.asciiz "; "
	.align 2
lista:	.space 40
	.eqv print_string, 4
	.eqv read_int, 5
	.eqv print_int10, 1 
	.eqv FALSE,0
	.eqv TRUE,1 
	.text
	.globl main
	
	
# Mapa
# $t0 = p
# $t1 = *p
# $t2 = lista + size 
# houve_troca: $t4
# i: $t5	
#lista: $t6
#lista + i: $t7
main:		la $t0, lista	  #$t0 = lista ou &lista[0]
		li $t3, SIZE	  #$t3 = SIZE
		sll $t3, $t3, 2	  #$t3 = SIZE * 4
		addu $t2, $t3, $t0 #$pointer de ultimo = t2 = lista + size*(4)
whileReadInt:		bgeu $t0, $t2, endwri #while(p <pultimo){

		li $v0, read_int   #read_int()
		syscall 

		sw $v0, 0($t0)	  #*p  = read_int() 
		addiu $t0, $t0, 4  # p +=4
			
		j whileReadInt
endwri:
		la $t6, lista
		li $t3, SIZE
		addi $t3, $t3,-1
do:		li $t4, FALSE 	#houve_troca = FALSE
			#do {
			
		li $t5, 0		#i = 0		
for:		bge  $t5,$t3, endfor	#while(i<SIZE-1)
if:		sll  $t7,$t5, 2	# $t7 = i *4
		addu $t0, $t6,$t7# $t6 = &lista[i]
		lw   $t8, 0($t0) # $t8 = listq[i]
		lw   $t9, 4($t0) # $t9 = lista[i+1] 
		ble  $t8,$t9, endif#if(lista[i] > lista[i+1]){
		sw   $t8, 4($t0) #lista[i+1] = $t8
		sw   $t9, 0($t0) #lista[i] = $t9
		li   $t4, TRUE 	#
endif:		addi $t5, $t5, 1 # i ++
		j for
endfor:
		beq $t4, TRUE, do
		
		
#Mapa de registos
# $t0 = i
# $t1 = lista
# lista + i $t2
		li  $t0, 0	#i = 0
		la  $t1, lista	#$t1 = &lista[0]
		li  $t3, SIZE	#$t3 = SIZE
		
whilePrintList:		bge $t0, $t3, endwpl #while (i < SIZE )
		
		sll $t2, $t0, 2	# $t2 = I *4
		addu $t2, $t2,$t1 # $t2 =  &lista[0] + i*4
		
		lw  $t4, 0($t2)	#lista[i] = *&lista[i]
		or $a0, $0, $t4	
		li $v0, print_int10
		syscall	#print int
		
		la $a0, str2
		li $v0, print_string
		syscall	#print string
		
		addi $t0,$t0,1	#i++
		j whilePrintList
		
endwpl:						

		jr $ra
