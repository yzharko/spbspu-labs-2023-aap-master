#ifndef SHAPE_HPP
#define SHAPE_HPP
#include "base-types.hpp"

namespace sobolevsky
{
  class Shape
  {
  public:
    double getArea();
    Rectangle_t getFrameRect();
    void move(Point_t point);
    void move(double xDist, double yDist);
    void scale(Point_t point, double coef);
  };
}

#endif
