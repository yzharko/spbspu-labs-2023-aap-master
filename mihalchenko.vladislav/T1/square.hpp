#ifndef SQUARE_HPP
#define SQUARE_HPP
#include <cstring>
#include "shape.hpp"

namespace mihalchenko
{
  class Square
  {
  public:
    float x_ = 7;
    float y_ = 7;
    float width_ = 10;

    Square();
    Square(float x, float y, float width);
    ~Square();
    float getArea(float x, float y, float width);
  };
}
#endif
