#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
#include <stdexcept>

namespace ponomarev
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(const point_t & newCenter) = 0;
    virtual void move(const double & offsetX, const double & offsetY) = 0;
    virtual void scale(const double k) = 0;
  };
}

#endif
