# ANO não sei 

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
- b) São efetuadas 15 trocas entre elementos do array, para que seja ordenado por ordem crescente.**x**  
- c) São efetuadas 21 comparações entre elementos do array, para que seja ordenado por ordem crescente.   
- d) Nenhuma está correta.

## 7. Considere o seguinte array de 6 elementos, que se pretende ordenar usando a versão do algoritmo "Selectionsort" em que se começa por colocar o menor elemento na primeira posição. [ 6, 5, 4, 3, 2, 1 ]

Explicação: minIndex n + n-1 + .. + 1 
					 5 + 4  + 3 + 2 + 1 =15  

- a) São efetuadas 3 trocas entre elementos do array, para que seja ordenado por ordem crescente. 
- b) São efetuadas 15 comparações entre elementos do array, para que seja ordenado por ordem crescente.  
- c) Ambas estão corretas. **x**
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
c) Ambas estão corretas.  
d) Nenhuma está correta.   **x**

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


# ANO 2024
# Questões de Computação / Algoritmos

---

## 1. Sejam dadas duas funções t(n) e g(n), uma constante positiva c e um inteiro não negativo n0:

- [ ] (a) se t(n)<c⋅g(n), para todo o n>n0, então t(n) é da ordem de O(g(n)), i.e., t(n) pertence a O(g(n))
- [ ] (b) se t(n)<c⋅g(n), para todo o n>n0, então t(n) é da ordem de Ω(g(n)), i.e., t(n) pertence a Ω(g(n))
- [ ] (c) se t(n)≥c⋅g(n), para todo o n>n0, então t(n) é da ordem de O(g(n)), i.e., t(n) pertence a O(g(n))
- [x] (d) Nenhuma está correta

---

## 2. Considere muitas instâncias distintas de um mesmo problema, todas da mesma dimensão e que foram resolvidas usando o mesmo algoritmo:

- [x] (a) Se o esforço computacional para resolver cada instância não foi idêntico, fará sentido analisar a eficiência computacional do algoritmo para o pior caso e o caso médio.
- [ ] (b) Se o esforço computacional para resolver cada uma dessas instâncias não dependeu da configuração de cada instância, não faz qualquer sentido falar em pior caso e em caso médio.
- [ ] (c) Ambas estão corretas
- [ ] (d) Nenhuma está correta

---

## 3. A tabela seguinte representa o número de operações básicas efetuadas para sucessivos valores de n:

| n      | 1  | 2  | 4  | 8  | 16 | 32 | 64 | 128 | 256 | 512 | 1024 |
|--------|----|----|----|----|----|----|----|-----|-----|-----|------|
| M(n)   | 0  | 1  | 3  | 5  | 7  | 9  | 11 | 13  | 15  | 17  | 19   |

Trata-se de um algoritmo com ordem de complexidade:

- [x] (a) logarítmica
- [ ] (b) linear
- [ ] (c) quadrática
- [ ] (d) Nenhuma está correta

---

## 4. A tabela seguinte representa o número de operações básicas efetuadas para sucessivos valores de n:

| n      | 1  | 2  | 4  | 8  | 16  | 32   | 64   | 128   | 256   |
|--------|----|----|----|----|-----|------|------|-------|-------|
| M(n)   | 3  | 7  | 21 | 73 | 273 | 1057 | 4161 | 16513 | 65793 |

Trata-se de um algoritmo com ordem de complexidade:

- [ ] (a) logarítmica
- [ ] (b) linear
- [x] (c) quadrática
- [ ] (d) Nenhuma está correta

---

## 5. Quando se usa um algoritmo de procura exaustiva (exhaustive search), é geralmente necessário enumerar todas as possíveis soluções de um conjunto de n elementos; um passo essencial para a resolução do problema envolve a geração de todas as permutações desses elementos. Um exemplo de um problema onde isto é aplicado é:

- [ ] (a) Problema da Mochila (The Knapsack Problem)
- [x] (b) Problema do Caixeiro Viajante (The Traveling Salesman Problem)
- [ ] (c) Ambas estão corretas
- [ ] (d) Nenhuma está correta

---

## 6. Em C++, o algoritmo std::count permite:

- [x] (a) Contar o número de ocorrências de um elemento específico (target) de uma estrutura de dados (container)
- [ ] (b) Contar quantos elementos de uma estrutura de dados (container) satisfazem uma dada condição
- [ ] (c) Contar os elementos únicos de uma estrutura de dados (container)
- [ ] (d) Nenhuma está correta

---

## Verdadeiro x  / Falso vazio

- [ ] (1) Um algoritmo é definido por uma sequência de instruções possivelmente ambíguas, que permite resolver instâncias de um problema num espaço de tempo finito.

Explicação: Não pode haver ambíguidade.

- [x] (2) Uma função t(n) pertence a Θ(g(n)) se existirem constantes c1, c2 >0 e n0 tal que c1 g(n) ≤ t(n) ≤ c2 g(n), para todo o n>n0.

- [x] (3) Ao efetuar, usando o algoritmo clássico, o produto de matrizes A×B=C, em que a matriz A tem 10 linhas e 20 colunas e a matriz B tem 20 linhas e 10 colunas, são efetuadas 2000 multiplicações.

- [ ] (4) Um algoritmo que gera todas as permutações de um conjunto de n elementos é um algoritmo de ordem de complexidade exponencial, i.e., pertence a O(2^n).

Explicação: Pertence a O(n!) 

- [x] (5) No caso médio, a versão iterativa do algoritmo de Pesquisa Binária num array ordenado tem complexidade O(log n).

- [ ] (6) Quando se usa a técnica da programação dinâmica, é necessário resolver repetidas vezes os mesmos sub-problemas.

Explicação: Programação Dinâmica resolve uma única os sub-problemas

- [ ] (7) 0+3+6+...+3(n−1)+3n = 3(n^2−n)/n.

Explicação: 3 SUM(i) = (n + 1)n/ 2 * 3 
	0->n

- [x] (8) 1+2+4+...+2^(n−1) = 2^n−1.

 número de n bits em binário    01111...11111111  = 10000....000000 - 1 

- [ ] (9) Quando se ordena um dado array de n elementos usando o algoritmo HeapSort, o primeiro passo é, habitualmente, transformar o array dado numa MIN-HEAP.

Explicação é usado MAX-HEAP

- [x] (10) Pretende-se ordenar um dado array de n elementos, todos distintos, e que se encontram armazenados de modo aleatório. Se for usado o algoritmo HeapSort, a ordem de complexidade dessa tarefa será O(n log n).

- [x] (11) Numa árvore binária, o número máximo de nós do nível i é 2^i, considerando que a raiz da árvore pertence ao nível zero (i=0).

- [ ] (12) Na travessia pós-ordem de uma árvore binária, todos os elementos da subárvore direita da raiz são visitados antes dos elementos da subárvore esquerda da raiz.

Explicação: Primeiro primeiro são visitados todos os elementos da esquerda depois da direita 

- [x] (13) Numa árvore binária de pesquisa ("Binary Search Tree"), a subárvore esquerda de um dado nó não pode conter elementos de valor superior a esse mesmo nó.


- [ ] (14) Uma árvore AVL é uma árvore binária equilibrada em altura em que, para cada nó, as alturas das suas duas subárvores diferem, sempre, de uma unidade.

Explicação: não é sempre pode ser uma unidade ou 0 

- [x] (15) Um grafo (não orientado) completo com n vértices tem (n^2−n)/2 arestas. 


Explicação: n * (cada vertice tem n-1 aretas)(n-1) / 2 divide-se por dois porque está se a contar por exemplo vertice A - B e B - A logo divide-se por 2   


- [x] (16) Se um grafo orientado é fortemente conexo, não tem qualquer vértice isolado.



- [x] (17) Dado um grafo, um circuito Hamiltoniano é um caminho que, partindo de um qualquer nó, atravessa, uma única vez, cada um dos outros vértices do grafo e regressa ao inicial.



- [x] (18) Considere um grafo orientado G(V,E) representado usando uma lista de vértices e, para cada vértice, a sua lista de adjacências. Se o grafo for completo, existem V listas de adjacências e o número total de nós definindo as várias listas de adjacências é V×(V−1).


- [ ] (19) A travessia por níveis ("Breadth-First Traversal") de um grafo orientado é habitualmente realizada usando uma pilha ("Stack").


Explicação: usada uma fila 


- [x] (20) Instâncias de grande dimensão do Problema do Caixeiro Viajante ("The Traveling Salesperson Problem") não são habitualmente resolvíveis em tempo útil.

