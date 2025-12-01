#include <stdio.h>
#include <stdlib.h>
int seq_Search(int num, int* array, int n){
	
	if(*(array+n) == num) return n;
		
	if(n>0)	return seq_Search(num, array, n-1); 
	
	
	
	
	return -1;


}

int main(int argc, char *argv[]){

	int array[] = {1,1231,2,3,4,5,7};
	printf("%d\n", seq_Search(atoi(argv[1]), array, 7));



}
