#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
public:
  Rectangle(double width, double height, const std::string& color);
  
  double area() const override;
  double perimeter() const override;

private:
  double width;
  double height;
};

#endif // RECTANGLE_H
