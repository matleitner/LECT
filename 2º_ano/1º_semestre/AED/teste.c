#include<stdio.h>

int main(void){
	int my_array[3] = {1, 2, 3};
	int* p_my_array = my_array;
	// Pointer to first element !!
	/*
	my_array[0] = 10;
	*my_array = 20;
	*p_my_array = 30;
	*/

	//printf("New value of first element: %d\n", *(1+p_my_array));
	/*
	int num;
	char my_char;
	
	scanf("%d %c", &num,&my_char);
	*/
	printf("%d",*p_my_array );
	
	return 0;
}
