// AED JMR 2024 + JM 2025

// Running the sorting algorithms (as in the lecture slides).
// Counting the number of operations on random arrays or on given arrays.

// sorting 100              # sorting ann array of 100 random integers
// sorting 6  6 5 4 4 2 1   # sorting the given array with 6 elements (array
// size followed by integer values)

// The original array is used for the 3 sorting algorithms.
// Sorted array is checked against the result of qsort.

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void randFill(int a[], int n) {
  while (n > 0) {
    // store a random integer
    *(a++) = rand();  // % (n * 2);
    n--;
  }
}

// Para instrumentar funções:
long unsigned int ncomp = 0;    // number of compares
long unsigned int nstores = 0;  // number of array stores

void swap(int* a, int* b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
  nstores += 2;
}

void selectionSort(int a[], int n) {
  for (int k = n - 1; k > 0; k--) {
    int indMax = 0;
    for (int i = 1; i <= k; i++) {
      ncomp++;
      if (a[i] >= a[indMax]) indMax = i;
    }
    if (indMax != k) swap(&a[indMax], &a[k]);
  }
}

void bubbleSort(int a[], int n) {
  int k = n;
  int stop = 0;
  while (stop == 0) {
    stop = 1;
    k--;
    for (int i = 0; i < k; i++) {
      ncomp++;
      if (a[i] > a[i + 1]) {
        swap(&a[i], &a[i + 1]);
        stop = 0;
      }
    }
  }
}

void insertElement(int sorted[], int n, int elem) {
  // Array sorted está ordenado
  // Há espaço para acrescentar mais um elemento
  int i;
  for (i = n - 1; (i >= 0) && (ncomp++, elem < sorted[i]); i--) {
    nstores++;
    sorted[i + 1] = sorted[i];
  }
  nstores++;
  sorted[i + 1] = elem;
}

void insertionSort(int a[], int n) {
  for (int i = 1; i < n; i++)
    if (ncomp++, a[i] < a[i - 1])  // this if is not really required!
      insertElement(a, i, a[i]);
}

// Compare two integers pointed to by a and b
int intcmp(const void* a, const void* b) { return *((int*)a) - *((int*)b); }

int main(int argc, char* argv[]) {
  srand((unsigned long)time(NULL));

  // first arg = size
  int n = atoi(argv[1]);

  int a[n];
  randFill(a, n);

  // any extra args are inserted in the array
  for (int i = 0; i < argc - 2 && i < n; i++) a[i] = atoi(argv[2 + i]);

  int b[n];
  memcpy(b, a, n * sizeof(*a));
  qsort((void*)b, n, sizeof(*b), intcmp);  // sort the array copy

  int c[n];
  memcpy(c, a, n * sizeof(*a));
  ncomp = 0;
  nstores = 0;
  selectionSort(c, n);
  assert(memcmp(b, c, n * sizeof(*b)) == 0);  // check order
  printf("selectionSort\t%10d\t%10lu\t%10lu\n", n, ncomp, nstores);

  memcpy(c, a, n * sizeof(*a));
  ncomp = 0;
  nstores = 0;
  bubbleSort(c, n);
  assert(memcmp(b, c, n * sizeof(*b)) == 0);  // check order
  printf("bubbleSort\t%10d\t%10lu\t%10lu\n", n, ncomp, nstores);

  memcpy(c, a, n * sizeof(*a));
  ncomp = 0;
  nstores = 0;
  insertionSort(c, n);
  assert(memcmp(b, c, n * sizeof(*b)) == 0);  // check order
  printf("insertionSort\t%10d\t%10lu\t%10lu\n", n, ncomp, nstores);

  return 0;
}
