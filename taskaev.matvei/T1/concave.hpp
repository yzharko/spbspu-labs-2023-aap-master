#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "baseTypes.hpp"
#include "Shape.hpp"

namespace taskaev
{
  class Concave : public Shape
  {
  public:
    Concave(point_t left, point_t right, point_t inner, point_t upper);
    double getArea();
    rectangle_t getFrameRect();
    void move(double x, double y);
    void move(point_t newCenter);
    void scale(double k);

  private:
    point_t p1;
    point_t p2;
    point_t p3;
    point_t p4;
  };
}
#endif

