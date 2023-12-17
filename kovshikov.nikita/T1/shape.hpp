#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual double gerArea() = 0;
  virtual rectangle_t getFrameRect() = 0;
  virtual Shape move() = 0;
  virtual Shape scale() = 0;
};

#endif
