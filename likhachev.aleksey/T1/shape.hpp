#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace likhachev
{
  class Shape {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const point_t& offset) = 0;
    virtual void move(double offsetX, double offsetY) = 0;
    virtual void scale(double multiplier) = 0;
    virtual point_t getPos() const = 0;
  };
}
#endif
