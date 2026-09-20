#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "linked-list.h"

/*******************************************************/

SllNode *sllDestroy(SllNode *list) {
  SllNode *dummy = list;
  SllNode *next;
  while (dummy != NULL) {
    next = dummy->next;
    free(dummy);
    dummy = next;
  }

  return dummy;
}

/*******************************************************/

void sllPrint(SllNode *list, FILE *fout) {
  if (list == NULL)
    fprintf(fout, "Empty");
  SllNode *dummy = list;

  while (dummy != NULL) {

    fprintf(fout, "%d, %s\n", dummy->reg.nmec, dummy->reg.name);
    dummy = dummy->next;
  }
}

/*******************************************************/

SllNode *sllInsert(SllNode *list, uint32_t nmec, const char *name) {
  assert(name != NULL && name[0] != '\0');
  assert(!sllExists(list, nmec));
  SllNode *node = (SllNode *)malloc(sizeof(SllNode));
  if (node == NULL)
    return list;
  node->reg.name = (char *)malloc(strlen(name) + 1);
  strcpy(node->reg.name, name);
  node->reg.nmec = nmec;
  node->next = NULL;
  if (list == NULL || nmec < list->reg.nmec) {
    node->next = list;
    return node;
  }

  SllNode *last = list;
  while (last->next != NULL && last->next->reg.nmec < nmec)
    // curr -> next -> next2
    //  1       2        4
    //          3

    last = last->next;

  node->next = last->next;

  last->next = node;
  return list;
}

/*******************************************************/

bool sllExists(SllNode *list, uint32_t nmec) {
  while (list != NULL) {
    if (list->reg.nmec == nmec) {
      return true;
    }
    list = list->next;
  }
  return false;
}

/*******************************************************/

SllNode *sllRemove(SllNode *list, uint32_t nmec) {
  assert(list != NULL);
  assert(sllExists(list, nmec));
  if (list->reg.nmec == nmec) {
    SllNode *toDelete = list;
    list = list->next; // A lista passa a começar no segundo nó
    free(toDelete);
    return list;
  }

  SllNode *dummy = list;
  while (dummy != NULL && dummy->next != NULL) {
    if (dummy->next->reg.nmec == nmec) {
      SllNode *toDelete = dummy->next;
      dummy->next = dummy->next->next;
      free(toDelete);
      break;
    }
    dummy = dummy->next;
  }

  return list;
}

/*******************************************************/

const char *sllGetName(SllNode *list, uint32_t nmec) {
  assert(list != NULL);
  assert(sllExists(list, nmec));

  SllNode *dummy = list;
  while (dummy != NULL) {
    if (dummy->reg.nmec == nmec) {
      return dummy->reg.name;
    }
    dummy = dummy->next;
  }
  return NULL;
}

/*******************************************************/

SllNode *sllLoad(SllNode *list, FILE *fin, bool *ok) {
  assert(fin != NULL);
  if (ok != NULL)
    *ok = false; // load failure

  char nome[100];

  int nmec;

  while (fscanf(fin, "%d%*c %[^\n]", &nmec, nome) == 2) {
    list = sllInsert(list, (uint32_t)nmec, nome);
  }

  return list;
}

/*******************************************************/
