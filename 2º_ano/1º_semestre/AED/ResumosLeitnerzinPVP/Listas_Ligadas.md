# Estruturas de dados dinâmicas
O que fazer quando não conhecemos o número de elementos de uma coleção? 

# Lista

- Conjunto de elementos do mesmo tipo
- Armazenados em ordem sequencial
- Inserção / remoção / substituição / consulta em qualquer
posição
- insert() / remove() / replace() / get() / moveTo() / …
- size() / isEmpty() / isFull()
- init() / destroy() / clear()


```c
struct _PointersListNode {
	void* data;
	_PointersListNode* next;
};

struct _PointersList {
	int size;
	struct _PointersListNode* head;
	struct _PointersListNode* tail;
	struct _PointersListNode* current;

	int currentPos;
};
```


data[0] head -> data[1] -> data[2] ->  data[3] tail -> NULL


___




## Implementar Stacks com Listas ligadas


```c
struct _PointersStackNode {
  void* data;
  struct _PointersStackNode* next;
};

struct _PointersStack {
  int cur_size;                    // current stack size
  struct _PointersStackNode* top;  // the node on the top of the stack
};

Stack* StackCreate(void) {
  Stack* s = (Stack*)malloc(sizeof(Stack));
  assert(s != NULL);

  s->cur_size = 0;
  s->top = NULL;
  return s;
}

void StackDestroy(Stack** p) {
  assert(*p != NULL);
  Stack* s = *p;

  StackClear(s);

  free(s);
  *p = NULL;
}

void StackClear(Stack* s) {
  assert(s != NULL);

  struct _PointersStackNode* p = s->top;
  struct _PointersStackNode* aux;

  while (p != NULL) {
    aux = p;
    p = aux->next;
    free(aux);
  }

  s->cur_size = 0;
  s->top = NULL;
}

int StackSize(const Stack* s) {
  assert(s != NULL);
  return s->cur_size;
}

int StackIsEmpty(const Stack* s) {
  assert(s != NULL);
  return (s->cur_size == 0) ? 1 : 0;
}

void* StackPeek(const Stack* s) {
  assert(s != NULL && s->cur_size > 0);
  return s->top->data;
}

void StackPush(Stack* s, void* p) {
  assert(s != NULL);

  struct _PointersStackNode* aux;
  aux = (struct _PointersStackNode*)malloc(sizeof(*aux));
  assert(aux != NULL);

  aux->data = p;
  aux->next = s->top;

  s->top = aux;

  s->cur_size++;
}

void* StackPop(Stack* s) {
  assert(s != NULL && s->cur_size > 0);

  struct _PointersStackNode* aux = s->top;
  s->top = aux->next;
  s->cur_size--;

  void* p = aux->data;

  free(aux);

  return p;
}
```
## PointersQueue com listas ligadas


```c
struct _PointersQueueNode {
  void* data;
  struct _PointersQueueNode* next;
};

struct _PointersQueue {
  int size;                         // current Queue size
  struct _PointersQueueNode* head;  // the head of the Queue
  struct _PointersQueueNode* tail;  // the tail of the Queue
};

Queue* QueueCreate(void) {
  Queue* q = (Queue*)malloc(sizeof(Queue));
  if (q == NULL) abort();

  q->size = 0;
  q->head = NULL;
  q->tail = NULL;
  return q;
}

void QueueClear(Queue* q) {
  assert(q != NULL);

  struct _PointersQueueNode* p = q->head;
  struct _PointersQueueNode* aux;

  while (p != NULL) {
    aux = p;
    p = aux->next;
    free(aux);
  }

  q->size = 0;
  q->head = NULL;
  q->tail = NULL;
}

void QueueEnqueue(Queue* q, void* p) {
  assert(q != NULL);

  struct _PointersQueueNode* aux;
  aux = (struct _PointersQueueNode*)malloc(sizeof(*aux));
  if (aux == NULL) abort();

  aux->data = p;
  aux->next = NULL;

  q->size++;

  if (q->size == 1) {
    q->head = aux;
    q->tail = aux;
  } else {
    q->tail->next = aux;
    q->tail = aux;
  }
}

void* QueueDequeue(Queue* q) {
  assert(q != NULL && q->size > 0);

  struct _PointersQueueNode* aux = q->head;
  void* p = aux->data;

  q->size--;

  if (q->size == 0) {
    q->head = NULL;
    q->tail = NULL;
  } else {
    q->head = aux->next;
  }

  free(aux);

  return p;
}
```



___

# Lista ordenada 

- Conjunto de elementos do mesmo tipo
- Armazenados em ordem de acordo com um critério
- Registar uma função comparadora
- A junção de um novo elemento à lista mantém a ordem !!
- A procura de um elemento fica facilitada

### Tem uma função compFun na estrutura 

Cada vez que insere compara para colocar o elemento na lista

# ListInsert(List* l, void* p)

Para inserir numa Lista ordenada, temos de apontar o l->node(prev)->next para new_node  e o new_node->next para o antigo node(prev)->next 
