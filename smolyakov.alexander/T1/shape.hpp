#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace smolyakov
{
  class Shape
  {
  public:
    virtual point_t getScaleCenter() const = 0;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void moveTo(point_t shift) = 0;
    virtual void moveBy(point_t shift) = 0;
    virtual void scale(double factor) = 0;
  };
}
#endif
