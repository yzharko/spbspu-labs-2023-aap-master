#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace gorbunova
{
  class Shape
  {
  public:
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(point_t center) = 0;
    virtual void move(double xMove, double yMove) = 0;
    virtual void scale(point_t posNew, double z) = 0;
  };
}
#endif
