#include <iostream>
#include "rectangle.hpp"
#include "regular.hpp"
#include "square.hpp"
#include "shape.hpp"
int main()
{
  Rectangle rect({ 0, 0 }, { 2, 10 });
  Square square({ 0, 0 }, 3);
  Regular regul({ 0,0 }, { 0,1 }, { 1,1 });
  Shape* shape = &rect;
  std::cout << shape->getArea() << "\n";
  shape = &square;
  std::cout << shape->getArea() << "\n";
  shape = &regul;
  std::cout << shape->getArea() << "\n";
  shape->scale(2);
  std::cout << shape->getArea() << "\n";
}

