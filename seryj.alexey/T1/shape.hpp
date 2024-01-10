#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"
namespace seryj
{
  class Shape
  {
  public:
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(point_t) = 0;
    virtual void move(double x, double y) = 0;
    virtual void scale(double k) = 0;
    virtual ~Shape() = default;
  };
}
#endif
