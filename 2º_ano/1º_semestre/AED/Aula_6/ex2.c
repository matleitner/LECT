#include <stdio.h>
#include <stdlib.h>

int V_recurssion(int a, int *arr){


        if(a==0) return 0;

        if(a==1) return arr[a-1];

        int cond_a = arr[a] + V_recurssion(a-2, arr);

        int cond_b = V_recurssion(a-1,arr);

        if(cond_b > cond_a) return cond_b;

        return cond_a;

}

int* loadArray(int size){
        int* array = (int*) malloc(sizeof(int)*size);
        if(array == NULL) return NULL;

        for (int i = 0; i<size;i++){
                array[i] = i+1;
        }


        return array;

}


int main(void){
       for(int size= 0; size<10;size++){
                int a;
                int* array = loadArray(size);
	        a = V_recurssion(size, array);
                printf("%d\n",a);
                free(array);
       }

       return 0;
}
