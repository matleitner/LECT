#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
static int contador_mult = 0; 
long int x_n(int x, int n){
	if(n == 1) return x;
	contador_mult++;
	return x_n(x, n/2) * x_n(x, (n+1)/2); 

}


int main(int argc, char *argv[]){
	printf("%s^%s = %ld\n",argv[1], argv[2],  x_n(atoi(argv[1]), atoi(argv[2])));
	
	printf("Num de multiplicações: %d\n", contador_mult);

	return 0;
}
