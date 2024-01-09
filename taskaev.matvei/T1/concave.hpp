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
    point_t left_;
    point_t right_;
    point_t inner_;
    point_t upper_;
  };
}
#endif

