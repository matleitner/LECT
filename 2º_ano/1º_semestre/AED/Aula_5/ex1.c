#include <stdio.h>
#include <assert.h>

int primeira_recursiva(int n,int* counter_1){
	assert(n>0);	
	(*counter_1)++;
	if(n == 1) return 1;
	return primeira_recursiva(n/2, counter_1) + n;
}

int segunda_recursiva(int n, int* counter_2){
	assert(n>0);
	(*counter_2)++;
	if (n == 1) return 1;
	return segunda_recursiva(n/2, counter_2) + segunda_recursiva((n+1)/2, counter_2) + n;
}

int terceira_recursiva(int n, int* counter_3){
	assert(n>0);
	
	(*counter_3)++;
	
	if(n==1) return 1;

	if (n%2!= 0){
		return terceira_recursiva(n/2, counter_3) + terceira_recursiva((n+1)/2, counter_3) + n;
		}
	
	return 2 * terceira_recursiva(n/2, counter_3) +n;

}

int main(void){



	int a, b,c;

	printf(" N\t\t1ª funcao\tNº de chamadas\t|\t2ªfuncao\tNº de chamadas\t|\t3ªfuncao\tNº chamadas\n");

	for(int i = 1; i <= 16; i++){
		
		int	counter_1 = 0;
		int counter_2 = 0;
		int counter_3 = 0;
			
		a = primeira_recursiva(i,&counter_1);
		b =  segunda_recursiva(i, &counter_2);
		c = terceira_recursiva(i,&counter_3);	

		printf("%2d %20d %20d    |   %12d     %16d   |%15d %15d\n",i,a, counter_1, b, counter_2, c,counter_3);	

	}
	return 0;
}
/*
	 N		1ª funcao	Nº de chamadas	|	2ªfuncao	Nº de chamadas	|	3ªfuncao	Nº chamadas
 1                    1                    0    |              1                    0   |              1               0
 2                    3                    1    |              4                    2   |              4               1
 3                    4                    1    |              8                    4   |              8               3
 4                    7                    2    |             12                    6   |             12               2
 5                    8                    2    |             17                    8   |             17               6
 6                   10                    2    |             22                   10   |             22               4
 7                   11                    2    |             27                   12   |             27               7
 8                   15                    3    |             32                   14   |             32               3
 9                   16                    3    |             38                   16   |             38              10
10                   18                    3    |             44                   18   |             44               7
11                   19                    3    |             50                   20   |             50              12
12                   22                    3    |             56                   22   |             56               5
13                   23                    3    |             62                   24   |             62              13
14                   25                    3    |             68                   26   |             68               8
15                   26                    3    |             74                   28   |             74              12
16                   31                    4    |             80                   30   |             80               4


na 1ª função
análise experimental:
	n -> infinito, chamadas -> log[2]n
	O(log[2]n)

analise formal:
	C(1) = 1 (chamada)
	C(2) = 1 + C(2/2) = 1 + C(1) = 2 (- 1) 
	C(3) = 1 + C(3/2) = 1 + C(1) = 2 (- 1)
	C(4) = 1 + C(4/2) = 1 + C(2) = 3 (- 1)
	C(8) = 1 + C(8/2) = 1 + C(4) = 4 (- 1)
	R(n) = 1 + C(n/2) = log[2]n  

	logo, O(log[2]n)
--------------------------------------------
na 2ª função
analise experimental 
	n -> infinito, ch -> 2(n -1)
	O(n)

analise formal
	C(1) =  1
	C(2) =  1 + C(2/2) + C((2+1)/2) = 1 + C(1) + C(1) = 3
       	C(3) =  1 + C(3/2) + C(4/2) = 1 + C(1) + C(2) = 1 + 1 + 3	
	C(4) =  1 + C(2) + C(2) = 7
	C(8) =  1 + C(4) + C(4)  = 15
	C(16)=  1 + C(8) + C(8)  =  
	R(n) =  1 + C(n/2) + C((n+1)/2) =  1 + 2C(n/2) = 1 + 2 * (2 ^log[2]n -1) = 1 + 2n - 2 = 2 n - 1

*/
