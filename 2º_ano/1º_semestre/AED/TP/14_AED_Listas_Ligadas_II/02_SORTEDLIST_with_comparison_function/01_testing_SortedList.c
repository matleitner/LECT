
//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira, April 2020, November 2023, November 2024
//
// TESTING the TAD SORTED LIST implementation based on a linked list
//

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "SortedList.h"

// Storing pointers to integers

// The comparator

int comparator(const void* p1, const void* p2) {
  int d = *(int*)p1 - *(int*)p2;
  return (d > 0) - (d < 0);
}

int main(void) {
  List* list = ListCreate(comparator);

  printf("INSERTING\n");

  for (int i = 1; i < 10; i += 2) {
    int* aux = (int*)malloc(sizeof(int));
    *aux = i;
    ListInsert(list, aux);
    ListTestInvariants(list);
  }

  for (int i = 0; i < 11; i += 2) {
    int* aux = (int*)malloc(sizeof(int));
    *aux = i;
    ListInsert(list, aux);
    ListTestInvariants(list);
  }

  printf("%d elements\n", ListGetSize(list));

  int i = 0;
  int size = ListGetSize(list);
  ListMove(list, 0);
  while (i < size) {
    int* p = (int*)ListGetCurrentItem(list);
    printf("%d ", *p);
    ListMoveToNext(list);
    ListTestInvariants(list);
    i++;
  }

  printf("\nREMOVING SOME ELEMENTS\n");

  ListMoveToHead(list);
  for (int i = 0; i < 6; i++) {
    int* aux = ListRemoveCurrent(list);
    free(aux);
    ListMoveToNext(list);
    ListTestInvariants(list);
  }

  i = 0;
  size = ListGetSize(list);
  ListMove(list, 0);
  while (i < size) {
    int* p = (int*)ListGetCurrentItem(list);
    printf("%d ", *p);
    ListMoveToNext(list);
    ListTestInvariants(list);
    i++;
  }

  printf("\nREMOVING THE REMAINING ELEMENTS\n");

  size = ListGetSize(list);
  ListMove(list, 0);
  while (i < size) {
    int* p = (int*)ListGetCurrentItem(list);
    printf("%d ", *p);
    ListMoveToNext(list);
    ListTestInvariants(list);
    i++;
  }

  printf("\nAND DESTROYING THE LIST\n");

  ListDestroy(&list);

  return 0;
}
