<!--Leitner-->

# Algoritmos

O que é um algoritmo? 

Sequência de instruções não ambíguas;

Permitem atingir um objetivo;

Num espaço de tempo finito;

# Análise da Complexidade


## Análise exprimental 


- Testes computacionais com diferentes tipos de instâncias / dados de entrada
- Contar o número de operações significativas / Registar o tempo de execução
- Analisar os resultados
- Classificar o algoritmo

## Análise formal 

- Escolher uma operação significativa
- Obter uma expressão matemática para o número de vezes que é executada, em função do "tamanho" dos dados
- CLassificar o algoritmo


## Classes de complexidade mais habituais

- 1
- n
- log n
- Vn
- n²
- 2^N
- n!

# Análise de Complexidade de procura do Maior Elemento de um Array não Ordenado


```c
	int searchMax(int array[], int n){
			int maxIndex = 0;
			for(int i = q; i<n; i++){
				if(array[i] > array[maxIndex]) maxValue = i;
			}
	}

```

Quantas atribuuções à variável maxIndex?

**Melhor caso**: 1 atribuição
**Pior caso**: n atribuições
**Caso Médio**: (1+2+3+4+5+...+n) / n = (n + 1) / 2

## Best case, Worst case

B(n) = min t(I)  I pertecne a Dn conjunto de instâncias de dimensão n

W(n) = máx t(I) I pertence a Dn


## Average case


A(n) = ∑( p(I) x t(I) ) I pertence a Dn

# Ordem de Complexidade

Classificar a eficiência de um algoritmo para instâncias de grande dimensão.

| n | log₂ n | n | n log₂ n | n² | n³ | 2ⁿ | n! |
|---|--------|---|----------|----|----|----|----|
| 10 | 3.3 | 10 | 3.3 × 10¹ | 10² | 10³ | 10³ | 3.6 × 10⁶ |
| 10² | 6.6 | 10² | 6.6 × 10² | 10⁴ | 10⁶ | 1.3 × 10³⁰ | 9.3 × 10¹⁵⁷ |
| 10³ | 10 | 10³ | 10⁴ | 10⁶ | 10⁹ | ? | ? |
| 10⁴ | 13 | 10⁴ | 1.3 × 10⁵ | 10⁸ | 10¹² | ? | ? |
| 10⁵ | 17 | 10⁵ | 1.7 × 10⁶ | 10¹⁰ | 10¹⁵ | ? | ? |
| 10⁶ | 20 | 10⁶ | 2.0 × 10⁷ | 10¹² | 10¹⁸ | ? | ? |

___ 

## Notação habitual

- O(n)
- Ω(n)
- Θ(n)

# Big-Oh: t(n) ∈ O(g(n))

- Majorante / Limite superior 

- Conjunto de todas as funções com a mesma ordem de crescimento g(n) ou com uma ordem de crescimento inferior

- t(n) ≤ c g(n) para todo n ≥ n0, c é uma constante positiva

- t(n), g(n) funções não negativas sobre o conjunto dos números naturais

# Big-Omega: t(n) ∈ Ω(g(n))

- Minorante / Limite inferior

- Conjunto de todas as funções com a mesma ordem de crescimento que g(n) ou com uma ordem de crescimento superior;

- t(n) ≥ c g(n), para todo o n ≥ n0

# Big-Theta: t(n) ∈ Θ(g(n))

- Enquadramento  

- conjunto de todas as funções com a mesma ordem de crescimento que g(n)

- c1 g(n) ≤ t(n) ≤ c2 g(n), para todo o n ≥ n0, c1, c2, constantes positivas

- t(n) ∈ O(g(n)) e t(n) ∈ Ω(g(n)) 

___

# Notação – Exemplos

| notation | provides | example | shorthand for | used to |
|----------|----------|---------|---------------|---------|
| **Big Theta** | asymptotic order of growth | Θ(N²) | ½ N²<br>10 N²<br>5 N² + 22 N log N + 3N<br>⋮ | classify algorithms |
| **Big Oh** | Θ(N²) and smaller | O(N²) | 10 N²<br>100 N<br>22 N log N + 3 N<br>⋮ | develop upper bounds |
| **Big Omega** | Θ(N²) and larger | Ω(N²) | ½ N²<br>N⁵<br>N³ + 22 N log N + 3 N<br>⋮ | develop lower bounds |







