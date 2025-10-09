#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int* makePotenciasArray(int num) {
	int* potencias = (int*)malloc(sizeof(int)*10);
	for(int i = 0; i<=9;i++){
                int p = 1;
                for(int c = 0;c<num;c++){
                        p *=i;
                }
                potencias[i] = p;
        }
	return potencias;
}


int countAlg(int number){

	
	if(number == 0) return 1;
	int counter = 0;
	while(number>0){
		
		number/=10;
		counter++;
	}
	return counter;
}

	
	
int main(void){
	int num;
	int numero = 1;
	scanf("%d", &num);
	
	int counter = 1;

	int j = 1;	
	
	while(counter<=num){
		
		int sum = 0;
			
		int temp = j;
		int temp_alg= countAlg(j);
		
		if(temp_alg > counter ) {

			counter++;
			continue;
		}

		
		int* potencias = makePotenciasArray(temp_alg);
		while(temp>0){
			
			int dig = temp %10;
		
			sum+= potencias[dig]; 
		
			temp/=10;;
		
		}	
		if(sum == j) printf("%d\n",j); 	
		free(potencias);
		j++;
			
	}
	
	return 0;	
	
}
