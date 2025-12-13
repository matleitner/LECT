//
// Algoritmos e Estruturas de Dados - 2024/2025
//
// J. Madeira - April/May 2022, December 2024
//
// COMPLETE the code, according to Circle.h
//

#include "Circle.h"

#define _USE_MATH_DEFINES

#include <cassert>
#include <cmath>
#include <iostream>
#include <string>

#include "Figure.h"
#include "Point.h"

Circle::Circle(void) : Figure(){
  // Circle of radius 1 and centered at (0,0)
  // COMPLETE
  radius_ = 1.0;  
}

Circle::Circle(Point center, const std::string& color, double length) : Figure(center, color), radius_(length) {
  // Ensure that the radius is larger than 0.0
  // COMPLETE
  assert(length>0.0);
}

Circle::Circle(double x, double y, const std::string& color, double length) : Figure(x,y,color), radius_(length) {
  // Ensure that the radius is larger than 0.0
  // COMPLETE
  assert(radius_ > 0.0);
}

double Circle::GetRadius(void) const { return radius_; }
void Circle::SetRadius(double length) {
  // Ensure that the radius is larger than 0.0
  // COMPLETE
  assert(radius_>0.0);
  radius_ = length;
}

std::string Circle::GetClassName(void) const { return "Circle"; }

double Circle::Area(void) const {
  // COMPLETE
  return radius_* M_PI * radius_; 
}

double Circle::Perimeter(void) const {
  // COMPLETE
  return 2* M_PI * radius_;
}

bool Circle::Intersects(const Circle& c) const {
  // dist(C1,C2) <= r1 + r2
  // if dist(C1,C2) == r1 + r2, then circles touch at a single point

  double distance_between_centers = GetCenter().DistanceTo(c.GetCenter());

  double sum_of_radii = radius_ + c.radius_;

  return (distance_between_centers < sum_of_radii);
}

std::ostream& operator<<(std::ostream& os, const Circle& obj) {
  os << "Center: " << obj.GetCenter() << std::endl;
  os << "Color: " << obj.GetColor() << std::endl;
  os << "Radius = " << obj.radius_ << std::endl;
  return os;
}

std::istream& operator>>(std::istream& is, Circle& obj) {
  // COMPLETE
  
  Point p;
  std::cout << "Center ";
  is >> p;
  obj.SetCenter(p);
  
  std::string s;
  std::cout << "Color: ";
  is >> s;
  obj.SetColor(s);
  double r;
  std::cout << "Radius: ";
  is >> r;
  obj.SetRadius(r);

  return is; 
}
