#include <stdio.h>
static int counter = 0;

int get_max_recursive(int *array, int n){

	if(n == 1) return *array;
	
	int maior_sub_array1 = get_max_recursive(array, (n)/2);			// n / 2 elementos 
	
	int maior_sub_array2 = get_max_recursive(array + n/2, n - n/2); // (n+1)/2 elementos
	counter++;
	int t = (maior_sub_array1 > maior_sub_array2) ? maior_sub_array1 : maior_sub_array2;
	return t;
}

int main(void){
	
	int array[] = {1,23,13,123123,10,1,2,34,112,9121231 };
	int n = 10;
	counter = 0;
	printf(" O max do array é: %d\n", get_max_recursive(array, n));

	printf("nº de comp: %d\n", counter);
	return 0;
}
