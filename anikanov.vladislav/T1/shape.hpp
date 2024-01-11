#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace anikanov {

  class Shape {
  public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;

    virtual rectangle_t getFrameRect() const = 0;

    virtual void move(const point_t) = 0;

    virtual void move(const float x, const float y) = 0;

    virtual point_t getCPoint() = 0;

    virtual void scale(const float, const point_t) = 0;

    float getDX(point_t fp, point_t sp)
    {
      return fp.x - sp.x;
    };

    float getDY(point_t fp, point_t sp)
    {
      return fp.y - sp.y;
    };
  };
}

#endif
