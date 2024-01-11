#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace psarev
{
  class Shape
  {
  public:
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(point_t newCenter) = 0;
    virtual void move(double xCh, double yCh) = 0;
    virtual void scale(double coef) = 0;
    virtual ~Shape() = default;
  };
}

#endif
