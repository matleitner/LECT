#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
int numbers(int arr[], int size){
	assert(size > 2);

	int counter = 0;
	
	for(int i = 1; i<size-1;i++){
		
		if(arr[i] == (arr[i-1] + arr[i +1]))
			counter++;

	}

	return counter;

}

int main(){
	int num = 10;
       
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	
	for(int j=0; j<num; j++){
	
		printf("%d ",array[j]);
	}
	printf("\n");
	
	int counter = numbers(array, num);

	printf("O número de elementos que respeitam esta prioridade são: %d\n", counter);
	return 0;
}


/* Analise exprimental O(n) porque se fazem n-2 iterações logo p n -> infinito o -2 não importa 			
 Caso sistemático.

 sum(1) i = 1 -> n-2 = n-2


  
  */
