#include <stdio.h>

int main(void){

	char multiple[] = "My string";

	char *p = &multiple[0]; // mesma coisa que escrever char *p = multiple
	printf("The address of the first array element : %p\n", p);

	p = multiple;

	printf("The address obtained from the array name: %p\n", multiple);




	return 0;
}
