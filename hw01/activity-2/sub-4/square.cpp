#include "square.h"

Square::Square(double side, const std::string& color)
  : Shape(color), side(side) {}

double Square::area() const {
  return side * side;
}

double Square::perimeter() const {
  return 4 * side;
}
