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
lista:	.word 20,1,2,3,4,5,6,7,8,9
	

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
	la $t0,lista			# $t0 = p
	li $t1, SIZE			# $t1 = SIZE
	addi $t3, $t1, -1		# 
	sll $t3, $t3, 2
	sll $t1, $t1, 2
	addu $t3, $t0, $t3 		# $t3 = pPenultimoLista
	addu $t4, $t0, $t1		# $t4 = pUltimo
				
for1:	bge $t0, $t3, endfor1		# while(p<ppenultimo) p++
		
	lw $t5, 0($t0)			#$t5 = *p
	
	addi $t2, $t0, 4			#$t2 = p+1
	

	
for2:	bge $t2, $t4, endfor2		#for(j = i+1;j< SIZE; j++)
		
		
	lw $t6, 0($t2)			# $t6 -> *(p++)

if:	ble $t5, $t6, endif		# *p < *p++
	move $t7, $t5			# aux = lista[i]
	sw $t6, 0($t0)			# lista[i] = lista[j] 
	sw $t7, 0($t2)			# lista[j] = aux	
	lw $t5, 0($t0)			# 

endif:	
	
	addi $t2, $t2, 4

	j for2
endfor2:
	addi $t0, $t0,4

	j for1	
endfor1:

	jr $ra
