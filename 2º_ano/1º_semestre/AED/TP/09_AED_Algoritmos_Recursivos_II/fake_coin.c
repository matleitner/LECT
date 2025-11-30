#include <stdio.h>

#include <stdlib.h>
// retorna o index da moeda falsa

int fake_coin(int *coins, int n){
	int coin_a = n-1;  
	int coin_b = n-2;
	int coin_c = n-3;
	if(coins[coin_a] == coins[coin_b] && coins[coin_c] != coins[coin_a]) return coin_c;
	if(coins[coin_a] == coins[coin_c] && coins[coin_c] != coins[coin_b]) return coin_b;
	if(coins[coin_b] == coins[coin_c] && coins[coin_c] != coins[coin_a]) return coin_a;
	if( n>3) return fake_coin(coins, n-3);

	return -1;
}  

int main(void){
	int array[] = {1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1}; 
	int n = 23;
	printf("%d\n", fake_coin(array, n));

	return 0;
}
