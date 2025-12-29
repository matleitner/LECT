<!--Leitner-->

# Stack / Pilha

- Conjunto de elementos do mesmo tipo
- Armazenados em ordem sequencial
- LIFO : Last-In-First-Out
- Inserção / remoção / consulta apenas no topo da pilha
- push() / pop() / peek()
- size() / isEmpty() / isFull()
- init() / destroy() / clear()



## PointersStack.h
```c
#ifndef _POINTERS_STACK_
#define _POINTERS_STACK_

typedef struct _PointersStack Stack;

Stack* StackCreate(int size);

void StackDestroy(Stack** p); 

void StackClear(Stack* s);

int StackSize(const Stack* s);

int StackIsFull(const Stack* s);

int StackIsEmpty(const Stack* s);

void* StackPeek(const Stack* s);

void StackPush(Stack* s, void* p);

void* StackPop(Stack* s);

#endif		// _POINTERS_STACK_

```

## PointersStack.c


```c
struct _PointersStack {
	int max_size;		
	int cur_size;		
	void** data;			// pointers stored in an array
}

```
### Peek Push e Pop


```c
void* StackPeek(const Stack* s){
	return s->data[s->cur_size-1];
}

void StackPush(Stack* s, void* p) {
	s->data[s->cur_size++] = p;
}

void* StackPop(Stack* s) {
	return s->data[--(s->cur_size)];
}

```

# Queue

- Conjunto de elementos do mesmo tipo
- Armazenados em ordem sequencial
- FIFO : First-In-First-Out
- Inserção na cauda da fila
- Remoção / consulta apenas na frente da fila
- enqueue() / dequeue() / peek()
- size() / isEmpty() / isFull()
- init() / destroy() / clear()

## PointersQueue.h

(Array circular de ponteiros)

```c
#ifndef _POINTERS_QUEUE_ 
#define _POINTERS_QUEUE_ 
 
typedef struct _PointersQueue Queue; 
 
Queue* QueueCreate(int size); 
 
void QueueDestroy(Queue** p); 
 
void QueueClear(Queue* q); 
 
QueueSize(const Queue* q); 
 
int QueueIsFull(const Queue* q); 
 
int QueueIsEmpty(const Queue* q); 
 
void* QueuePeek(const Queue* q); 
 
void QueueEnqueue(Queue* q, void* p); 
  
void* QueueDequeue(Queue* q); 
  
#endif  // _POINTERS_QUEUE_


```

## PointersQueue.c


```c
struct _PointersQueue {
	int max_size;
	int cur_size;
	int head;
	int tail;
	void** data;
};

// função privada para ser array circular

static int increment_index(const Queue* q, int i) {
	return (i + 1 < q->max_size ? i + 1 : 0; 
}
```

## Enqueue Dequeue


```c
void QueueEnqueue(Queue* q, int i) {
	q->tail = increment_index(q, q->tail);
	q->data[q->tail] = i;
	q->cur_size++
}

int QueueDequeue(Queue* q) {
	int old_head = q->head;
	q->head = increment(q, q->head);
	q->cur_size--;
	return q->data[old_head];
}

```

# Deque

## Deque.h


```c
#ifndef _POINTERS_DUQUEUE_
#define _POINTERS_DEQUEUE_ 

typedef struct _Pointers_Deque_ Deque;

Deque* DequeCreate(int size);

void DequeDestroy(Deque** p);

void*  Deque_remove_at_front(Deque* d);

void*  Deque_peek_at_front(Deque* d);

void Deque_add_at_rear(Deque* d, void* i);

void*  Deque_remove_at_rear(Deque* d);

void*  Deque_peek_at_rear(Deque* d);

int  Deque_size(Deque* d); 

int  Deque_isEmpty(Deque* d);

int  Deque_isFull(Deque* d);

void Deque_clear(Deque* d);

void Deque_display(Deque* d);

#endif    // _Pointers_DEQUEUE_
```


