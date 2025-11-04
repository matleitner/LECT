#include <stdio.h>
static const int SIZE = 8;

void main(void){

       static int val[] = {8, 4, 15, -1987, 327, -9, 27, 16};
       int i, v;

       i = 0;
       do {
               v = val[i];
               val[i] = val[i+SIZE/2];
               val[i+SIZE/2] = v;
       } while(++i < (SIZE / 2));

       printf("Result is: ");
       i = 0;
       do {
               printf("%d",val[i++]);
               printf(",");
       } while (i < SIZE);
	printf("\n");

}

