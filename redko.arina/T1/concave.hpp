#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "shape.hpp"

namespace redko
{
  class Concave : public Shape
  {
  public:
    Concave(point_t firstPoint, point_t secondPoint, point_t thirdPoint, point_t fourthPoint);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t dest);
    void move(double xDist, double yDist);
    void scale(point_t pos, double coefficient);
  protected:
    point_t firstPoint_;
    point_t secondPoint_;
    point_t thirdPoint_;
    point_t fourthPoint_;
  };
}

#endif
