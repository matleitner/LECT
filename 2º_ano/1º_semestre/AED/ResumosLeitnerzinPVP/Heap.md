# Binary Heaps 

Usados para representar filas com prioridade usando árvores binárias
completas

- O que são ?
- Com um critério de ordem/prioridade particular
- Qual ?
- Elementos da heap habitualmente armazenados por níveis, num array
- Acesso aos filhos e ao pai de um nó através de índices
- Não são utilizados ponteiros !!
- Eficiência !!

## MIN-HEAP : O valor/chave de um nó não é superior ao do seus filhos

- A sequência de valores em qualquer caminho da raiz da árvore até
uma folha é não-decrescente
## MAX-HEAP : O valor/chave de um nó não é inferior ao do seus filhos
- A sequência de valores em qualquer caminho da raiz da árvore até
uma folha é não-crescente
- Podem existir valores/chaves repetidos !
			


				
			/ 2  \1
	/ 8
			\ 5  /5
10		  	 \3
 
	\ 	/	6
		7
			\ 1

## Representação usando um array:

|0|1|2|3|4|5|6|7|8|9| 
|--|--|--|--|--|--|--|--|--|--| 
 |10| 8| 7| 5| 2| 1| 6| 3| 5| 1| 

LeftChild(i) = 2 * i + 1, se existir
RightChild(i) = 2 * i + 2, se existir
Parent(i) = (i-1) div 2, i>0


# MIN-Heap 


```c
struct _Heap {
	void** array;
	int capacity;
	int size;
	compFunc compare;
	printFunc print;
};
	
typedef struct _Heap MinHeap;

typedef int (*compFunc)(const void* p1, const void* p2);

typedef void (*printFunc)(void* p);

...

```

# MAX-Heap insert
## Funções privadas (getters) de child e parent

```c
static inline int _child(int n, int c) { return 2 * n + c; }

static inline int _parent(int n) {
	assert(n>0);
	return (n - 1) / 2; 
}
```

```c
void MaxHeapInsert(MaxHeap* ph, void* item) {
	assert(!MaxHeapIsFull(ph));

	int n = ph->size;

	while (n > 0) {
		int p = _parent(n)
		if ( ph->compare(item, ph->array[p] <= 0) break;
		ph->array[n] = ph->array[p];

		n = p;
	}
	ph->array[n] = item;
	ph->size++;
}


void MaxHeapRemoveMax(MaxHeap* ph) {
	assert(!MaxHeapIsEmpty(ph));

	ph->size--;
	int n = 0;
	while(1) {
		int max = _child(n,1);
	
		if(!(max < ph->size)) break;
		
		if(ph->compare(ph->array[max + 1], ph->array[max] > 0) {
			max = max + 1;
		}
		if (!(ph->compare(ph->array[max], ph->array[ph->size]) > 0)) break;

		ph->array[n] = ph->array[max];

		n = max;
	}
	ph->array[n] = ph->array[ph->size];
	
	ph->array[ph->size] = NULL;


}
```


# HEAP-sort

Dado um array de n elementos

Construir uma MAX-HEAP // In-place, sem usar memória adicional !

Repetir (n – 1) vezes

Levar o maior elemento da MAX-HEAP para a posição final // 1 TROCA

Reorganizar os elementos não ordenados para MAX-HEAP // 1 x fixHeap

## heapBottomUp


```c
void fixHeap( int a[], int index, int n) {
	int child;
	for( int tmp = a[index]; leftChild(index) < n; index = child) {
		child = leftChild(index);
		if( child !=(n-1) && a[child + 1] > a[child] ) child++;
		if( tmp < a[child] ) a[index] = a[child];
		else break;
	} 
	array[index] = tmp;
}

void heapBottomUp ( int a[], int n ) {
	for(int i = n/2 - 1; i >= 0; i--)
			fixHeap(a,i,n);
}

void heapSort(int a[], int n ) {
	heapBottomUp( a, n );
	for(int i = n-1; i > 0; i--) {
		swap(&a[0], &a[i]);
		fixHeap(a,0, 1);
	}
}
```


## Complexidade 

A construção do MAX-Heap é O(N)
Ordenação é O(n log2 n) logo 

Heap-Sort é de O(n log2 n)
