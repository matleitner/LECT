# Algoritmos Recursivos

Oferecem soluções concisas e elegantes

Decomposição em subproblemas

# Mergesort

Ordenar um array / lista
- Se o tamanho é 0 ou 1, já está ordenada
- Caso contrário, subdividir em duas “metades”
- Aprox. do mesmo tamanho !!
- Ordenar recusivamente cada “metade”
- Fundir as duas “metades” ordenadas num só array / lista
- Questão : usar ou não um array / lista adicional ?

```c
void merge(int* A, int* tmpA, int lPos, int rPos, int rEnd) {
	int lEnd = rPos -1;
	int tmpPos = lPos;
	int nElements = rEnd - lPos +1;
	
	while(lPos <= lEnd && rPos <= rEnd) {
		if(A[lPos] <= A[rPos]) 
			tmpA[tmpPos++] = A[lPos++];
		else
			tmpA[tmpPos++] = A[rPos++];	
	}
	while (lPos <= lEnd) 
		tmpA[tmpPos++] = A[lPos++];
	while (rPos <=rEnd) 	
		tmpA[tmpPos++] = A[rPos++];
	
	for (int i = 0; i < nElements; i++, rEnd--)
		A[rEnd] = tmpA[rEnd];
}


void mergeSort(int* A, int* tmpA, int left, int right) {
	
	if(left<right) {
		int center = (left + right) / 2;
	
		mergeSort(A, tmpA, left, center);
		mergeSort(A,tmpA, center+1, right);
		merge(A, tmpA, left, center + 1, right);
	}

}


``` 



## Diminuir-para-Reinar / Decrease-and-Conquer

- Resolver 1 só subproblema em cada passo do processo recursivo
- Lista / cadeia de chamadas recursivas

## Dividir-para-Reinar / Divide-and-Conquer

- Resolver 2 ou mais subproblemas em cada passo do processo recursivo
- Árvore de chamadas recursivas

## The Master Theorem 

Dada uma recorrência, para o caso particular $n = b^k, k\geq1$

$T(1) = c$

$T(n) = a\ \ T(\frac{n}{b}) + f(n)$

$a \geq 1, b\geq 2, c \gt 0$


### Teorema se $f(n)$ in $\Theta(n^d)$, em que $d \geq 0$ então
$$ T(n) \ in \ \Theta (n^d), se \ a \lt b^d $$
$$ T(n) \ in \ \Theta (n^d \log n), se \ a = b^d $$
$$ T(n) \ in \ \Theta (n^{\log_b{a}}), se \ a \gt b^d $$


## Exemplo anterior

$$M(n) = 2\ M(n/2) + 1$$

$$ f(n) = 1,\ f(n) \ in \ \Theta(n⁰), d = 0 $$
$$ a = 2, b = 2, a \gt b^d $$

$$ M(n) \ in\  \Theta (n)$$

## Smooth functions

Função eventualmente não-decrescente
$$f(n_1) \leq f(n_2),\ para\ qualquer\ n_2 \gt n_1 \geq n_0$$

Função "smooth"

1) $f(n)$ é eventualmente não-decrescente
2) $f(2n)$ in $\Theta(f(n)) $f(2n)\ e\ f(n)$ têm a mesma ordem de complexidade

Exemplos
-  $\log n,\ n,\ n\ \log n\ e\ n^k$ são funções smooth
- $a^n$ não é

