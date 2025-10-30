//
// TO DO : desenvolva um algoritmo para verificar se um numero inteiro positivo
//         e uma capicua
//         Exemplos: 12321 e uma capiacua, mas 123456 nao e
//         USE uma PILHA DE INTEIROS (STACK) e uma FILA DE INTEIROS (QUEUE)
//
// TO DO : design an algorithm to check if the digits of a positive decimal
//         integer number constitue a palindrome
//         Examples: 12321 is a palindrome, but 123456 is not
//         USE a STACK of integers and a QUEUE of integers
//

#include <stdio.h>

#include "IntegersQueue.h"
#include "IntegersStack.h"

int main(void) { 
	int num;
	printf("Insira um número: ");
	scanf("%d", &num);
	
	int aux = num;
	


	Stack* stack = StackCreate(20);
	Queue* queue = QueueCreate(20);

	// load struct
	while(aux != 0){
		int aux_rem = aux%10;
		
		StackPush(stack, aux_rem);
		QueueEnqueue(queue, aux_rem);
		
		aux/=10;	
	
	}
	int capicua = 1;
	while(!StackIsEmpty(stack)){
	
		if(StackPop(stack) != QueueDequeue(queue)){ 
			
			capicua = 0;	
	       	
			break;
	 	}	
						
	}
	Stack** adrPilha = &stack;
	Queue** adrFila = &queue;
	StackDestroy(adrPilha);
	QueueDestroy(adrFila);

	printf("O número seguinte %s uma capicua\n", (capicua ? "é " : "não é"));
	return 0; 

}



/*
 * 123456789
 * stack 9 8 7 6 5 4 3 2 1 pop é 1 fica: 9 8 7 6 5 4 3 2 pop 2 
 *
 * queue 9 8 7 6 5 4 3 2 1 pop 
 *
 * */
