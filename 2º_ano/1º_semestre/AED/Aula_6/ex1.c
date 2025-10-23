#include <stdio.h>
#include <stdlib.h>

int ADDS = 0;

int DelannoyRecurssive(int m, int n){
	if(m == 0 || n == 0) return 1;
	ADDS+=2;
	return DelannoyRecurssive(m-1,n) + DelannoyRecurssive(m-1,n-1) +DelannoyRecurssive(m,n-1);
}

unsigned long DelannoyDynamicPrograming(unsigned int m, unsigned int n){
	
	unsigned long long  int array[m+1][n+1];
	for(unsigned int i = 0; i<=m ; i++){
	
		for(unsigned int j = 0; j<=n; j++){
		
			if(i ==  0 || j == 0) array[i][j] = 1;
		
			else{
			     array[i][j] = array[i-1][j] + array[i-1][j-1] + array[i][j-1];
			     ADDS+=2;		
			}
		}
	
	}
	return array[m][n];

}
unsigned long int **D;

unsigned long  int **initMemo(int num){
	unsigned long int **mem = (unsigned long int **) malloc((num+1)*sizeof( unsigned long int *));

	for(int i =0; i<= num;i++){

		mem[i] = malloc((num+1)*sizeof( unsigned long  int));
	
		for(int j = 0; j<= num; j++){
	
			mem[i][j] = -1;	

		}

	}
	return mem;
}
	
unsigned long DelannoyMemoization(unsigned int m, unsigned int n){
	if(D[m][n] !=  -1) return D[m][n];

	if(n == 0||m==0) D[m][n] = 1;

	else{
		ADDS+=2;
		D[m][n] = DelannoyMemoization(m-1,n)+DelannoyMemoization(m-1,n-1) + DelannoyMemoization(m,n-1);
	}	
	
	return D[m][n];



} 

int main(int argc, char *argv[]){
		int num = atoi(argv[1]);
		D = initMemo(num);	
		for(unsigned long int i = 0; i<=num; i++){
			for(unsigned long int j = 0; j<=num;j++){
	
				if(j ==i ) printf("\n");	
//				int d = DelannoyRecurssive(i,j);

//				printf("Recurssive (%d,%d): %d\n",i,j, d);
//				unsigned long int d = DelannoyDynamicPrograming(i,j); 
				unsigned long int d = DelannoyMemoization(i,j);

				printf("Memoization (%ld,%ld): %d\t%ld\n",i,j,ADDS,d);
			
//				printf("Dynamic (%d,%d): %d\t%ld\n",i,j,ADDS,d);

				ADDS = 0;			
			}
		
	}
	free(D);
	//./ex1 14 é o max p  long unsigend 
	return 0;
}




/*
 algoritmo recurssivo Res(n) = c * 2^n
 	O(2^n)
 *
 *
 *
 *
 * */
