#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"
namespace miheev
{
  class Shape
  {
  public:
    virtual ~Shape(){}

    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(double dx, double dy) = 0;
    virtual void move(point_t) = 0;
    virtual void scale(double) = 0;
  };
}

#endif
