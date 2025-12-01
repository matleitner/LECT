#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

int C(int n, int p){
	assert(n>=0);	
	assert(p>=0);	
	if (p == n || p == 0) return 1;
	return C(n-1,p-1) + C(n-1, p);
	

}

int main(int argc, char *argv[]){
	printf("%d\n", C(atoi(argv[1]),atoi(argv[2])));


	return 0;
}
