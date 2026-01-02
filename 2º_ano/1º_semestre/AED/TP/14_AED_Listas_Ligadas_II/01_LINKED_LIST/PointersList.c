//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira, April 2020, November 2024
//
// Adapted from Tomás Oliveira e Silva, AED, September 2015
//
// Pointers LIST implementation based on an linked list
//

// ***************** COMPLETAR AS FUNCOES !!! *******************

#include "PointersList.h"

#include <assert.h>
#include <stdlib.h>

struct _PointersListNode {
  void* data;
  struct _PointersListNode* next;
};

struct _PointersList {
  int size;                           // current List size
  struct _PointersListNode* head;     // the head of the List
  struct _PointersListNode* tail;     // the tail of the List
  struct _PointersListNode* current;  // the current node
  int currentPos;
};

List* ListCreate(void) {
  List* l = (List*)malloc(sizeof(List));
  assert(l != NULL);

  l->size = 0;
  l->head = NULL;
  l->tail = NULL;
  l->current = NULL;
  l->currentPos = -1;  // Default: before the head of the list
  return l;
}

void ListDestroy(List** p) {
  assert(*p != NULL);
  List* l = *p;

  ListClear(l);

  free(l);
  *p = NULL;
}

void ListClear(List* l) {
  assert(l != NULL);

  struct _PointersListNode* p = l->head;
  struct _PointersListNode* aux;

  while (p != NULL) {
    aux = p;
    p = aux->next;
    free(aux);
  }

  l->size = 0;
  l->head = NULL;
  l->tail = NULL;
  l->current = NULL;
  l->currentPos = -1;  // Default: before the head of the list
}

int ListGetSize(const List* l) {
  assert(l != NULL);
  return l->size;
}

int ListIsEmpty(const List* l) {
  assert(l != NULL);
  return (l->size == 0) ? 1 : 0;
}

// Current node functions

int ListGetCurrentIndex(const List* l) {
  assert(l != NULL);
  return l->currentPos;
}

void* ListGetCurrentValue(const List* l) {
  assert(l != NULL && l->current != NULL);
  return l->current->data;
}
// Move e Search

int ListSearchFromCurrent(const List* l, void* p) {
    assert(l != NULL);
    struct _PointersListNode* node = l->current;
    int pos = l->currentPos;
    while (node != NULL) {
        if (node->data == p) return pos;
        node = node->next;
        pos++;
    }
    return -1;
}

int ListMove(List* l, int newPos) {
    assert(l != NULL);
    if (newPos < 0 || newPos >= l->size) return -1;
    l->current = l->head;
    l->currentPos = 0;
    for (int i = 0; i < newPos; i++) {
        l->current = l->current->next;
        l->currentPos++;
    }
    return 0;
}

int ListMoveToNext(List* l) {
    assert(l != NULL);
    if (l->current == NULL || l->current->next == NULL) return -1;
    l->current = l->current->next;
    l->currentPos++;
    return 0;
}

int ListMoveToPrevious(List* l) {
    assert(l != NULL);
    if (l->current == NULL || l->currentPos == 0) return -1;
    struct _PointersListNode* p = l->head;
    for (int i = 0; i < l->currentPos - 1; i++)
        p = p->next;
    l->current = p;
    l->currentPos--;
    return 0;
}

int ListMoveToHead(List* l) {
    assert(l != NULL && l->size > 0);
    l->current = l->head;
    l->currentPos = 0;
    return 0;
}

int ListMoveToTail(List* l) {
    assert(l != NULL && l->size > 0);
    l->current = l->tail;
    l->currentPos = l->size - 1;
    return 0;
}

// Insert

void ListInsertBeforeHead(List* l, void* p) {
    assert(l != NULL);
    struct _PointersListNode* node = malloc(sizeof(struct _PointersListNode));
    node->data = p;
    node->next = l->head;
    l->head = node;
    if (l->size == 0) l->tail = node;
    if (l->currentPos != -1) l->currentPos++;
    l->size++;
}

void ListInsertAfterTail(List* l, void* p) {
    assert(l != NULL);
    struct _PointersListNode* node = malloc(sizeof(struct _PointersListNode));
    node->data = p;
    node->next = NULL;
    if (l->size == 0) l->head = l->tail = node;
    else {
        l->tail->next = node;
        l->tail = node;
    }
    l->size++;
}

void ListInsertAfterCurrent(List* l, void* p) {
    assert(l != NULL && l->current != NULL);
    struct _PointersListNode* node = malloc(sizeof(struct _PointersListNode));
    node->data = p;
    node->next = l->current->next;
    l->current->next = node;
    if (l->current == l->tail) l->tail = node;
    l->size++;
}

void ListInsertBeforeCurrent(List* l, void* p) {
    assert(l != NULL);
    if (l->current == l->head || l->current == NULL) {
        ListInsertBeforeHead(l, p);
        return;
    }
    struct _PointersListNode* node = malloc(sizeof(struct _PointersListNode));
    node->data = p;
    struct _PointersListNode* prev = l->head;
    for (int i = 0; i < l->currentPos - 1; i++)
        prev = prev->next;
    node->next = l->current;
    prev->next = node;
    l->currentPos++;
    l->size++;
}

// Remove

void ListRemoveTail(List* l) {
    assert(l != NULL && l->size > 0);
    if (l->size == 1) { ListRemoveHead(l); return; }
    struct _PointersListNode* p = l->head;
    while (p->next != l->tail) p = p->next;
    if (l->current == l->tail) { l->current = NULL; l->currentPos = -1; }
    free(l->tail);
    l->tail = p;
    l->tail->next = NULL;
    l->size--;
}

void ListRemoveCurrent(List* l) {
    assert(l != NULL && l->current != NULL);
    if (l->current == l->head) { ListRemoveHead(l); return; }
    struct _PointersListNode* prev = l->head;
    for (int i = 0; i < l->currentPos - 1; i++) prev = prev->next;
    prev->next = l->current->next;
    if (l->current == l->tail) l->tail = prev;
    free(l->current);
    l->current = prev->next;
    l->size--;
}

void ListRemoveNext(List* l) {
    assert(l != NULL && l->current != NULL && l->current->next != NULL);
    struct _PointersListNode* aux = l->current->next;
    l->current->next = aux->next;
    if (aux == l->tail) l->tail = l->current;
    free(aux);
    l->size--;
}

// Modify

void ListModifyCurrentValue(const List* l, void* p) {
    assert(l != NULL && l->current != NULL);
    l->current->data = p;
}

// Remove functions

void ListRemoveHead(List* l) {
  assert(l != NULL && l->size > 0);

  struct _PointersListNode* aux = l->head;

  if (l->current == l->head) {
    l->current = l->head->next;
    if (l->current == NULL) {
      l->currentPos = -1;
    }
  } else if (l->currentPos != -1) {
    // Current node is not the head node
    // Decrement the current index, since there is one less list node
    l->currentPos--;
  }

  // One less list node, after removing the head node
  l->size--;

  if (l->size == 0) {
    l->head = NULL;
    l->tail = NULL;
  } else {
    l->head = l->head->next;
  }

  free(aux);
}
