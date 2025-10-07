#include <stdio.h>
int fatorial(int num){
	if (num == 1 ) return 1;
	if (num == 0) return 1;
	return fatorial(num-1) * num   ;

}
int main(){
	int fact[10];
	for (int i = 0; i<=9 ; i++){
		fact[i] = fatorial(i);
	}

	for(int i = 1; i <=100000;i++){
		int temp = i;
		int sum = 0;
		while(temp>0){
			int algarismo = temp %10;
			sum+=fact[algarismo];
					
			temp/= 10;
			
			}
		if(sum == i) printf("%d\n",i);	
	}	
	return 0;
}
