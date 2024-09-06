#include "triangle.h"
#include <cmath>

Triangle::Triangle(double side1, double side2, double side3, const std::string& color)
  : Shape(color), side1(side1), side2(side2), side3(side3) {}

double Triangle::area() const {
  double s = perimeter() / 2;
  return std::sqrt(s * (s - side1) * (s - side2) * (s - side3));
}

double Triangle::perimeter() const {
  return side1 + side2 + side3;
}
