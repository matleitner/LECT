# Árvores Binárias
				
Algumas propriedades das árvores binárias

Nº máximo de nós no nível i  $2^i$
Nº máximo de nós numa árvore de altura h   $2^(h+1)-1$
Nº mínimo de nós numa árvore de altura h   h + 1

$$h + 1 <= n <= 2^(h + 1) -1$$ 

# Estrutura Árvore Binária 

```c
struct _TreeNode {
	ItemType item;
	struct _TreeNode* left;
	struct _TreeNode* right;
	
};
```

## Algoritmos recursivos

- Contar o nº de nós de uma árvore;
- Determinar a altura de uma árvore;
- Destruir uma árvore;
- Verificar se duas árvores são iguais;


### Contar o nº de nós de uma árvore 


```c
int TreeGetNumberOfNodes(const Tree* root) {
	if (root == NULL) return 0;
	return 1 + TreeGetNumberOfNodes(root->left) + TreeNumberOfNodes(root->right);
}
```

### Determinar a altura


```c
int TreeGetHeight(const Tree* root) {
	if(root == NULL) return -1;
	int heightLeftSubTree = TreeGetHeight(root->left);

	int heightRightSubTree = TreeGetHeight(root->right);

	if (heightLeftSubTree > heightRightSubTree) {
		return 1 + heightLeftSubTree;
	}
	return 1 + heightRightSubTree;
}
```

### Destruir árvore


```c
void TreeDestroy(Tree** pRoot) {
	Tree* root = *pRoot;

	if (root == NULL) return;
	TreeDestroy(&(root->left));
	TreeDestroy(&(root->right));

	free(root);
	*pRoot = NULL;
}
```


### Verificar se árvores são iguais


```c
void TreeEquals(const Tree* root1, Tree* root2) {
	if(root1 == NULL && root2 == NULL) return 1;
	if(root1 == NULL || root2 == NULL) return 0; 


	if(root1->item != root2->item ) {
		return 0;
	}

	return TreeEquals(root1->left, root2->left) && TreeEquals(root1->right, root2->right);
}
```


# Representação de expressões 

INFIXA : operando operador operando
PREFIXA : operador operando operando
POSFIXA : operando operando operador


## Ordem da visita para o nó da raiz e as subárvores

### Travessia em pré-ordem (NLR) 

(+(*(+ab)c)7)

### Travessia em-ordem (LNR)

a + b * c + 7
 
### Travessia em pós-ordem (LRN)

(((a b +) c *) 7 +)

# Travessia em profundidade 

|DFS Postorder|DFS Preorder| DFS Inorder|
|--|--|--|
|bottom->top left->right|top->bottom ->top left->right| left->node ->right|




# Travessia por níveis

BFS 

left-> right 

top-> bottom


# Estrategia DFS BFS (usando TADs auxiliares)

 
- Criar um conjunto vazio de ponteiros
- Adicionar o ponteiro para o nó raiz da árvore
- Enquanto o conjunto não for vazio
		
	retirar do conjunto o ponteiro para o próximo nó
	processar esse nó

- destruir conjunto vazio

### BFS
	
```c
... //void (*function)(ItemType* p)
if (root == NULL ) return ;


Queue* q = QueueCreate();

QueueEnqueue(q, root);
while (QueueIsEmpty(q) == 0) {
	Tree* p = QueueDequeue(queue);
	function(&(p->item));
	if(p->left != NULL) QueueEnqueue(q, p->left);
	if(p->right != NULL) QueueEnqueue(q, p->right);
}
QueueDestroy(&q);
```


### DFS


```c
... // creation of stack s

while(StackIsEmpty(s) == 0) {
	Tree* p = StackPop(s);
	function(&(p->item));
	// dfs pre-ordem neste caso 
	if( p->right != NULL) {
		StackPush(stack, p->right);
	}
	if( p->left != NULL) {
		StackPush(stack,p->right);
	}
}

```


# Árvore Binária de Procura

## Procurar elemento


```c
...

while(root != NULL) {
	if( root->item == item) {
		return 1;
	}
	if( root->item > item) {
		root = root->left; 
	} else {
		root = root->right;
	}
}
	return 0;
```

## Adicionar um elemento 


```c
int BSTreeAdd( BSTree** pRoot, const ItemType item) {
	BSTree* root = *pRoot;

	struct _BSTreeNode* new = (struct _BSTree*) malloc(sizeof(*new));
	assert(new != NULL);

	new->item = item;
	new->left = new->right = NULL;
	if(root == NULL) {
	
		*pRoot = new;
		return 1;
	}
	struct _BSTreeNode* prev = NULL;
	struct _BSTreeNode* current = root;

	while ( current != NULL ) {
		if (current->item == item) {
			free(new);
			return 0; 
		}
		prev = current; 
		if (current->item > item) {
			current->left;
		} else {
			current = current->right;
		}
	}
	if (prev->item > item) {
		prev->left = new;
	} else {	
		prev->right;
	}	
	return 0;
}		

```
||Lista ligada| Array ordenado | Árvore Binária de Pesquisa|
|--|--|--|--|--|
| search | N | log N | h | 
| insert | N | N | h |
| min/max | N | 1 | h | 
| floor / ceiling | N | log N | h | 
| rank | N | log N | h | 
| select | N | 1 | h | 
| ordered iteration | N log N  | N | N | 




# Árvores equilibradas em altura 

### Altura O ~ (log n) 

Para uma árvore ser equílibrada o fator de equilíbrio de um nó F = altura(sub-árvore Dir) - altura(sub-árvore Esq) = -1, 0, 1; 


# Árvores Bínárias Totais

Árvore com propriedade especial: todos os nós têm 0 ou 2 filhos;

