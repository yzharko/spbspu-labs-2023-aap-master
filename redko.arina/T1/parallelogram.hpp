#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"

namespace redko
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram(point_t firstPoint, point_t secondPoint, point_t thirdPoint);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t dest);
    void move(double xDist, double yDist);
    void scale(point_t pos, double coefficient);
  protected:
    point_t firstPoint_;
    point_t secondPoint_;
    point_t thirdPoint_;
  };
}

#endif
