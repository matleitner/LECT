

// selection sort, procura o minimo e troca para o primeiro elemento
#include <stdio.h>
static int COMPARACOES = 0;
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
} 


void SelectionSort(int* a, unsigned int n) {
	for(int i = 0; i < n-1; i++){
		int indexMin = i;
		for (int j = i+1; j < n; j++) {
			COMPARACOES++;
			if( a[indexMin] > a[j] ) indexMin = j; 
		}
		if(indexMin != i) swap(&a[indexMin], &a[i]);
		
	}
}

void main(void) {
	
	int n = 7;
	int a[] = {6,2,21,4,123,6,1};
	
	for(int i = 0; i<n; i++){
  		printf("%d->", a[i]); 
	}	                          
	printf("\n");	
	SelectionSort(a, n);
                       

	for(int i = 0; i<n; i++){
		printf("%d->", a[i]); 
	}
	printf("\n");
	printf("COMPARAÇÔES: %d\n", COMPARACOES);
	
}


/*
		sum i= 0->n-1(sum j =i ->n(1comparação)) = (1*(n)n-1) = n²-n
Melhor Caso: O(n) 
Médio : 
Pior Caso : O(n²)
*/

