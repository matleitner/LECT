//
// Algoritmos e Estruturas de Dados - 2025/2026 - 1o semestre
//
// J. Madeira - Outubro 2025
//

#include "Triangle.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// Constructor

// REQUIRES: tri points to a Triangle instance
//           each side length is positive 
//           a_in > 0 && b_in > 0 && c_in > 0
//           the sides satisfy the triangle inequality
//           a_in + b_in > c_in && a_in + c_in > b_in &&
//           b_in + c_in > a_in
// MODIFIES: *tri
// EFFECTS:  Initializes a triangle with given side lengths
void Triangle_init(Triangle* tri, double a_in, double b_in, double c_in) {
  assert(a_in > 0 && b_in > 0 && c_in > 0);
  assert(a_in + b_in > c_in && a_in + c_in > b_in && b_in + c_in > a_in);

  tri->side1 = a_in;
  tri->side2 = b_in;
  tri->side3 = c_in;
}

// Getters

// REQUIRES: tri points to a valid Triangle
// EFFECTS:  Returns the length of the first side of the given triangle
double Triangle_side1(const Triangle* tri) {
  return tri->side1;
}

// REQUIRES: tri points to a valid Triangle
// EFFECTS:  Returns the length of the second side of the given triangle
double Triangle_side2(const Triangle* tri) {
  return tri->side2;
}

// REQUIRES: tri points to a valid Triangle
// EFFECTS:  Returns the length of the third side of the given triangle
double Triangle_side3(const Triangle* tri) {
  return tri->side3;
}

// Operations on Triangles

// REQUIRES: tri points to a valid Triangle
// EFFECTS:  Returns the perimeter of the given triangle
double Triangle_perimeter(const Triangle* tri) {
  return tri->side1 + tri->side2 + tri->side3;
}

// REQUIRES: tri points to a valid Triangle; s > 0
// MODIFIES: *tri
// EFFECTS:  Scales the sides of the triangle by the factor s
void Triangle_scale(Triangle* tri, double s) {
  assert(s > 0);
  
  tri->side1 *= s;
  tri->side2 *= s;
  tri->side3 *= s;
}

// Printing the triangle attributes

// REQUIRES: tri points to a valid Triangle
// EFFECTS:  Prints the lengths of the triangle sides
void Triangle_print(const Triangle* tri) { 
  printf("t1 : %.1f , %.1f , %.1f\n", tri->side1, tri->side2, tri->side3);
}


