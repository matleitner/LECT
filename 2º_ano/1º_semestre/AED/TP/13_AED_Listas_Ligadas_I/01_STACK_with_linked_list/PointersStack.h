//
// Algoritmos e Estruturas de Dados - 2024/2025 - 1o semestre
//
// Joaquim Madeira, April 2020
//
// Adapted from Tomás Oliveira e Silva, AED, September 2015
//
// Pointers stack (First In Last Out) implementation based on n
// linked list of pointers
//

#ifndef _POINTERS_STACK_
#define _POINTERS_STACK_

typedef struct _PointersStack Stack;

Stack* StackCreate(void);

void StackDestroy(Stack** p);

void StackClear(Stack* s);

int StackSize(const Stack* s);

int StackIsEmpty(const Stack* s);

void* StackPeek(const Stack* s);

void StackPush(Stack* s, void* p);

void* StackPop(Stack* s);

#endif  // _POINTERS_STACK_
