#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <stdio.h>
#include "shape.hpp"
#include "base-types.hpp"

namespace reznikova
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t leftpoint, point_t rightpoint);
    ~Rectangle() = default;
    double getArea();
    rectangle_t getFrameRect();
    void move(double dx, double dy);
    void move(point_t new_center);
    void scale(double n);
  private:
    point_t leftpoint_;
    point_t rightpoint_;
  };
}

#endif
