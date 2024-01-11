#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace jirkov
{
  class Shape
  {
  public:
    virtual ~Shape() {}
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(point_t destination) = 0;
    virtual void move(double moveX, double moveY) = 0;
    virtual void scale(double k) = 0;
  };
}

#endif