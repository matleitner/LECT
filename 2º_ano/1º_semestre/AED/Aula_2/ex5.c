#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Display the contents of array a with n elements
// Pre-Conditions: a != NULL and n > 0
// Example of produced output: Array = [ 1.00, 2.00, 3.00 ]
void DisplayArray(double* a, size_t n) {
	printf("Array = [");
	assert(a != NULL);
	assert(n>0);
	for(int i = 0; i < n;i++){
		if (i!=n-1) printf(" %.2lf,",a[i]);
		else printf(" %.2lf ",a[i]);
	}
	printf("]\n");



}


// Read the number of elements, allocate the array and read its elements
// Condition: number of elements > 0
// Pre-Condition: size_p != NULL
// Return NULL if memory allocation fails
// Set *size_p to ZERO if memory allocation fails
//le do teclado (duhh)

double* ReadArray(size_t* size_p) { 
	if(size_p  == NULL || *size_p == 0 ) return NULL;

	double* array = (double*) malloc(sizeof(double)*(*size_p));
	
	if(array == NULL) {
		
		*size_p = 0;	
		return NULL;
	}

	for( int i = 0; i < *size_p; i++){
		printf("Insira um número: ");
		scanf("%lf",&array[i]);
	}
	
	return array;
	
}



// Allocate and return a new array with (size_1 + size_2) elements
// which stores the elements of array_1 followed by the elements of array_2
// Pre-Conditions: array_1 != NULL and array_2 != NULL
// Pre-Conditions: size_1 > 0 and size_2 > 0
// Return NULL if memory allocation fails
double* Append(double* array_1, size_t size_1, double* array_2, size_t size_2){
	double* final_array = (double*) malloc(sizeof(double)*(size_1+size_2));

	for (int i = 0; i< (size_1+size_2); i++){
		if(i<size_1)final_array[i] = array_1[i];
		else final_array[i] = array_2[i-size_1];			
	}
	
	return final_array;
}
int main(){
	double a[] = {1.00, 2.00, 3.00};
	size_t n = sizeof(a)/sizeof(a[0]);
	size_t size;
	printf("Insira o número p/ o tamanho do array: ");
	scanf("%ld",&size);
	DisplayArray(a,n);
	double* array = ReadArray(&size);
	DisplayArray(array,size);
	double* array_append = Append(a,n,array,size);

	DisplayArray(array_append, n+size);
	free(array_append);
	free(array);
	return 0;

}


