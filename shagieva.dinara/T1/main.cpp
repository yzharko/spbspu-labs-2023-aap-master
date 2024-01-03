#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include <iostream>

int main()
{
  using namespace shagieva;
  point_t a = { 2.0, 2.0 };
  point_t c = { 4.0, 4.0 };
  Rectangle figure(a, c);
  std::cout << figure.getArea() << "\n";
  figure.scale(2);
  std::cout << figure.getArea() << "\n";
  point_t newCenter = { 5.0, 5.0 };
  figure.move(newCenter);
  rectangle_t frame = figure.getFrameRect();
  return 0;
}
