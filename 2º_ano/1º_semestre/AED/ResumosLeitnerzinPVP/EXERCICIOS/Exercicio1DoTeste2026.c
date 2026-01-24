	

#include <stdio.h>
#include <stdlib.h>

char* primeiroVogaisDepoisCOnsoantes(char* s, int n){
	int vowel[26] = {0};
	char* string= (char*)malloc(sizeof(char) *n); 	
	int j = 0;
		
	for(int i = 0; i < n; i++){
		if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' ){
			vowel[s[i]-'A'] = 1;
			string[j++] = s[i]; 	
		} 
	}
	
	for(int i = 0; i < n; i++){
		if(vowel[s[i]-'A'] == 0){
			string[j] = s[i];
			j++;
		}

}
	string[j] = '\0';

	return string;	

}




int main(void){
	char* s = "ABACAXI";
	int n = 7;
	char* out = primeiroVogaisDepoisCOnsoantes(s, n);
	printf("Output-> %s\n", out);
	free(out);	
	return 0;
}
