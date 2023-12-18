#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

class Shape
{
public:
  virtual double gerArea() = 0;
  virtual rectangle_t getFrameRect() = 0;
  virtual void move(point_t newPos) = 0;
  virtual void move(double xPlus, double yPlus) = 0;
  virtual void scale(double multiplier) = 0;
};

#endif
