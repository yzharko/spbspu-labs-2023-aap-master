#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <stdio.h>
#include <iostream>
#include "baseTypes.hpp"
#include "Shape.hpp"

namespace taskaev
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t leftpoint, point_t rightpoint);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(double x, double y);
    virtual void move( point_t center);
    virtual void scale(double k);

  private:
    point_t leftPoint_;
    point_t rightPoint_;
  };
}
#endif
