#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace anikanov {

  class Shape {
  public:
    virtual ~Shape() = default;

    virtual float getArea() = 0;

    virtual RectangleT getFrameRect() = 0;

    virtual void move(PointT) = 0;

    virtual void move(float x, float y) = 0;

    virtual PointT getCPoint() const = 0;

    virtual void scale(float, PointT) = 0;
  };
}

#endif
