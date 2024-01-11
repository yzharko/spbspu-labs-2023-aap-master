#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace anikanov {

  class Shape {
  public:
    virtual ~Shape() = default;

    virtual float getArea() = 0;

    virtual rectangle_t getFrameRect() = 0;

    virtual void move(point_t) = 0;

    virtual void move(float x, float y) = 0;

    virtual point_t getCPoint() const = 0;

    virtual void scale(float, point_t) = 0;

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
