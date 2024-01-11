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
    virtual ~Rectangle() = default;
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(double dx, double dy);
    virtual void move(point_t new_center);
    virtual void scale(double n);
  private:
    point_t leftpoint_;
    point_t rightpoint_;
  };
}

#endif
