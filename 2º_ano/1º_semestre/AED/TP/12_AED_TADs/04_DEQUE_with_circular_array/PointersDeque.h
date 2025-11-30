// Leitner 
/*
	Integer_Dequeue
	int max_size
	int cur_size  0	1 	2	3	4	... 
	int head      head -> -> -> -> tail
	int tail
	int* data
*/

#ifndef _POINTERS_DUQUEUE_
#define _POINTERS_DEQUEUE_ 
typedef struct _Pointers_Deque_ Deque;

Deque* DequeCreate(int size);

void DequeDestroy(Deque** p);


void Deque_add_at_front(Deque* d, void* i);
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
#endif		// _Pointers_DEQUEUE_
