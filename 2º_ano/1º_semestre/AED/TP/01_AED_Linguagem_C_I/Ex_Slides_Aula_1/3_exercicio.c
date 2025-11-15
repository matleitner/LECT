#include <stdio.h>
#include <math.h>
//cc 3_exercicio.c -o 3Ex -lm
int main(void){

	double x = 10.45;
	
	double y = 3.95;
	
	printf("%f\n", floor(x));
	
	printf("%f\n", ceil(x));
	
	printf("%f\n", floor(y));
	
	printf("%f\n", ceil(y));
	return 0;
}
