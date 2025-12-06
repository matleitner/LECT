/*
Deque* DequeCreate(); ✔️

void DequeDestroy(**Deque p);

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

*/

#include "DequeList.h"
#include "PointersList.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct _Deque{
	List* list;	
};

Deque* DequeCreate(){
	Deque* d = malloc(sizeof(Deque));
	if(d == NULL) return NULL;
	d->list = ListCreate();
	return d; 
}

void DequeDestroy(Deque** p){
	assert(*p != NULL);
	ListDestroy(&((*p)->list));
	free(*p);
	*p = NULL; 
}

void Deque_add_at_rear(Deque* d, void* i){
	assert(d != NULL);
		
	ListInsertAfterTail(d->list, i);
}

void* Deque_remove_at_rear(Deque* d){
	assert(d != NULL);
	ListMoveToTail(d->list);
	void* value = ListGetCurrentValue(d->list);
	ListRemoveTail(d->list);
	return value;
}

void* Deque_peek_at_rear(Deque* d){
	assert(d != NULL);
	ListMoveToTail(d->list); 
	return ListGetCurrentValue(d->list);
}

void Deque_add_at_front(Deque* d, void* i){
	assert(d != NULL);
	
	ListInsertBeforeHead(d->list, i);
	
}

void* Deque_remove_at_front(Deque* d){
	assert(d != NULL);
	ListMoveToHead(d->list);
	void* value = ListGetCurrentValue(d->list);	
	ListRemoveHead(d->list);
	return value;
}


void* Deque_peek_at_front(Deque* d){
	assert(d != NULL);
	if(Deque_isEmpty(d)) return NULL;
	ListMoveToHead(d->list);
	return ListGetCurrentValue(d->list);
}

int Deque_size(Deque* d){
	assert(d != NULL);
	return ListGetSize(d->list);
}

int Deque_isEmpty(Deque* d){
	assert(d != NULL);
	return ListGetSize(d->list) == 0;
}
/*int Deque_isFull(Deque* d){
	assert(d != NULL);
	return d->size == d->curSize;
}*/
void Deque_clear(Deque* d){
	assert(d != NULL);
	if (!Deque_isEmpty(d)) {
        ListMoveToHead(d->list);
        while(ListGetCurrentValue(d->list) != NULL){
            void* val = ListGetCurrentValue(d->list);
            if (val != NULL) free(val);           // libera o valor
            ListMoveToNext(d->list);              // move para o próximo nó
        }
    }
	ListClear(d->list);
}


void Deque_display(Deque* d){
	assert(d != NULL);
	
	if (Deque_isEmpty(d)) {
    printf("Deque vazio\n");
    return;
	}
	ListMoveToHead(d->list);
    printf("Head:");
    void* val = ListGetCurrentValue(d->list);
    while(val!= NULL){
        printf("%d->", *(int*)val);
        ListMoveToNext(d->list);
        val = ListGetCurrentValue(d->list);
    }
    printf(":Tail\n");
}
