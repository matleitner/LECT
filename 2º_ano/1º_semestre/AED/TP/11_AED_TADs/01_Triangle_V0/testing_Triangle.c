//
// Algoritmos e Estruturas de Dados - 2025/2026 - 1o semestre
//
// J. Madeira - Outubro 2025
//

#include <assert.h>
#include <stdio.h>

#include "Triangle.h"

int main(void) {
  // Triangles - Direct initialization
  struct Triangle t1 = {3, 4, 5};
  struct Triangle t2 = {2, 2, 2};

  // Direct access to the attributes of each triangle
  printf("t1 : %.1f , %.1f , %.1f\n", t1.side1, t1.side2, t1.side3);
  printf("t2 : %.1f , %.1f , %.1f\n", t2.side1, t2.side2, t2.side3);

  return 0;
}