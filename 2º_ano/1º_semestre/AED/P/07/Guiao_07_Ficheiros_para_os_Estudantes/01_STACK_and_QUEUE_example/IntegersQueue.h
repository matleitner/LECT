//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira, Joao Manuel Rodrigues - June 2021, November 2023
//
// Integers queue (First In First Out) implementation based on a circular array
//

#ifndef _INTEGERS_QUEUE_
#define _INTEGERS_QUEUE_

typedef struct _IntegersQueue Queue;

Queue* QueueCreate(int size);

void QueueDestroy(Queue** p);

void QueueClear(Queue* q);

int QueueSize(const Queue* q);

int QueueIsFull(const Queue* q);

int QueueIsEmpty(const Queue* q);

int QueuePeek(const Queue* q);

void QueueEnqueue(Queue* q, int i);

int QueueDequeue(Queue* q);

#endif  // _INTEGERS_QUEUE_
