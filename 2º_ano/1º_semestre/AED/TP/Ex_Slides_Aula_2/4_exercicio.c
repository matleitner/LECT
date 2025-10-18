#include <stdio.h>
int main(void){
	char str[] = "Hello, World!";
	char *ptr = str; // é o mesmo que ter &str[0]
	printf("String characters using pointer arithmetic:\n");
	while (*ptr != '\0') {// Loop until the null character
		printf("%c ", *ptr);
		ptr++;// Move to the next character
	}
	printf("\n");


        return 0;
}

