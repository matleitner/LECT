#include <stdio.h>


int main(int argc, char *argv[]){
	// ./a.out Martim Leitner 
	char *first_name = argv[1];
	char *last_name = argv[2];	
	
	printf("Primeiro nome: %s\nÚltimo nome: %s\n", first_name, last_name);
	return 0;

}
