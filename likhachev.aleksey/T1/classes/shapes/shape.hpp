#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "shapesCommon.hpp"

namespace likhachev
{
  class Shape {
    public:
      virtual double getArea() const = 0;
      virtual likhachev::Rectangle_t getFrameRect() const = 0;
      virtual void move(Point_t offset) = 0;
      virtual void move(double offsetX, double offsetY) = 0;
  };
}
#endif
