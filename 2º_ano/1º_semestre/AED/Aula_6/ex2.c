#include <stdio.h>
#include <stdlib.h>
int count_comparacoes = 0;
int V_recurssion(int a, int *arr){


		if(a==0) return 0;

		if(a==1) return arr[0];
		
		int cond_a = arr[a-1] + V_recurssion(a-2, arr);

		int cond_b = V_recurssion(a-1,arr);
		count_comparacoes++;
		if(cond_b > cond_a) return cond_b;

		return cond_a;

}

int* loadArray(int size){
		int* array = (int*) malloc(sizeof(int)*size);
		if(array == NULL) return NULL;
		
		for (int i = 0; i<=size;i++){
				array[i] = rand()%100;
}


		return array;

}



int V_DynamicPrograming(int size, int *array){
	int coins[size];
	for (int i = 0; i < size; i++) coins[i] = 0;	
	int aux[size+1];
       	aux[0] = 0;
	aux[1] = array[0];
	for(int i = 2;i<=size;i++){
		int cond_a = array[i-1] + aux[i-2];
		int cond_b = aux[i-1];
		count_comparacoes++;
//		if(cond_a > cond_b)coins[i-1] = array[i-1];
		
		aux[i] = (cond_a > cond_b) ? cond_a : cond_b;
	}
	int j = size;
	int k = 0;
	while( j>0){
		if(aux[j] > aux[j-1]) {
			coins[k++] = array[j-1];j-=2;
		}
		else j--;
	}
	for(int i = 0; i<size;i++){
		printf("Coin: %d;", coins[i]);		
	}
	printf("\n");
	return aux[size];

}




int* A;

int* initMemo(int size){
	int* A = (int*) malloc(sizeof(int)*(1+size));
	for(int i = 0; i<= size;i++){
		

		A[i] = -1;
	
	}	
	return A;


}


int V_Memoization(int size, int *array){

	if(A[size] != -1) return A[size];


	if(size == 0){ 
		A[size] = 0;
		return A[size];
	
	}
	if(size == 1) {
		
		A[size] = array[0];
	
		return A[size];
	}
	int cond_a = array[size-1] + V_Memoization(size-2, array);
	int cond_b = V_Memoization(size-1,array);
	count_comparacoes++;
	A[size] = (cond_a > cond_b) ? cond_a : cond_b;
	return A[size];
	


}
void printArray(int size,int *arr){

	for (int i = 0; i < size; i++){
	
	
		printf("Coin:%d ", *(arr+i));
	
	}

	printf("\n");

}

int main(int argc, char** argv){
	int num = atoi(*(argv +1));
	A = initMemo(num);

	for(int size= 0; size<=num;size++){
				int* array = loadArray(size);
				
				for(int i = 0; i<=size; i++){printf("%d,", array[i]);}
				printf("\n");				
  				int a = V_recurssion(size, array);
				
				
				printf("i: %d\nRecursão comparações(%d)  :  %d\n",size,count_comparacoes,a);
				count_comparacoes = 0;
				int b = V_DynamicPrograming(size,array);
					
				printf("Dynamics comparações(%d)  :  %d\n",count_comparacoes,b);
				count_comparacoes = 0;
				
				int c= V_Memoization(size, array);
				printf("Memoization comparações(%d)  :  %d\n",count_comparacoes,c);
				
				count_comparacoes = 0;

				printf("\n\n");
				free(array);
	}

	return 0;
}




// limite inaceitavel i = 45  :  529

