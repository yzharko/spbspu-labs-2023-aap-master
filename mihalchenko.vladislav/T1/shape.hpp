#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace mihalchenko
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t &point) = 0;
    virtual void move(const double deltaX, const double deltaY) = 0;
    virtual void scale(double scaleKoef) = 0;
  };
}
#endif
