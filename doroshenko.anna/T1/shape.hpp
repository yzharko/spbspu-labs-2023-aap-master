#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace doroshenko
{
  class Shape
  {
  public:
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(point_t destination) = 0;
    virtual void move(double moveX, double moveY) = 0;
    virtual void scale(point_t pos, double coefficient) = 0;
  };
}

#endif
