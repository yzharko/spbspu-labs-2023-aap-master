#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace ponomarev
{
  class Shape
  {
  public:
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(point_t toThePoint) = 0;
    virtual void move(double aX, double aY) = 0;
    virtual void scale(point_t pos, double k) = 0;
  };
}

#endif
