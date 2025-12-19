#include <stdio.h>



void printArray(char s[], int a[], int size){
		
	printf("%s:\n", s);

	for (int i = 0; i<size; i++){
		printf("%d ",a[i]);
	}
	
	printf("\n");
}

void cumSum(int a[], int b[], int size){
	
	int c = 0;
	
	for(int i = 0; i<size; i++){
	
		c+=a[i];
		b[i] = c;
	
	}
}


int main(void){
	
	int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int sizeA = sizeof(a)/sizeof(a[0]);
	printArray("a", a, sizeA);

	int b[12];
	int sizeB = sizeof(b)/sizeof(b[0]);
	cumSum(a,b, sizeA);

	printArray("b",b,sizeB);

	return 0;
}



