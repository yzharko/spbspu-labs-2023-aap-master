#ifndef REGULAR_HPP
#define REGULAR_HPP
#include <stdio.h>
#include <iostream>
#include <cmath>
#include "shape.hpp"
#include "base-types.hpp"

namespace reznikova
{
  class Regular : public Shape
  {
  public:
    Regular(point_t center, point_t point1, point_t point2);
    virtual ~Regular() = default;
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(double dx, double dy);
    virtual void move(point_t new_center);
    virtual void scale(double n);
  private:
    point_t center_;
    point_t point1_;
    point_t point2_;
    double r;
    double R;
    double num_sides;
  };
}

#endif
