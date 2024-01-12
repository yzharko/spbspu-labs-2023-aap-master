#ifndef SHAPE_HPP
#define SHAPE_HPP

#include "base-types.hpp"

namespace anikanov {

  struct Shape {
    virtual ~Shape() = default;

    virtual double getArea() const = 0;

    virtual rectangle_t getFrameRect() const = 0;

    virtual void move(const point_t) = 0;

    virtual void move(const double x, const double y) = 0;

    virtual void scale(const double) = 0;

    virtual point_t getCPoint() = 0;
  };
}

#endif
