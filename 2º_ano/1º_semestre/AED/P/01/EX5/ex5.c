#include <stdio.h>
#include <math.h>
int main(void){
	int num;


	printf("Insira um número: ");
	
	scanf("%d",&num);
	
	
	printf("\tTabela (0 até %d)\n\n", num);

	printf("%-15s|%-20s|%-15s\n", "Número", "Quadrado","Raiz Quadrada");
	
	if (num >0){

		for (int i = 1;i <= num;i++){
			double sqrtOfNum = sqrt(i);
		       	int squareOfNum = i*i;	
			printf("%-14d|%-20d|%-15.2f\n",i, squareOfNum, sqrtOfNum);
	
		} 
	}

	else {
		printf("não é possível continuar o programa, adeus...");
	}
	return 0;
}
