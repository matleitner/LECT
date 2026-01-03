## 1. Definições de Notação Assimptótica
## Sejam dadas duas funções, t(n) e g(n), uma constante positiva c e um inteiro não-negativo n0​.


- a) Se t(n)≤cg(n), para todo o n>n0​, então t(n) é da ordem de Ω(g(n)), i.e., t(n) pertence a Ω(g(n)). 
- b) Se t(n)≥cg(n), para todo o n>n0​, então t(n) é da ordem de O(g(n)), i.e., t(n) pertence a O(g(n)). 
- c) Ambas estão corretas. 
- d) Nenhuma está correta. **x**


## 2. Análise de Instâncias e Eficiência
## Considere (muitas) instâncias distintas de um mesmo problema, todas da mesma dimensão, e que foram resolvidas usando um mesmo algoritmo.

- a) Se o esforço computacional necessário para resolver cada uma dessas instâncias dependeu da configuração de cada instância, a análise da eficiência computacional do algoritmo implicará resultados distintos para o pior caso e para o caso médio. **x** 

- b) Se o esforço computacional necessário para resolver cada uma dessas instâncias foi idêntico, a análise da eficiência computacional do algoritmo implicará resultados distintos para o pior caso e para o caso médio.

- c) Ambas estão corretas.

- d) Nenhuma está correta.

## 3. Complexidade por Observação de Tabela (I)
A tabela abaixo apresenta o número de operações básicas efetuadas, por um determinado algoritmo, para sucessivos valores de n.
|N	|1	|2	|4	|8	|16	|32	|64	|128|	256	|512	|1024|
|--|--|--|--|--|--|--|--|--|--|--|--|

| M(n)	| 3	| 4	| 5	| 6	|7	| 8	| 9	| 10 | 11	| 12	| 13 |

Trata-se de um algoritmo com ordem de complexidade: 

- a) quadrática. 
- b) linear. 
- c) logarítmica. **x**  
- d) Nenhuma está correta.

## 4. Complexidade por Observação de Tabela (II)

A tabela abaixo apresenta o número de operações básicas efetuadas, por um determinado algoritmo, para sucessivos valores de n.
N	1	2	4	8	16	32	64	128	256
M(n)	4	12	40	144	544	2112	8320	33024	131584

Trata-se de um algoritmo com ordem de complexidade: 
- a) quadrática. **x**
- b) linear.
- c) logarítmica.
- d) Nenhuma está correta.


## 5. A tabela abaixo apresenta o número de operações básicas efetuadas, por um determinado algoritmo, para sucessivos valores de n.

n	1	2	3	4	5	6	7	8	9	10
M(n)	1	2	3	5	8	13	21	34	55	89


- a) Da tabela, obtém-se a seguinte relação recorrente para o número de operações, quando n>2: M(n)=M(n−1)+M(n−2). 
- b) Trata-se de um algoritmo com ordem de complexidade exponencial. 
- c) Ambas estão corretas.  **x** 
- d) Nenhuma está correta.


## 6. Considere o seguinte array de 6 elementos, que se pretende ordenar usando o algoritmo "Bubblesort". [ 6, 5, 4, 3, 2, 1 ]

- a) São efetuadas 5 trocas entre elementos do array, para que seja ordenado por ordem crescente. 
- b) São efetuadas 15 trocas entre elementos do array, para que seja ordenado por ordem crescente. 
- c) São efetuadas 21 comparações entre elementos do array, para que seja ordenado por ordem crescente.  **x** 
- d) Nenhuma está correta.

## 7. Considere o seguinte array de 6 elementos, que se pretende ordenar usando a versão do algoritmo "Selectionsort" em que se começa por colocar o menor elemento na primeira posição. [ 6, 5, 4, 3, 2, 1 ]

Explicação: minIndex n + n-1 + .. + 1 
					 5 + 4  + 3 + 2 + 1 =15  

- a) São efetuadas 3 trocas entre elementos do array, para que seja ordenado por ordem crescente. 
- b) São efetuadas 15 comparações entre elementos do array, para que seja ordenado por ordem crescente. **x** 
- c) Ambas estão corretas. 
- d) Nenhuma está correta.


## 8. Pretende-se ordenar um dado array de n elementos, todos distintos, e que se encontram armazenados de modo aleatório. A ordem de complexidade dessa tarefa depende do algoritmo escolhido, e será 

- a) O(n²), se for usado o algoritmo Bubblesort. 
- b) O(n²), se for usado o algoritmo de ordenação por seleção (Selectionsort). 
- c) O(nlogn), se for usado o algoritmo Heapsort. 
- d) Todas estão corretas. **x**

## 9. Pretende-se resolver o Problema das Torres de Hanói, para n discos. 


Explicação: 2^n-1

- a) Para n=2 é necessário efetuar 4 movimentos de discos. 
- b) Para n=3 é necessário efetuar 8 movimentos de discos. 
- c) O número de movimentos de discos efetuados é da ordem de O(2^n). **x** 
- d) Todas estão corretas.

## 10. Seja dada uma escada com n degraus, que podem ser subidos um a um, ou dois a dois, ou três a três, ou numa qualquer combinação dos movimentos anteriores (p.ex., numa escada com três degraus, pode subir-se um só degrau e depois dois de uma só vez). 

- a) Para n=3, é possível subir a escada apenas de 4 maneiras diferentes.  3, 2+ 1, 1+2, 1+1+1 **x**     

- b) Para n=4, é possível subir a escada apenas de 6 maneiras diferentes.  

3 depois 1, 1 + 3, 2 + 1 + 1, 1+ 2+ 1, 1+ 1+ 2, 1+1+1+1, 2+2        7 formas

- c) Ambas estão corretas. 

- d) Nenhuma está correta.

# Exercícios de Estruturas de Dados

---

## Questão 11

Seja dada uma **árvore binária total**, i.e., em que todos os níveis da árvore estão completamente preenchidos, com \(n\) nós.

a) O número de níveis da árvore é dado por \(\lfloor \log_2 n \rfloor\).  

b) O número de nós que são folhas da árvore é dado por \(n \div 2\), em que `div` é o operador que determina o quociente da divisão inteira. 

c) Ambas estão corretas.  

d) Nenhuma está correta. **x**

---

## Questão 12

Seja dada uma **árvore binária de altura equilibrada** que armazena, de modo **ordenado**, \(n\) números inteiros.

a) No pior caso, concluir que um dado número não pertence à árvore é uma operação de complexidade \(O(\log n)\).  
b) No pior caso, determinar o valor do menor elemento armazenado na árvore é uma operação de complexidade \(O(\log n)\).  
c) Ambas estão corretas.  **x**
d) Nenhuma está correta.

---

## Questão 13

O **array** abaixo armazena, por níveis, os elementos de uma **árvore ternária**:


| Índice | 0  | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 |
| ------ | -- | - | - | - | - | - | - | - | - | - | -- | -- | -- | -- | -- |
| Valor  | 10 | 6 | 9 | 2 | 5 | 7 | 8 | 0 | 1 | 3 | -  | -  | -  | -  | -  |


Valor: 10 6 9 2 5 7 8 0 1 3 - - - - -
filho[0] = 3i + 1; filho[1] = 3i +2; filho[2] = 3i + 3
pai[n] = (n-1)/3

a) O elemento de valor 0 é filho do elemento de valor 9.  
b) A árvore tem 7 folhas.  
c) Ambas estão corretas. **x**  
d) Nenhuma está correta.

---

## Questão 14

O **array** abaixo armazena, por níveis, os elementos de uma **árvore binária de procura (Binary Search Tree)**:
| Índice | 0 | 1 | 2  | 3 | 4 | 5  | 6  |
| ------ | - | - | -- | - | - | -- | -- |
| Valor  | 8 | 4 | 12 | 2 | 6 | 10 | 14 |


3 2 3 1 3 2 3 = 17 consultas

a) Se forem sucessivamente procurados cada um dos elementos do conjunto {2, 4, 6, 8, 10, 12, 14}, é efetuado um total de 17 consultas a elementos da árvore.  

b) Para procurar na árvore qualquer um dos elementos do conjunto {1, 3, 5, 7, 9, 11, 13, 15}, são sempre consultados 3 elementos, concluindo-se depois que o valor procurado não pertence à árvore.  

c) Ambas estão corretas.  **x**

d) Nenhuma está correta.

---

## Questão 15

Considere um grafo orientado \(G(V,E)\), representado usando a lista ordenada dos seus nós e, para cada nó, a sua lista ordenada de adjacências.


a) No pior caso, adicionar uma nova aresta ao grafo orientado é uma operação de complexidade \(O(V)\).  

b) No pior caso, verificar se um nó é isolado é uma operação de complexidade \(O(E)\).  

c) Ambas estão corretas. **x**  

d) Nenhuma está correta.

