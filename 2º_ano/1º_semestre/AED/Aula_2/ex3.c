#include <ctype.h>
#include <string.h>
#include <stdio.h>
int main (void) {
	char string1[] = "S+<F2>tri31ng1";
	char string2[] = "StrinASAg2";
	char alfabeto[] = "200~abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char stringMinusculas[] = "";
	int counterOfAlphabetLetters = 0;
	int counterOfCapitalLetters = 0;
	for (int i = 0; i < strlen(string1); i++){	
		if((string1[i]>='a' &&  string1[i]<='z')||(string1[i]>='A' && string1[i]<='Z') ){
			counterOfAlphabetLetters++;
		}
		
	} 
	for(int i = 0; i < strlen(string2);i++){
		if(string2[i]>='A' && string2[i]<='Z'){
			counterOfCapitalLetters++;
		}
	} 
	
	for(int i = 0; i < strlen(string2);i++){
		if(string2[i]>='A' && string2[i]<='Z'){
		
		}
	} 


		

	
	printf("Numero de characteres do alfabeto da String:%s é %d\n ",string1 ,counterOfAlphabetLetters);

	printf("Numero de Letras maiusculas da string: %s é: %d\n", string2, counterOfCapitalLetters);

	return 0;

}

