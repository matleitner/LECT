#include <stdio.h>
#include <assert.h>

int check(int arr[], int size){
	int counter = 0;
	for(int i = 0;i<size-2; i++){

		for(int j = i+1; j<size-1;i++){

			for(int k = j+1; k<size;k++){
			
				if(arr[k] == arr[i] +arr[j])counter++;	
				
			}

		}


	}

	return counter;


}	


int main(){
	
	int size = 10;
	
	int array[] = {1,2,3,4,5,6,7,8,9,10};

	printf("%d\n",check(array,size));

	return 0;

}
