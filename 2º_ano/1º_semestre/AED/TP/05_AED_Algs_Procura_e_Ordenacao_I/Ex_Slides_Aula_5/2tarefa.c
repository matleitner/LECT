#include <stdio.h>



int binarySearch(int arr[], int n, int x){
    int left = 0;
    int right = n-1;
    while(left<=right){

        int middle = left +  (right-left)/2;
        printf("Middle: %d\n\n", middle);

        if(arr[middle] == x) return middle;
        
        else if(arr[middle] < x){ left = middle +1;
            
        }
        else {right = middle -1;
        }
        printf("Left: %d\n\n",left);
        printf("Right: %d\n\n", right);
    }
    return -1;
}


int main(void){


    int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12};
    int x = binarySearch(arr, 14, 12 );
    printf("X : %d\n", x);
}