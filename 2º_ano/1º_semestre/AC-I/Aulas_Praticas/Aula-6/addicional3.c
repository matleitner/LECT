#include <stdio.h>

int main(int argc, char **argv){
	char** p = argv +1;
        int countChars = 0;
        int length = 0 ;
        char* stringMaior;
        int biggestChar = 0;
        
	while((**p) != '\0'){
                

                do{
                        if(**argv!='\0'){
                                length++;
                                if(('a'<=**argv  && 'z'>=**argv) || ('Z'>=**argv && 'A' <=**argv)) countChars++;
                        **argv++;
                        }

}while(**argv != '\0');

                if(biggestChar <length) {
                        stringMaior = *argv;
                        biggestChar = length;


                }
                printf("Numero de caracteres de (%s): %d\n", *argv, length);
                printf("Numero de letras de (%s): %d\n", *argv, countChars);

                length = 0;
                countChars = 0;
		**p++;
}
        printf("String maior destas todas é: %s\n", stringMaior);




}

