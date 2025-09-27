#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//Conte os caracteres da segunda string que são letras maiúsculas.
char* stringMinusculasMaker(char* str1);


int main (void) {
	char string1[50];
	char string2[50];
	char alfabeto[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	scanf("%s",string1);
	scanf("%s", string2);	
	int counterOfAlphabetLetters = 0;
	int counterOfCapitalLetters = 0;
	char*  stringMinusculas = stringMinusculasMaker(string2);
	
	
	int len1 = strlen(string1);
	int len2 = strlen(string2);
	
	//Conte os caracteres da primeira string que são letras do alfabeto.
	for (int i = 0; i < len1; i++){	
		if((string1[i]>='a' &&  string1[i]<='z')||(string1[i]>='A' && string1[i]<='Z') ){
			counterOfAlphabetLetters++;
		}
		
	} 

	//Conte os caracteres da segunda string que são letras maiúsculas.
	for(int i = 0; i < len2;i++){
		if(string2[i]>='A' && string2[i]<='Z'){
			counterOfCapitalLetters++;
		}
	} 


	//Compare as duas strings resultantes e escreva uma mensagem indicando que são iguais, ou apresentando as duas strings na sua ordem lexicográfica
	
	
	if(strcmp(string1,string2)>0) printf("A string %s é maior que %s\n", string1, string2);
	else if(strcmp(string1,string2)<0) printf("A string %s é menor que %s\n",string1, string2);
	else printf("São iguais\n");
	

	//Crie uma cópia da segunda string
	char copy[50];

	strcpy( copy, string2 );
	

	
	
		
	printf("Numero de characteres do alfabeto da String:%s é %d\n",string1 ,counterOfAlphabetLetters);

	printf("Numero de Letras maiusculas da string: %s é: %d\n", string2, counterOfCapitalLetters);
	printf("String em minusculas: %s\n",stringMinusculas);
	printf("Cópia da 2ª string: %s\n",copy);
	
	
	strcat(copy, string2);	
	printf("Concatenação : %s\n",copy);
	free(stringMinusculas);
	return 0;

}



char* stringMinusculasMaker(char* str1 ){
	char* stringMinusculas= malloc(strlen(str1)+1);	
	for(int i = 0; i < strlen(str1);i++){
		if(str1[i]>='A' && str1[i]<='Z'){
			stringMinusculas[i] = str1[i]+32;
		}
		else stringMinusculas[i] = str1[i];
	} 

	stringMinusculas[strlen(str1)] = '\0';
	return stringMinusculas;



}
