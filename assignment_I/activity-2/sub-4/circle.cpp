#include "circle.h"
#include <cmath>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Circle::Circle(double radius, const std::string& color)
  : Shape(color), radius(radius) {}

double Circle::area() const {
  return M_PI * radius * radius;
}

double Circle::perimeter() const {
  return 2 * M_PI * radius;
}
