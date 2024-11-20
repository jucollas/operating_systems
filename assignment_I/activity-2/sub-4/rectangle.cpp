#include "rectangle.h"

Rectangle::Rectangle(double width, double height, const std::string& color)
  : Shape(color), width(width), height(height) {}

double Rectangle::area() const {
  return width * height;
}

double Rectangle::perimeter() const {
  return 2 * (width + height);
}
