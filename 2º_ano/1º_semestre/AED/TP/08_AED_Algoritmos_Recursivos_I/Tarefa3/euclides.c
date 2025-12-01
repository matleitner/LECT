#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
	Algoritmo de euclides:

	Dividir o maior numero pelo menor
	Verificar o resto 
	Se resto != 0, repita o processo usando o divisor da divisão anterior como o novo dividendo e o resto como o novo divisor.

*/

int euclides(int num_a, int num_b){
		assert(num_a);	
		assert(num_b);
		
		if(num_a > num_b){
				int divisor = num_b;
				int resto = num_a%num_b;
				if( resto == 0) return divisor;
				return euclides(divisor,resto);
		}
		
		int divisor = num_a;
		int resto = num_b%num_a; 
		if(resto == 0) return divisor;
		return euclides(divisor, resto);
		
				
		
}

int main(int argc, char *argv[]){
		assert(argc==3);
		
		int res = euclides(atoi(argv[1]), atoi(argv[2]));
		printf("%d\n", res);
		
		return 0;
}
