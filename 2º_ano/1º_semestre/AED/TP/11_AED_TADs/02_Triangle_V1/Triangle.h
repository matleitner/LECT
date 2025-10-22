//
// Algoritmos e Estruturas de Dados - 2025/2026 - 1o semestre
//
// J. Madeira - Outubro 2025
//

#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

// Triangle: the attibutes
struct _Triangle {
  double side1;
  double side2;
  double side3;
};

// New type, equivalent to struct _Triangle
typedef struct _Triangle Triangle;

// Constructor

// REQUIRES: tri points to a Triangle instance
// MODIFIES: *tri
// EFFECTS:  Initializes a triangle with given side lengths
void Triangle_init(Triangle* tri, double a, double b, double c);

// Getters

// REQUIRES: tri points to a valid Triangle
// EFFECTS:  Returns the length of the first side of the given triangle
double Triangle_side1(const Triangle* tri);

// REQUIRES: tri points to a valid Triangle
// EFFECTS:  Returns the length of the second side of the given triangle
double Triangle_side2(const Triangle* tri);

// REQUIRES: tri points to a valid Triangle
// EFFECTS:  Returns the length of the third side of the given triangle
double Triangle_side3(const Triangle* tri);

// Operations on Triangles

// REQUIRES: tri points to a valid Triangle
// EFFECTS:  Returns the perimeter of the given triangle
double Triangle_perimeter(const Triangle* tri);

// REQUIRES: tri points to a valid Triangle; s > o
// MODIFIES: *tri
// EFFECTS:  Scales the sides of the triangle by the factor s
void Triangle_scale(Triangle* tri, double s);

// Printing the triangle attributes

// REQUIRES: tri points to a valid Triangle
// EFFECTS:  Prints the lengths of the triangle sides
void Triangle_print(const Triangle* tri);

#endif  // _TRIANGLE_H_
