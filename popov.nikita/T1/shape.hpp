#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace popov
{
  class Shape
  {
    virtual float getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(point_t pos);
    virtual void move(point_t x, point_t y);
    virtual void scale(n);
  };
}

#endif
