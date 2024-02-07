#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace sobolevsky
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t point) = 0;
    virtual void move(double xDist, double yDist) = 0;
    virtual void scale(double n) = 0;

    virtual ~Shape() = default;
  };
}

#endif
