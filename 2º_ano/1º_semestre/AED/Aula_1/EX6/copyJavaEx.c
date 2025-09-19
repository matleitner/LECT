#include <stdio.h>



void printArray(char s[]; int a[]){
	int size = sizeof(a)/sizeof(a[0];
	printf("%s:", s);
	for (int i = 0; i<=size; i++)
	{
		printf("%d\n",a[i]);
	}
	printf("\n");
}


int main(void){
	int a[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	printArray("a", a);
	return 0;
}



