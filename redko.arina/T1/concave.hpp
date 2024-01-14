#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "shape.hpp"

namespace redko
{
  class Concave : public Shape
  {
  public:
    Concave(const point_t & firstPoint, const point_t & secondPoint, const point_t & thirdPoint, const point_t & fourthPoint);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t & dest);
    void move(double xDist, double yDist);
    void doScale(double coefficient);
  private:
    point_t firstPoint_;
    point_t secondPoint_;
    point_t thirdPoint_;
    point_t fourthPoint_;
  };
}

#endif
