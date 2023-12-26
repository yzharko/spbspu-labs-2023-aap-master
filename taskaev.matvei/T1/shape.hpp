#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "baseTypes.hpp"

namespace taskaev
{
  class Shape
  {
    public:
      virtual double getArea() = 0;
      virtual rectangle_t getFrameRect() = 0;
      virtual void move(point_t center) = 0;
      virtual void move(double x, double y) = 0;
      virtual void scale(double c) = 0;
  };
}
#endif
