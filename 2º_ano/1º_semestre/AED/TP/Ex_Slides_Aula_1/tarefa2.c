#include <stdio.h>
		
/*
	Desenvolva um programa que leia uma sequência de valores inteiros
	terminada por −1 (valor terminador), e processe esses valores um a um.
	O programa deve imprimir:
	- Quantos valores inteiros positivos foram lidos.
	- O maior valor inteiro positivo lido.
	- O menor valor inteiro positivo lido.
	- O valor da média (com 3 casas decimais) dos valores inteiros positivos lidos.
 */

int main(void){
	int num;
	
	int counter_positives = 0;
		
	int max = -1;
	int min = 2147483646;	
	int sum = 0;
	
	while(num != -1){
		scanf("%d", &num);
		
		if (2147483647>num && num >0){ 
			counter_positives++;
			sum+= num;
		if(num<min) min = num;
			
		if(num>max) max = num;
		}





		
		
				
		printf("Valores interios positivos lidos: %d\n", counter_positives);


		 
	
	}

	printf("O maior valor inteiro lido foi: %d\n", max);
	printf("O menor valor inteiro lido foi: %d\n", min);
	double media = (double) sum / counter_positives;
	printf("A media é: %.2lf\n", media);	
	return 0;
}

