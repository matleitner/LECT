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
