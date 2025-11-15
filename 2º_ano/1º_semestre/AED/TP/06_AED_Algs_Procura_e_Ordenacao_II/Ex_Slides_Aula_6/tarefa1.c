#include <stdio.h>

void swap(int *pArray1, int *pArray2 ){

    int temp = *pArray1;

    *pArray1 = *pArray2;
    *pArray2 = temp;


}

void selectionSort(int *arr, int n){
        for(int i = (n-1); i>0; i--){
            int indexMax = 0;

            for(int k = 1; k<=i; k++){

                if (arr[k]>=arr[indexMax]) indexMax = k;
            }
            if(indexMax!=i)swap(&arr[indexMax], &arr[i]);
        
        }
    

} 



/*
    9, 8, 7, 6, 5, 4, 3,2 1 
    ^                     ^

    indexMax              comparar de tras p frente

*/
int main(void){

    int array[] = {9,8,7,6,5,4,3,2,1};
    //selectionSort(array, 9);
    selectionSort(array, 9);
    
    for(int i = 0; i<9; i++){
        printf("%d\n",array[i]);
    }
    return 0;

}
