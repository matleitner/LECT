# Grafo
Grafo, G(V, E) 

e_i = (v_j, v_k)
e_i é incidente em v_j e em v_k

### Número Máximo de arestas = V x (V - 1) / 2 

### Grau de um vértice

Número de arestas incidentes nesse vértice

### Grafo Regular

Todos os vértices têm o mesmo grau k;

## Passeio / Trajeto / Caminho 

- Um passeio é uma qualquer sequência de vértices adjacentes
 Comprimento do passeio: nº de arestas que o constituem

- Um trajeto é um passeio constituído por arestas distintas
 Um circuito é um trajeto de comprimento não nulo, que começa e
acaba no mesmo vértice

- Um caminho é um passeio constituído por arestas e vertices
distintos
 Um ciclo é um caminho de comprimento não nulo, que começa e
acaba no mesmo vértice

## Grafo conexo

- Existe um caminho entre cada par de vértices

- Um único componente conexo

# Grafos Orientados

 G(V,E)
 Grafo orientado

## As arestas orientadas definem uma adjacência unidirecional
 e i = ( v j , v k)
 vj é o vértice origem e vk o vértice destino
 vk é adjacente a vj
 ei é incidente em vk

## Número máximo de arestas = V * (V - 1) 

## Passeio / Caminho
- Um passeio orientado é uma sequência de vértices
 Cada vértice (exceto o primeiro) é adjacente ao seu predecessor

- Caminho orientado : arestas e vértices distintos
- Ciclo orientado : caminho orientado com o mesmo vértice
inicial e final

## Conectividade

- Grafo orientado fracamente conexo

 Substituir as arestas orientadas por arestas não-orientadas

 O grafo resultante é conexo
-  Grafo orientado fortemente conexo

Existe um caminho entre cada par de vértices

Vértices mutuamente alcançáveis !!

Um único componente fortemente conexo

# TAD Grafo 


```c

struct _Edge {
	unsigned int adjVertex<,
	int weight;
};

struct _Vertex {
	unsigned int id;
	unsigned int inDegree;
	unsigned int outDegree;
	List* edgesList;
};

struct _GraphHeader {
	unsigned short isDigraph;
	unsigned short isComplete;
	unsigned short isWeighted;
	unsigned int numVertices;
	unsigned int numEdges;
	List* verticesList;
};
```
# Travessia em profundidade DFS

Travessia em Profundidade (vértice v)

	Criar um STACK vazio

	Push(stack, v)

	// Vértice inicial

	Marcar v como visitado

	Enquanto NãoVazio(stack) fazer

		v = Pop(stack)

		Para cada vértice w adjacente a v

			Se w não está marcado como visitado

			Então Push(stack, w)

				Marcar w como visitado

 

# Travessia por níveis BFS

Travessia por Níveis(vértice v)

	Criar FILA vazia

	Enqueue(queue, v)         // Vértice inicial
	
	Marcar v como visitado
		
	Enquanto NãoVazia(queue) fazer
		
		v = Dequeue(queue)

		Para cada vértice w adjacente a v
			
			Se w não está marcado como visitado

			Então Enqueue(queue, w)
	
				Marcar w como visitado

Algoritmo útil para descobrir caminho mais curto 


# Procura exaustiva 
c <- gerar a primeira solução candidata
enquanto ( c é candidata ) faz
	se (c é uma solução válida) 
	entao imprimir (c) 
	c<- gerar a próxima solução candidata, se existir
