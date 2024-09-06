#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
public:
  Triangle(double side1, double side2, double side3, const std::string& color);

  double area() const override;
  double perimeter() const override;

private:
  double side1;
  double side2;
  double side3;
};

#endif // TRIANGLE_H
