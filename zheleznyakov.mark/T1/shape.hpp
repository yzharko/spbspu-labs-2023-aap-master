#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace zheleznyakov
{
  class Shape
  {
  public:
    virtual double getArea() = 0;
    virtual zheleznyakov::rectangle_t getFrameRect() = 0;
    virtual void move(zheleznyakov::point_t point) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double k) = 0;
  };
}
#endif
