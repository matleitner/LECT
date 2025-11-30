#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
static int mult= 0;
long int b_n(int b, int n){
	if(n == 1) return b; 
	
	if(n%2== 0){
		long int t = b_n(b, n/2);
		mult++;
		return	t * t;}
	long int t = b_n(b, (n-1)/2); 
	mult += 2;
	return b * t * t;

}
int main(int argc, char **argv){
		long int p = b_n(atoi(argv[1]), atoi(argv[2]));
		printf("%s^%s = %ld\nNum de multiplicações: %d\n", *(argv+1), *(argv +2), p , mult);
		return 0;


}
