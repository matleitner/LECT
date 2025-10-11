#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int check(int arr[], int size){
	assert(size>2);
	int r = arr[1] / arr[0];

	for(int i = 2; i<size; i++){
		if(arr[i] != r * arr[i-1])return 0;
	}
	return 1;

}

int main(){
	int size = 10;
	int array[]  = {1,2,3,4,5,6,7,8,9,10};

	
	printf("%d\n", check(array,size));
	int array1[]  = {1,2,4,4,5,6,7,8,9,10};

	
	printf("%d\n", check(array1,size));

	int array2[]  = {1,2,4,8,16,32,64,128,256,512};

	
	printf("%d\n", check(array2,size));

	int size40 = 40;
	int array40[size40];
	for(int j= 0;j<40; j++){
		array40[j] = rand()%100;
		printf("%d ",array40[j]);	
	}
	printf("\n%d\n",check(array40,size40));
	return 0;

}
