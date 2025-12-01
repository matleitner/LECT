#include "PointersDeque.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>



struct _Pointers_Deque_{
	int max_size;
	int cur_size;
	int tail;
	int head;
	void** data;

};

//private functions 
static int increment_index(Deque* d, int index){
	return (index+1 < d->max_size) ? index + 1 : 0;
} 
static int decrease_index(Deque* d, int index){

	return (index-1 <0)? d->max_size-1 : index-1; 

}

Deque* DequeCreate(int size){
	assert(size>=10 && size <=1000000);
	Deque* d = (Deque*)malloc(sizeof(Deque));

	if(d == NULL) return NULL;
	
	d->max_size = size;
	d->cur_size = 0;
	d->head = 1;			// cur_size = tail - head + 1
	d->tail = 0;
	d->data = (void**)malloc(sizeof(void*)*size);
	if(d->data == NULL){ 	
		free(d);
		return NULL;
	}
	
	return d;
}


void DequeDestroy(Deque** p){
	assert(*p!=NULL);
	Deque* d = *p;	// d = valor apontado por p que é uma deque
	free(d->data); 	
	free(*p);
	*p =NULL;
}
//FRONT

void Deque_add_at_front(Deque* d, void* i){
	assert(d->cur_size<d->max_size);
	d->head = decrease_index(d, d->head);
	d->cur_size++;
	d->data[d->head] = i;
	
}

void* Deque_remove_at_front(Deque* d){
	void* data = d->data[d->head];
	
	d->head = increment_index(d, d->head);
	d->cur_size--;
	return data;	
}

void* Deque_peek_at_front(Deque* d){
	
	return d->data[d->head];

}


//REAR
void Deque_add_at_rear(Deque* d, void* i){
	assert(d->cur_size < d->max_size);
	d->tail = increment_index(d, d->tail);
	d->data[d->tail] = i;
	d->cur_size++;
}

void* Deque_remove_at_rear(Deque* d){
	void* data = d->data[(d->tail)];
	d->tail = decrease_index(d, d->tail);
	d->cur_size--;
	return data;
} 

void* Deque_peek_at_rear(Deque* d){

	return d->data[d->tail];
}


int Deque_size(Deque* d){ return d->cur_size;}

int Deque_isEmpty(Deque* d){ return ( d->cur_size>0)? 0:1; }

int Deque_isFull(Deque* d){return d->cur_size==d->max_size;}

void Deque_clear(Deque* d){
	d->head = 1;
	d->tail = 0;
	d->cur_size = 0;

}

void Deque_display(Deque* d){
	if(d->cur_size== 0){
		printf("Deque vazio...\n");
		return ;
	}
	int i = d->head;
    int c = d->cur_size;  // número de elementos restantes
    while(c > 0){
        printf("%d->", *(int*)d->data[i]);
        i = increment_index(d, i);
        c--;
    }
	printf("\n");
}
