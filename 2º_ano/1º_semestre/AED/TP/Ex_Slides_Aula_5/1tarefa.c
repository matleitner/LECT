#include <stdio.h>

int counter_comparacoes_search = 0;
int counter_comparacoes_searchIfNot = 0;

int search(int arr[], int n, int x){
	int i;
	for(i = 0;i<n; i++){
        counter_comparacoes_search++;
		if(arr[i] == x)
			return i;

	}
	return -1;
}

int searchIfNot(int arr[], int n, int x){
	int stop = 0; int i;
    
	for(i = 0; i<n; i++){
        counter_comparacoes_searchIfNot++;
		if(x<=arr[i]){
			stop = 1; break;
		}

	}
    counter_comparacoes_searchIfNot++;
	if(stop && arr[i] == x)
	return x;

	return -1;

}
int main(void){
	int arr[] = {1,2,3,4,5,6,8,9};

    int x = search(arr, 8, 0);
    int y = searchIfNot(arr, 8 ,0);
    printf("Search(): %d\n", x);
    printf("Comparações %d\n", counter_comparacoes_search);
    printf("SearchIfNot(): %d\n", y);
    printf("Comparações %d\n", counter_comparacoes_searchIfNot);
	return 0;
}