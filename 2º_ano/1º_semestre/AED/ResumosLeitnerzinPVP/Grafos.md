# Grafo



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
