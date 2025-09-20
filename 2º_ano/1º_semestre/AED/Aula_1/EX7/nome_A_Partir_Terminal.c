#include <stdio.h>


int main(int argc, char *argv[]){
	// cc nome_A_Partir_Terminal.c Martim Leitner 
	
	char first_name[30] = argv[1];
	char last_name[30] = argv[2];
	printf("%s   %s", first_name, last_name);
	return 0;

}
