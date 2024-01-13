#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "baseTypes.hpp"

namespace taskaev
{
  class Shape
  {
  public:
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(double x, double y) = 0;
    virtual void move(const point_t& newCenter) = 0;
    virtual void scale(double k) = 0;
  };
}
#endif
