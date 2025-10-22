#include <stdio.h>

void printArray(int* pArray, int n){
    
    for(int i = 0; i<n; i++){

        printf("%d\n", pArray[i]);
    
    }

}

void swap(int *pArr1, int *pArr2){
    int temp = *pArr1;
    
    *pArr1 = *pArr2;
    
    *pArr2 = temp;

}

int getMaxIndex(int *arr,int start, int n){
    int indexMax = 0;
    for(int start; start<n;start++){
        if(arr[indexMax]<arr[start]) indexMax = start;
    

    }
    return indexMax;
}
int getMinIndex(int *arr,int start, int n){
    int minIndex = 0;

    for(int start; start<n;start++){

        if(arr[minIndex]>arr[start]) minIndex = start;

    }

    return minIndex;

}
aunt
void selectionSort(int *arr, int n){
    int left = 0;
    int right = n;
    while(left<right){

//printArray(arr,n);
//printf("\n");


        int indexMin = getMinIndex(arr, left, right);
        int indexMax = getMaxIndex(arr, left, right);

        if(indexMin != left) swap(&arr[indexMin], &arr[left]);
        if(indexMax == left) indexMax = indexMin;
        if(indexMax != right) swap(&arr[right],&arr[indexMax]);
        left++;
        right--;
    }

}
int main(void){

    int arr[] = {0,1,2,3,4,2,1};
    selectionSort(arr, 7);
    printArray(arr, 7);
    //printArray(arr,5);
    //printf("%d\n", arr[2]);
    return 0;
}