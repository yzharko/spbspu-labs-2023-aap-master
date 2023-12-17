#include <iostream>
#include "shape.hpp"
#include "rectangle.hpp"
#include "square.hpp"
#include "triangle.hpp"

int main()
{
  hohlova::Rectangle rectangle({ 1, 1 }, { 3,4 });
  hohlova::Triangle triangle({ 0, 0 }, { 1, 1 }, { 0, 1 });
  hohlova::Square square({ 6, 7 }, 1);
  Shape* shape = &rectangle;
  std::cout << shape->getArea();
  shape = &triangle;
  std::cout << shape->getArea();
  shape = &square;
  std::cout << shape->getArea();
}
