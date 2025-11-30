#include <stdio.h>
#include <stdlib.h>

void swap( void *a, void *b){
    int aux = *(int*) a;
    *(int*) a = *(int*) b;
    *(int *) b = aux;
}


void selectionSort(int *array, int n){

    for(int k = n-1; k>0; k--){
        int indexMax = 0;
        for(int i = 1; i<=k; i++){
            if(array[i]>array[indexMax]) indexMax = i;
        }
        if(indexMax != k) swap(&array[indexMax],&array[k]);
    }

}
void insertElement(int sorted[], int n, int elem){
    int i;
    for(i= n; (i>=0) && (elem<sorted[i]);i++){
        sorted[i+1] = sorted[i];

    }
    sorted[i+1] = elem;
}


void insertionSort(int array[], int n){
    for(int i = 1; i<n; i++){
        insertElement(array, i-1, array[i]);

    }
}
void printArray(int *array, int n){
    
    for(int i = 0; i<n;i++)printf("%d,", array[i]);
}

int main(int argc, char **argv){
    char linha[256];
    FILE *fich =  fopen(argv[2],"r");
    int size = 100000;
    int *nums = malloc(size * sizeof(int));
    int i = 0;
    while(fgets(linha, sizeof(linha), fich)){
        nums[i] = atoi(linha); 
        //printf("%d, ", nums[i]);
        i++;
    }
    fclose(fich);
    printArray(nums,i);
	 printf("aaaaaaaaa\n");
	 switch(atoi(argv[1])){
    case 0:
	 	selectionSort(nums,i);
		break;
	 case 1:
		insertionSort(nums,i);
		break;
	 }
    printArray(nums,i);
	 printf("\n");
    free(nums);
    return 0;


}
