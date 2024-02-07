#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace kovshikov
{
  class Shape
  {
  public:
    virtual ~Shape() = default; //
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0; // const = 0;
    virtual void move(const point_t &newPos) = 0;
    virtual void move(double xPlus, double yPlus) = 0;
    virtual void scale(double multiplier) = 0;
  };
}

#endif
