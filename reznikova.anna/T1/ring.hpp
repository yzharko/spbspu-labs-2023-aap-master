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
    ~Ring() = default;
    double getArea();
    rectangle_t getFrameRect();
    void move(double dx, double dy);
    void move(point_t new_center);
    void scale(double n);
  private:
    point_t center_;
    double r1_;
    double r2_;
  };
}

#endif
