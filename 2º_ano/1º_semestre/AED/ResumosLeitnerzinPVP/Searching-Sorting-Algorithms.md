# Search
# Linear Search 

```c
    int search( int a[], int n, int x) {
        for( int i=0; i<n; i++ ) {
            if( a[i] == x ) {
               return i;
            }
        }
        return -1
    }
```
### $B(n) = 1 $

### $W(n) = n$

## $A(n) = ? $

### 1º Cenário, o valor existe no array 

$$A(n) =\sum_{i=0}^{n-1}\frac{1}{n} \times (i +1) = \frac{n+1}{2} $$

### 2º Cenário, o valor pode não existir

$$A(n) =\sum_{i=0}^{n-1} \frac{p}{n} \times (i +1) + (1-p) \times n = \frac{p \times (n+1)}{2}+(1-p) \times n $$


# Binary search 



| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|--|--|--|--|--|--|--|--|
| 0 | 2 | 3 | 3 | 5 | 6 | 7 | 8 |

```c
int binSearch( int a[], int n, int x ) {    
    int left = 0; int right = n – 1;
    while( left <= right ) {
        int middle = (left + right) / 2;
        if(a[middle] == x) return middle;
        if(a[middle] > x) right = middle – 1;
        else left = middle + 1;
    }
    return -1;
}
```

## $B(n) = 1$

## $W(n) = 1 + \lfloor \log_2{n} \rfloor$  <br> $W(n) \in O(\log n) $ 




# Algoritmos de Ordenação

## Selection Sort

Procurar a última ocorrência do maior elemento
- Colocá-lo na última posição, se necessário, efetuando uma troca
- Repetir o processo para os restantes elementos
- Algoritmo in-place
- Variante: procurar a primeira ocorrência do menor elemento

```c

void selectionSort( int a[], int n ) {
    for( int k = n – 1; k > 0; k-- ) {
        int indMax = 0;
        for( int i = 1; i <= k; i++ ) {
            if( a[i] >= a[indMax] ) indMax = i;
        }
        if( indMax != k ) swap( &a[indMax], &a[k] );
    }
}
```
### Número de Comparações
$$\sum_{k=1}^{n-1}k  = \frac{n(n-1)}{2}= \frac{n²}{2}- \frac{n}{2}$$
$$O(n)$$

### Número de Trocas
$W_T(n) = n-1 \Rightarrow O(n)$

$A_T(n) = n-\ln n \Rightarrow O(n)$

$B_T(n) = 0 $

## Bubble sort

Percorrer o array da esquerda para a direita
- Trocar elementos adjacentes, se estiverem fora de ordem
- A última ocorrência do maior elemento fica na sua posição final
- Repetir o processo para os restantes elementos
- Parar logo que possível !
- Algoritmo in-place
- Shaker Sort : alternar o sentido : esquerda-direita / direita-esquerda


```c
void bubbleSort( int a[], int n ) {
    int k = n; int stop = 0;
    while( stop == 0 ) {
        stop = 1; k--;
        for( int i = 0; i < k; i++ )
            if( a[i] > a[i + 1] ) {
                swap( &a[i], &a[i + 1] );
                stop = 0;
            }
    }
}
```

### Número de Comparadções
$B_c(n) = n-1 \Rightarrow O(n) $

$ W_c(n) = \frac{n²-n}{2} \Rightarrow O(n²)$

$A_c(n) = \frac{1}{3} n² - \frac{1}{6} n $

### Número de Trocas 

$B_t(n) = 0$

$W_t(n) = W_c(n)$


## Insertion Sort 

 O elemento a[0] constitui um subconjunto de um só elemento
- Inserir ordenadamente o elemento a[1] nesse subconjunto
- 1 comparação + 0 ou 1 troca de posição
- Temos agora um subconjunto ordenado com dois elementos
- Repetir o processo, um a um, para os restantes elementos do array
- Algoritmo in-place
- Variante: começar na outra extremidade do array

```c
void insertElement( int sorted[], int n, int elem ) {
// Array sorted está ordenado
// Há espaço para acrescentar mais um elemento
    int i;
    for( i = n – 1; (i >= 0) && (elem < sorted[i]); i-- )
        sorted[i + 1] = sorted[i]
    sorted[i + 1] = elem;
}

void insertionSort( int a[], int n ) {
    for( int i = 1; i < n; i++ )
        if( a[i] < a[i – 1] )
            insertElement( a, i, a[i] );
}
```


### Número de Comparadções
$B_c(n) = n-1 $

$ W_c(n) = \frac{n-1}{2} \times (n+2)$

$A_c(n) = \frac{n²}{4} + \frac{7n}{4}$

### Número de Trocas 

$B_t(n) = 0$

$W_t(n) = W_c(n)$
