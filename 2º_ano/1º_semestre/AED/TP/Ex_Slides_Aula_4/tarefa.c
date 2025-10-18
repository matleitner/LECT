#include <stdio.h>

int main(void){
	int array[]  = {21,2,3,4,5,1,7,1,42,32};
	size_t size  = 10;
	int indexMax = 0;
	int indexMin = 0;
	int firstMinIndex = 0;
	

	for(int i= 1; i<size; i++){
		if(array[i] >array[indexMax])
			indexMax = i;
	
		if(array[i] <= array[indexMin]){
			indexMin = i;
			if(array[i] < array[firstMinIndex] && array[indexMin] != array[firstMinIndex])
				firstMinIndex = i;
			}
	} 	
	printf("First min: %d\n", firstMinIndex);
	printf("Last min: %d\n",indexMin);
	printf("Last max: %d\n", indexMax);


	return 0;
}
