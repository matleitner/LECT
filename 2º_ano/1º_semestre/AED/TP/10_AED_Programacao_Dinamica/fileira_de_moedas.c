#include <stdio.h>

typedef long unsigned int longuint;


/*

O Problema da Fileira de Moedas

* Fileira de n moedas
* Valores inteiros c1, c2, ..., cn
* Pode haver moedas repetidas

* Objetivo: Escolher moedas de modo a obter o maior valor total possível
* Otimização combinatória: problema de maximização
* Restrição: Não podem ser escolhidas duas moedas adjacentes

Valor da solução ótima – Recorrência

* Como obter uma recorrência para o valor da solução ótima?
* V(n) = ?
* Maior valor total que se obtém de uma fileira com n moedas

* Casos triviais?
* n-ésima moeda é escolhida / não é escolhida?

O Problema da Fileira de Moedas

V(0) = 0
V(1) = c1
V(n) = max { cn + V(n – 2), V(n – 1) }, para n > 1
* V(i) representa o valor da solução ótima, considerando as primeiras i moedas
* Exemplo: 5, 1, 2, 10, 6, 2
* V(6) = ?

*/

longuint recursive(int *coins, int n){
	
	if(n == 0) return 0;
	if(n == 1) return *(coins+n);
	return (coins[n] + recursive(coins, n-2) > recursive(coins, n-1)) ? coins[n] + recursive(coins, n-2) : recursive(coins, n-1);
}

longuint  dinamica(int *coins, int n){
	longuint V[n+1];
	
	V[0] = 0;
	V[1] = coins[0];
	for(unsigned int i = 2; i<=n; i++){
		V[i] = (coins[i-1]+ V[i-2]> V[i-1] ? (coins[i-1] + V[i-2]) : V[i-1]);

	}

 	int i = n;
    printf("Moedas escolhidas: ");
    while (i >= 1) {
        if (V[i] == V[i-1]) {
            i -= 1;
        } else {
            printf("%d ", coins[i-1]);
            i -= 2;
        }
    }
	return V[n];
}


int main(void){
	int coins[] = {5, 1, 2, 10, 6, 2,1,2,3,45,1,23,123,2,4};
	printf("%ld\n", dinamica(coins, 15));
	


	return 0;
}
