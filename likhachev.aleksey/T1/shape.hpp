#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace likhachev
{
  class Shape {
    public:
      virtual double getArea() const;
      virtual likhachev::Rectangle_t getFrameRect() const;
      virtual void move();
      virtual void scale();
  };
}
#endif
