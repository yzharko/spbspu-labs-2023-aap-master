#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace reznikova
{
  class Shape
  {
  public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual void move(const double& dx, const double& dy) = 0;
    virtual void move(const point_t& new_center) = 0;
    virtual void scale(const double n) = 0;
  };
}

#endif
