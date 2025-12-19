#define SIZE 10
#void main(void)
#{
#	static int lista[SIZE];
#	int i, j, aux;
#// inserir aqui o código para leitura de valores e
#// preenchimento do array
#	for(i=0; i < SIZE-1; i++)
#	{
#		for(j = i+1; j < SIZE; j++)
#		{
#			if(lista[i] > lista[j])
#			{
#				aux = lista[i];
#				lista[i] = lista[j];
#				lista[j] = aux;
#			}
#		}
#	}
#// inserir aqui o código de impressão do conteúdo do array
#}

	.data
	.align 2 # neste caso não seria muito necessário pois começa num registo acabado em 0	
lista:	.word 40,1,2,3,4,5,6,7,8,9
	

	.eqv SIZE, 10

	.text
	.globl main
#Mapa de registos:
# $t0 : i 
# $t1 : j
# $t2 : aux
# $t3 : SIZE -1
# $t4 : lista
# $t5 : lista[i]
# $t6 : lista[j] 


main:	
	
	li $t0, 0			#i = 0
		#j = i + 1
	li $t3, SIZE			# $t3 = SIZE
	addi $t3, $t3, -1		# $t3 = SIZE - 1
	
	la $t4,lista			#$t4 = lista 
#	slt $t4, $t0, $t3
#	bne $t4, $0, endfor1
for1:	bge $t0, $t3, endfor1		# for(i = 0; i < SIZE-1;i++)

	sll $t5, $t0,2			#$t5 = i * 4
	addu $t5, $t4, $t5		#$t5 = endereço -> lista[i]
		
	lw $t6, 0($t5)			#$t6 = valor de -> lista[i]
	
	addi $t1, $t0, 1
	

	
for2:	bge $t1, SIZE, endfor2		#for(j = i+1;j< SIZE; j++)
		
	sll $t7, $t1,2			#$t7 = j*4
	addu $t7, $t4, $t7		#$t7 = endereço lista[j]	
	
	lw $t8, 0($t7)			# $t8 -> valor lista[j]
if:	ble $t6, $t8, endif		# lista[i] < lista[j]
	move $t2, $t6			# aux = lista[i]
	sw $t8, 0($t5)			# lista[i] = lista[j] 
	sw $t2, 0($t7)			# lista[j] = aux	
	lw $t6, 0($t5)
endif:	
	
	addi $t1, $t1,1
	j for2
endfor2:
	addi $t0, $t0,1
	j for1	
endfor1:
  
	
	
	
	
	
	jr $ra
