#include<stdio.h>
#if 1 
#define ola(x,y)  #x #y

#endif 
int main(void){
	int my_array[3] = {1, 2, 3};
	int* p_my_array = my_array;
	
	goto ola;
	printf("Ola");
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
	
	ola:
	printf("%d\n",*p_my_array );
	printf("%s\n",ola(1,2));	
	return 0;
}
