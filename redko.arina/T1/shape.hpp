#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace redko
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t dest) = 0;
    virtual void move(double xDist, double yDist) = 0;
    virtual void scale(point_t pos, double coefficient) = 0;
  };
}

#endif
