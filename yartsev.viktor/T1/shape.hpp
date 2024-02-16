#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace yartsev {
  class Shape {
    public:
      virtual double getArea() = 0;
      virtual yartsev::rectangle_t getFrameRect() =0;
      virtual void move() = 0;
      virtual void scale() = 0;
  };
}

#endif
