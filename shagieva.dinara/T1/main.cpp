#include "base-types.hpp"
#include "shape.hpp"
#include "rectangle.hpp"
#include "complexquad.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
  using namespace shagieva;

  point_t pointA = { 1.0, 2.0 };
  point_t pointB = { 9.0, 2.0 };
  point_t pointC = { 13.0, 7.0 };
  point_t pointD = { 3.0, 6.0 };

  Complexquad figure(pointA, pointB, pointC, pointD);
  try
  {
    std::cout << figure.getArea() << "\n";
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  return 0;
}
