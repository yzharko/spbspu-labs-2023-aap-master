#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace shagieva
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const double & dx, const double & dy) = 0;
    virtual void move(const point_t & newCenter) = 0;
    virtual void scale(const double & scaleFactor) = 0;
  };
}

#endif
