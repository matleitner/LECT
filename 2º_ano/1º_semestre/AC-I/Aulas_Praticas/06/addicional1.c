#include <stdio.h>

int main(int argc, char *argv[]){
	int countChars = 0;
	int length = 0 ;
	char* stringMaior;
	int biggestChar = 0;
	for(int i = 1; i< argc; i++){
		int j = 0;

		do{
			if(argv[i][j] !='\0'){
				length++;				
				if(('a'<=argv[i][j]  && 'z'>=argv[i][j]) || ('Z'>=argv[i][j] && 'A' <=argv[i][j])) countChars++;
			j++;
			}  
			
}while(argv[i][j] != '\0');	
	
		if(biggestChar <length) {
			stringMaior = argv[i]; 
			biggestChar = length;			
		
		
		}
		printf("Numero de caracteres de (%s): %d\n", argv[i], length);	
		printf("Numero de letras de (%s): %d\n", argv[i], countChars);
	
		length = 0;
		countChars = 0;
}
	printf("String maior destas todas é: %s\n", stringMaior);
		
	 


} 
