#include <stdio.h>
#include <stdlib.h>

void Permute(int* a, int* b, int* c);
	
	

int main(){
	int a = 10;
	int b = 20;
	int c = 30;
	
	
	
	for (int i = 0; i <= 2;i++){
		printf("a = %d, b = %d, c = %d\n",a ,b , c );
		Permute(&a, &b,&c);
	}
	return 0;
}



void Permute(int* a, int* b, int* c){
	int temporaria = *a;

	*a = *c;
	*c = *b;
	*b = temporaria;


}
