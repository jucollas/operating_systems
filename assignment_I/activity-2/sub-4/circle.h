#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
public:
  Circle(double radius, const std::string& color);

  double area() const override;
  double perimeter() const override;

private:
  double radius;
};

#endif // CIRCLE_H
