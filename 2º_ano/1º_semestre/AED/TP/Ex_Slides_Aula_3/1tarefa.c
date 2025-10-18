#include <stdio.h>

int maior_de_4_nums_1o_metodo(int a, int b, int c, int d, int* counter_comparacoes, int *num_atribuicoes){
	
	int atribuicoes = 0;
	int comparacoes = 0;
	
	int maior;
	comparacoes++;
	if(a>b){
		comparacoes++;
		if(a>c){
			comparacoes++;
	 		if(a>d){
	    			maior = a;
				atribuicoes++;		
	 		} 
	 		else {
	 		        maior = d;
				atribuicoes++;
			}
		}
		else{
			comparacoes++;	
			if(c>d) {
				maior = c;
				atribuicoes++;
			}
			else {
				maior = d;
				atribuicoes++;
			}
		
		
		}
	}
	else{
		comparacoes++;
		if(b>c){
			comparacoes++;
	 		if(b>d){
				comparacoes++; 
				maior = b;
				atribuicoes++;
			}
	   		 
			else {
				atribuicoes++;
				maior = d;
			}
			
		}
		else{
			comparacoes++;
			if(c>d) {
				maior = c;
				atribuicoes++;}

			else{
			     maior = d;
			     atribuicoes++;
			}
		}
	 
	}
	*num_atribuicoes = atribuicoes;
	*counter_comparacoes = comparacoes;
	return maior;

}
int maior_de_4_nums_2o_metodo(int a, int b, int c, int d, int* counter_comparacoes, int *num_atribuicoes ){
	int atribuicoes = 0;
	int comparacoes = 0;

	atribuicoes++;
	int maior = a;
	comparacoes++;
	if (b>maior) {
		maior = b;
		atribuicoes++;
	}
	comparacoes++;
	if (c>maior){
		maior = c;
		atribuicoes++;
	}
	if(d>maior){
		maior = d;
		atribuicoes++;
	}
	*num_atribuicoes = atribuicoes;
	*counter_comparacoes = comparacoes;
	return maior;
}

int maior_de_n_nums_2o_metodo(int *array, int size, int* counter_comparacoes, int *num_atribuicoes ){
	int atribuicoes = 0;
	int comparacoes = 0;

	atribuicoes++;
	int maior = array[0];
	for( int i = 1; i<size; i++){
		comparacoes++;
		if (array[i]>maior) {
			maior = array[i];
			atribuicoes++;
		}	
	}

	
	*num_atribuicoes = atribuicoes;
	*counter_comparacoes = comparacoes;
	return maior;
}

int main(void){
	int counter_comparacoes = 0;
	int num_atribuicoes = 0;
	int maior = 0 ;
	int a,b,c,d;
	printf("Insira 4 numeros: ") ;
	scanf("%d %d %d %d", &a,&b, &c, &d);
	
	maior = maior_de_4_nums_1o_metodo( a, b, c, d, &counter_comparacoes, &num_atribuicoes);
	
	
	printf("1º metodo:\n");
	printf("Maior : %d\n", maior);
	printf("Numero de comparações : %d\n", counter_comparacoes);
	printf("Numero de atribuições : %d\n", num_atribuicoes);
	
	//

	counter_comparacoes = 0;
	num_atribuicoes = 0;
	maior = maior_de_4_nums_2o_metodo( a, b, c, d, &counter_comparacoes, &num_atribuicoes);
	

	printf("\n\n2º metodo:\n");
	printf("Maior : %d\n", maior);
	printf("Numero de comparações : %d\n", counter_comparacoes);
	printf("Numero de atribuições : %d\n", num_atribuicoes);
	
	//
	
	int array[] = {90, 21 , 41, 12, 41, 1 ,4, 2 ,45, 1};
	int size = 10;
	counter_comparacoes = 0;
	num_atribuicoes = 0;

	maior = maior_de_n_nums_2o_metodo(array,  size, &counter_comparacoes, &num_atribuicoes );

	printf("\n\n2º metodo para n numeros:\n");
	printf("Maior : %d\n", maior);
	printf("Numero de comparações : %d\n", counter_comparacoes);
	printf("Numero de atribuições : %d\n", num_atribuicoes);
	

	return 0;

}
