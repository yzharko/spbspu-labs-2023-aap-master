#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace redko
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t & dest) = 0;
    virtual void move(double xDist, double yDist) = 0;
    virtual void scale(double coefficient) = 0;
  };
}

#endif
