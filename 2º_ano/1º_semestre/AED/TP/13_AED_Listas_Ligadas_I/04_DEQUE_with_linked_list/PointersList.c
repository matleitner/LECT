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
  assert(l != NULL);
  return (l->current != NULL) ? l->current->data : NULL;
}

void ListModifyCurrentValue(const List* l, void* p) {
  assert(l != NULL && p != NULL);
  l->current->data = p;
}

// The move and search functions return 0 on success and -1 on failure (on
// success the current node is changed, on failure it is not changed)

// Search

int ListSearchFromCurrent(const List* l, void* p) {
  assert(l != NULL || p != NULL);
  struct _PointersListNode* node = l->current;
  
  while(node != NULL){
	  if(node->data == p) return 0;
	  node = node->next;
  }
  return -1; 
}

// Move to functions

int ListMove(List* l, int newPos) {
  assert(l!=NULL); 
  if(newPos<0 || newPos>=l->size) return -1;

  struct _PointersListNode* node = l->head;
  int pos = 0;


  while(pos<newPos){
	  node = node->next;
	  pos++;
			
  } 


 	l->current = node;
  l->currentPos = newPos;
 	return 0;
}

int ListMoveToNext(List* l) {
    assert(l != NULL);

    // Se current já é NULL (ou seja, fora da lista), não podemos avançar.
    if (l->current == NULL) return -1;

    // Se o próximo nó é NULL (chegou ao fim da lista)
    if (l->current->next == NULL) {
        l->current = NULL; // Mova current para NULL para sinalizar o fim
        l->currentPos = l->size; // Ou -1, dependendo da sua convenção para "depois da cauda"
        return 0; // Sucesso na movimentação para fora da lista
    }

    // Movimento normal
    l->current = l->current->next;
    l->currentPos++;

    return 0;
  }

int ListMoveToPrevious(List* l) { 
	if(l->currentPos-1 <0) 	return -1;
    
  return ListMove(l, l->currentPos-1); 	


}

int ListMoveToHead(List* l) { 
  if (l == NULL || l->head == NULL) return -1;
  assert(l != NULL);
  struct _PointersListNode* head = l->head;
  l->current = head;
  l->currentPos = 0;
  
  return 0; }

int ListMoveToTail(List* l) {
  if(l == NULL || l->tail == NULL)  return -1;
  l->current = l->tail;
  l->currentPos = l->size -1;
  return 0;  

}

// Insert functions

void ListInsertBeforeHead(List* l, void* p) {
    if(l == NULL || p == NULL) return;
    
    struct _PointersListNode* newNode = malloc(sizeof(struct _PointersListNode));
    
    if(newNode == NULL) return;
    
    newNode->data = p;
    newNode->next = l->head;
    l->head = newNode;
    
    if(l->size == 0) l->tail = newNode;
    
    l->size++;
}

void ListInsertAfterTail(List* l, void* p) {
    if(l== NULL || p == NULL) return;

    struct _PointersListNode* node = malloc(sizeof(struct _PointersListNode));
    
    if(node == NULL) return;
    node->data = p; 
    node->next = NULL;
    if(l->tail == NULL){
      l->head = node;
      l->tail = node;
    }
    else{
      l->tail->next = node;
      l->tail = node;
    }
    l->size++;    


}

void ListInsertAfterCurrent(List* l, void* p) {
    if(l== NULL || p == NULL) return;

    struct _PointersListNode* node = malloc(sizeof(struct _PointersListNode));
    
    if(node == NULL) return;
    node->data = p;
    node->next = l->current->next;
    l->current->next = node;
    if(l->current == l->tail) l->tail = node;
    l->size++;

}

void ListInsertBeforeCurrent(List* l, void* p) {
    // strategy is to find the node that the ->next is current and setting ->next = newNode 
    //and the next of newNode->next = current 
    if(l == NULL || p == NULL) return;
    struct _PointersListNode* newNode = malloc(sizeof(struct _PointersListNode));
    newNode->data = p;
    if(l->current == l->head){
      newNode->next = l->head;
      l->head = newNode;
    }else{
      struct _PointersListNode* node = l->head;
      while (node->next != l->current)
      {
        node = node->next;
      }
      node->next = newNode;  
      newNode->next = l->current;
    }
    l->size++;
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

  l->size--;

  if (l->size == 0) {
    l->head = NULL;
    l->tail = NULL;
  } else {
    l->head = l->head->next;
  }

  free(aux);
}

void ListRemoveTail(List* l) {
  assert(l != NULL && l->size >0);
  struct _PointersListNode* old = l->tail;
  if(l->head== l->tail){
    l->head = NULL;
    l->current = NULL;
    l->tail = NULL;
  }
  else{
    struct _PointersListNode* aux =l->head;
      
    while (aux->next != l->tail)
    {
      aux = aux->next;
    }

    aux->next = NULL;
    l->tail = aux;
    if(l->current == old){
      l->current = l->tail;
    }
  
  }

  free(old);
  l->size--;
}

void ListRemoveCurrent(List* l) {
  assert(l != NULL && l->size >0);
  struct _PointersListNode* currentOld = l->current;
  if(l->current == l->head){
    ListRemoveHead(l);
    return;
  }
  if(l->current == l->tail){
    ListRemoveTail(l);
    return;
  }
    struct _PointersListNode* prev = l->head;
    while(prev->next != l->current){
      prev = prev->next;
      if(prev== NULL)return;
    }
    prev->next = l->current->next;
    l->current = prev->next;
    free(currentOld);
    l->size--;
  }


void ListRemoveNext(List* l) {
  assert(l != NULL && l->size >0);
  struct _PointersListNode* nextNode = l->current->next;
  if(nextNode == l->tail) l->tail = l->current;
  l->current->next = nextNode->next;
  
  
  free(nextNode);
  l->size--;
  

}

// Tests
void ListTestInvariants(const List* l) {
    assert(l != NULL); // lista deve existir

    // Lista vazia
    if (l->size == 0) {
        assert(l->head == NULL);
        assert(l->tail == NULL);
        assert(l->current == NULL);
        return;
    }

    // Lista não vazia
    assert(l->head != NULL);
    assert(l->tail != NULL);

    // Contar nós e verificar tail
    int count = 0;
    struct _PointersListNode* node = l->head;
    while (node != NULL) {
        count++;
        if (node->next == NULL) {
            assert(node == l->tail); // último nó deve ser o tail
        }
        node = node->next;
    }
    assert(count == l->size); // size consistente

    // Verificar current
    node = l->head;
    int found = 0;
    while (node != NULL) {
        if (node == l->current) {
            found = 1;
            break;
        }
        node = node->next;
    }
    assert(l->current == NULL || found); // current deve estar na lista ou ser NULL
}
