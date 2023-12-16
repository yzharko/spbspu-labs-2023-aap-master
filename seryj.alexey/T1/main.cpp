#include <iostream>
#include "rectangle.hpp"
#include "regular.hpp"
#include "square.hpp"
#include "shape.hpp"
int main()
{
  Rectangle rect({ 0, 0 }, { 2, 2 });
  Square sqar({ 0, 0 }, 3);
  Regular regu({ 0,0 }, { 0,1 }, { 1,1 });
  Shape* shape = &rect;
  std::cout << shape->getArea() << "\n";
  shape = &sqar;
  std::cout << shape->getArea() << "\n";
  shape = &rect;
  std::cout << shape->getArea() << "\n";
}