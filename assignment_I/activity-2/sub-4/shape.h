#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
  Shape(const std::string& color);
  virtual ~Shape() = default;

  virtual double area() const = 0;
  virtual double perimeter() const = 0;
  std::string getColor() const;

protected:
  std::string color;
};

#endif // SHAPE_H
