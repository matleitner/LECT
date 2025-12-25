//
// Algoritmos e Estruturas de Dados --- 2024/2025
//
// Joaquim Madeira, Nov 2023, Nov 2024
//

// Complete the functions (marked by ...)
// so that they pass all tests.

#include "PersonSet.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the structure
struct _PersonSet_ {
  int capacity;    // the current capacity of the array
  int size;        // the number of elements currently stored
  Person **array;  // points to an array of pointers to persons
};

#define INITIAL_CAPACITY 4

// You may add auxiliary definitions and declarations here, if you need to.

// Create a PersonSet.
PersonSet *PersonSetCreate() {
  // You must allocate space for the struct and for the array.
  // The array should be created with INITIAL_CAPACITY elements.
  // (The array will be reallocated if necessary, when elements are appended.)

  // COMPLETE ...
  PersonSet* p = (PersonSet*)malloc(sizeof(PersonSet));
  if(p == NULL){	  
	  perror("PersonSetCreate");
	  return NULL; 
  }

  p->array = (Person**) malloc( INITIAL_CAPACITY * sizeof(Person*));
  if(p->array == NULL){
	free(p);
	perror("PersonsetCreate -storage");
	return NULL;	
  }

  
  p->capacity = INITIAL_CAPACITY;
  p->size = 0;	
  return p;

}

// Destroy PersonSet *pps
void PersonSetDestroy(PersonSet **pps) {
  assert(*pps != NULL);
  
  // COMPLETE ...
 
  free((*pps)->array);
  free(*pps);
  *pps = NULL;
 
}

int PersonSetSize(const PersonSet *ps) { return ps->size; }

int PersonSetIsEmpty(const PersonSet *ps) { return ps->size == 0; }

void PersonSetPrint(const PersonSet *ps) {
  printf("{\n");
  for (int i = 0; i < ps->size; i++) {
    Person *p = ps->array[i];
    PersonPrintf(p, ";\n");
  }
  printf("}(size=%d, capacity=%d)\n", ps->size, ps->capacity);
}

// Find index in ps->array of person with given id.
// (INTERNAL function.)
static int search(const PersonSet *ps, int id) {
  // COMPLETE ...
  for(int i = 0; i<ps->size;i++){
  	Person *p = ps->array[i];
	if(p->id == id) return i;

  }
  return -1;
}

// Append person *p to *ps, without verifying presence.
// Use only when sure that *p is not contained in *ps!
// (INTERNAL function.)
static void append(PersonSet *ps, Person *p) {
  // MODIFY the function so that if the array is full,
  // it uses realloc to double the array capacity!

  // COMPLETE ...
  if(ps->size ==  ps->capacity){
  	Person **pset = (Person**) realloc(ps->array, ps->capacity*2*sizeof(Person*));
	if(pset == NULL) return;
  	ps->array = pset;
	ps->capacity *= 2;
  }

  ps->array[ps->size] = p;
  ps->size++;
}

// Add person *p to *ps.
// Do nothing if *ps already contains a person with the same id.
void PersonSetAdd(PersonSet *ps, Person *p) {
  // You may call the append function here!
  // COMPLETE ...
  if(search(ps, p->id) ==-1) append(ps,p);
}

// Pop one person out of *ps.
Person *PersonSetPop(PersonSet *ps) {
  assert(!PersonSetIsEmpty(ps));
  // It is easiest to pop and return the person in the last position!

  // COMPLETE ...
  Person* p = ps -> array[ps->size-1];
  ps->size--;
  return p;
}

// Remove the person with given id from *ps, and return it.
// If no such person is found, return NULL and leave set untouched.
Person *PersonSetRemove(PersonSet *ps, int id) {
  // You may call search here!

  // COMPLETE ...
  int ind = search(ps,id);
  if(ind == -1) return NULL;
  
  Person *p= ps->array[ind];
  ps->array[ind] = ps-> array[ps->size-1];
  //memmove(&ps->array[ind], &ps->array[ind+1], (ps->size - ind -1) * sizeof(Person*)); // maitaining the order

  ps->size--;
  return p;
}

// Get the person with given id of *ps.
// return NULL if it is not in the set.
Person *PersonSetGet(const PersonSet *ps, int id) {
  // You may call search here!

  // COMPLETE ...
  int ind = search(ps,id);
  if(ind == -1)  return NULL;
	 
  return ps->array[ind];
}

// Return true (!= 0) if set contains person wiht given id, false otherwise.
int PersonSetContains(const PersonSet *ps, int id) {
  return search(ps, id) >= 0;
}

// Return a NEW PersonSet with the union of *ps1 and *ps2.
// Return NULL if allocation fails.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetUnion(const PersonSet *ps1, const PersonSet *ps2) {
  PersonSet *ps = PersonSetCreate();
  if(ps == NULL) return NULL;
  for(int i = 0; i< ps1->size; i++){
  	PersonSetAdd(ps, ps1->array[i]);
 }
  for(int i = 0; i< ps2-> size; i++){
  	PersonSetAdd(ps, ps2->array[i]);
  
 }

  
  // COMPLETE ...

  return ps;
}

// Return a NEW PersonSet with the intersection of *ps1 and *ps2.
// Return NULL if allocation fails.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetIntersection(const PersonSet *ps1, const PersonSet *ps2) {
  // COMPLETE ...
  PersonSet* ps = PersonSetCreate();
  if(ps == NULL)  return NULL;
  const PersonSet *minor, *greater;
  (ps1->size >= ps2 ->size) ? (greater = ps1, minor = ps2) : (greater = ps2, minor = ps1);
  for(int i = 0; i < minor->size; i++){
  	if(PersonSetContains(greater, minor->array[i]->id))
			PersonSetAdd(ps,minor->array[i]);
  
  }
  return ps;
}

// Return a NEW PersonSet with the set difference of *ps1 and *ps2.
// Return NULL if allocation fails.
// NOTE: memory is allocated.  Client must call PersonSetDestroy!
PersonSet *PersonSetDifference(const PersonSet *ps1, const PersonSet *ps2) {
  // COMPLETE ...
	PersonSet* ps = PersonSetCreate();
	if(ps == NULL) return NULL;

	for(int i = 0; i < ps1->size; i++){
		if(!PersonSetContains(ps2, ps1->array[i]->id)){
			PersonSetAdd(ps, ps1->array[i]);
		}
	} 
	return ps;
}
// Return true iff *ps1 is a subset of *ps2.
int PersonSetIsSubset(const PersonSet *ps1, const PersonSet *ps2) {
  // COMPLETE ...
	for(int i = 0 ; i< ps1->size; i++){
		if(!PersonSetContains(ps2, ps1->array[i]->id)) return 0;
	}
	return 1;
}

// Return true if the two sets contain exactly the same elements.
int PersonSetEquals(const PersonSet *ps1, const PersonSet *ps2) {
  // You may call PersonSetIsSubset here!

  // COMPLETE ...
	PersonSet* ps = PersonSetIntersection(ps1, ps2);
	if(ps == NULL) return 0;
	PersonSetDestroy(&ps);
	return 1;
}
