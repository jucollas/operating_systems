#ifndef SQUARE_H
#define SQUARE_H

#include "shape.h"

class Square : public Shape {
public:
  Square(double side, const std::string& color);
  
  double area() const override;
  double perimeter() const override;

private:
  double side;
};

#endif // SQUARE_H
