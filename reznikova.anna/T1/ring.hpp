#ifndef RING_HPP
#define RING_HPP
#include <stdio.h>
#include "shape.hpp"
#include "base-types.hpp"

namespace reznikova
{
  class Ring : public Shape
  {
  public:
    Ring(point_t center, double r1, double r2);
    virtual ~Ring() = default;
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(double dx, double dy);
    virtual void move(point_t new_center);
    virtual void scale(double n);
  private:
    point_t center_;
    double r1_;
    double r2_;
  };
}

#endif
