#include <iostream>
#include "rectangle.h"
#include "square.h"
#include "triangle.h"
#include "circle.h"

int main() {
  Rectangle rect(4.0, 5.0, "red");
  Square square(3.0, "blue");
  Triangle tri(3.0, 4.0, 5.0, "green");
  Circle circle(5.0, "yellow");

  std::cout << "Rectangle area: " << rect.area() << ", perimeter: " << rect.perimeter() << ", color: " << rect.getColor() << std::endl;
  std::cout << "Square area: " << square.area() << ", perimeter: " << square.perimeter() << ", color: " << square.getColor() << std::endl;
  std::cout << "Triangle area: " << tri.area() << ", perimeter: " << tri.perimeter() << ", color: " << tri.getColor() << std::endl;
  std::cout << "Circle area: " << circle.area() << ", perimeter: " << circle.perimeter() << ", color: " << circle.getColor() << std::endl;

  return 0;
}
