#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include <iostream>
#include <stdio.h>
#include "baseTypes.hpp"
#include "Shape.hpp"

namespace taskaev
{
  class Concave : public Shape
  {
  public:
    Concave(point_t left, point_t right, point_t inner, point_t upper);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(double x, double y);
    virtual void move(const point_t& newCenter);
    virtual void scale(double k);

  private:
    point_t p1;
    point_t p2;
    point_t p3;
    point_t p4;
  };
}
#endif

