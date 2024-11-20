#include "shape.h"

Shape::Shape(const std::string& color) : color(color) {}

std::string Shape::getColor() const {
  return color;
}
