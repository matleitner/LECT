//
// Algoritmos e Estruturas de Dados - 2025/2026 - 1o semestre
//
// J. Madeira - Outubro 2025
//

#include <assert.h>
#include <stdio.h>

#include "Triangle.h"

int main(void) {
  Triangle t1;
  Triangle_init(&t1, 3, 4, 5);
  Triangle t2;
  Triangle_init(&t2, 2, 2, 2);

  Triangle_print(&t1);
  Triangle_print(&t2);

  printf("t1 - side1 : %.2f\n", Triangle_side1(&t1));
  printf("t1 - side2 : %.2f\n", Triangle_side2(&t1));
  printf("t1 - side3 : %.2f\n", Triangle_side3(&t1));

  printf("t1 - Perimeter : %.2f\n", Triangle_perimeter(&t1));

  printf("Scaling t1 - factor : 2\n");
  Triangle_scale(&t1, 2);
  Triangle_print(&t1);

  return 0;
}