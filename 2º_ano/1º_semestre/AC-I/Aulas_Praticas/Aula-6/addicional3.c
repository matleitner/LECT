#include <stdio.h>
// 0x0000001    "ao", "asdasd" 
                
int main(int argc, char **argv){
	char** p = argv +1;
        int countChars = 0;
        int length = 0 ;
        char* stringMaior;
        int biggestChar = 0;
        char** pUltimo = (argv + argc); 
        
	while(p < pUltimo){
                char* pStr = *p;
                char* pointerIncial = pStr; 
                do{
                        if(*pStr!='\0'){
                                length++;
                                if(('a'<=*pStr  && 'z'>=*pStr) || ('Z'>=*pStr && 'A' <=*pStr)) countChars++;
                                pStr++;
                        }

                }while(*pStr != '\0');

                if(biggestChar <length) {
                        stringMaior = pointerIncial;
                        biggestChar = length;

                        
                }
                
                printf("Numero de caracteres de (%s): %d\n", pointerIncial, length);
                printf("Numero de letras de (%s): %d\n", pointerIncial, countChars);
                p++;

                length = 0;
                countChars = 0;
        }
 
        
        printf("String maior destas todas é: %s\n", stringMaior);
        
        
        //char* p = *(argv+1);// p = argv[1]
        //char* pUlitmo = *(argv +argc-1);// p = argv[argc-1]

        
        //printf("%c\n",*(*++argv));
        //printf("%s\n", *argv);
        //printf("%s\n", pUltimo);
        return 0;


}

