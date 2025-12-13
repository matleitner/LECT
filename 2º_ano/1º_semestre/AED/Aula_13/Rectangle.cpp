//
// Algoritmos e Estruturas de Dados - 2024/2025
//
// J. Madeira - April/May 2022
//
// COMPLETE the code, according to Rectangle.h
//

#include "Rectangle.h"

#include <cassert>
#include <iostream>
#include <string>

#include "Point.h"

Rectangle::Rectangle(void) {
  // Rectangle of width=1 and height=1 and centered at (0,0)
  // COMPLETE
}

Rectangle::Rectangle(Point center, const std::string& color, double width,
                     double height) {
  // Ensure that the width and height are larger than 0.0
  // COMPLETE
}

Rectangle::Rectangle(double x, double y, const std::string& color, double width,
                     double height) {
  // Ensure that the width and height are larger than 0.0
  // COMPLETE
}

double Rectangle::GetHeight(void) const { return height_; }
void Rectangle::SetHeight(double length) {
  // Ensure that the height is larger than 0.0
  // COMPLETE
}

double Rectangle::GetWidth(void) const { return width_; }
void Rectangle::SetWidth(double length) {
  // Ensure that the width is larger than 0.0
  // COMPLETE
}

std::string Rectangle::GetClassName(void) const { return "Rectangle"; }

double Rectangle::Area(void) const {
  // COMPLETE
}

double Rectangle::Perimeter(void) const {
  // COMPLETE
}

std::ostream& operator<<(std::ostream& os, const Rectangle& obj) {
  // COMPLETE
}

std::istream& operator>>(std::istream& is, Rectangle& obj) {
  // COMPLETE
}