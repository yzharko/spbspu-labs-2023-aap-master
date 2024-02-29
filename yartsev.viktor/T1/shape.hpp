#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace yartsev {
  class Shape {
    public:
      virtual double getArea() const = 0;
      virtual rectangle_t getFrameRect() = 0;
      virtual void move(const point_t & to) = 0;
      virtual void move(const double & dx, const double & dy) = 0;
      virtual void scale(const double & scaling) = 0;
  };
}

#endif
