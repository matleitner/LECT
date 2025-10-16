#include <stdio.h>
#include <assert.h>

int check(int arr[], int size){
	int counter = 0;
	for(int k = 2;k<size; k++){
		for(int j = 1;j<k; j++){
		       for(int i= 0; i<j;i++){		
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



