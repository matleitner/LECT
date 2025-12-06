// Leitner
// Implementação de um TAD deque mas usando funções de LIST

#ifndef _DEQUE_
#define _DEQUE_

typedef struct _Deque Deque;


Deque* DequeCreate();

void DequeDestroy(Deque** p);

void Deque_add_at_front(Deque* d, void* i);
void*  Deque_remove_at_front(Deque* d);
void*  Deque_peek_at_front(Deque* d);


void Deque_add_at_rear(Deque* d, void* i);
void*  Deque_remove_at_rear(Deque* d);
void*  Deque_peek_at_rear(Deque* d);

int  Deque_size(Deque* d);


int  Deque_isEmpty(Deque* d);
//int  Deque_isFull(Deque* d);

void Deque_clear(Deque* d);
void Deque_display(Deque* d);


#endif //_DEQUE_LIST_
