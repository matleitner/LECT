#include <stdio.h>
#include <math.h>



int main(void){
	int num;
	int numero = 1;
	scanf("%d\n", &num);
	int potencias[10];
	for(int i = 0; i<=9; i++){
		int p = 1;
		for(int j = 0; j<num;j++){
			p *= i; 
		}
			
		potencias[i] = p;
	}
	for (int m = 0; m<num;m++){
		numero*=10;
	
	}
	
	for(int j = 1; j<numero;j++){
		int sum = 0;
		int temp = j;
	
		while(temp>0){
			int dig = temp %10;
			sum+= potencias[dig]; 
			temp/=10;;
			}	
		if(sum == num) printf("%d\n",j); 	
	}

	return 0;	
	
	
}
