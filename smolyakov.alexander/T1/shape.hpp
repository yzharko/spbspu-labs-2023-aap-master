#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace smolyakov
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void moveTo(double x, double y) = 0;
    virtual void moveBy(double x, double y) = 0;
    virtual void scale(double factor) = 0;
  };
}
#endif
