# Programação dinâmica

Estratégia algorítmica genérica
> Aplicável a
> > Cálculo de recorrências
> > Resolução de problemas de otimização combinatória
> Ideia : armazenar e reutilizar resultados “anteriores” usando
> um array local
> > Array 1D / 2D /

## Exemplo números de fibonacci 



```c
long unsigned int fibonacci(unsigned int n) {
	long unsigned int fib[n+1];
	
	fib[0] = 0;
	fib[1] = 1;
	
	for(long unsinged int i = 2; i<= n; i++){
		fib[i] = fib[i-1] + fib[i-2];
	}
	return fib[n];

}

```


# Memoization 

- Resultados de uma função são memorizados para uso futuro
- I.e., evita-se o cálculo de resultados (intermédios ou finais)
obtidos no processamento de inputs anteriores
- Usar um array global / uma cache para armazenar os resultados
calculados
- Como inicializar ?
- Recursividade + Programação Dinâmica


```c
#define SIZE 100

long int fib_Cache[SIZE];

void inicializeCache(void) {
	for(size_t i = 0; i < SIZE; i++){
		fib_Cache[i] = -1;
	}

long int fibonacci(unsigned int n){
	if(fib_Cache[n] != -1) return fib_Cache[n];

	long int r;
	if(n == 0) r = 0;
	else if ( n == 1) r = 1;
	else {
	
		N_SOMAS++; 
		r = fibonacci(n-2) + fibonacci(n-1);
	}
	fib_Cache[n] = r;	
	
	return r;
}
}

```
