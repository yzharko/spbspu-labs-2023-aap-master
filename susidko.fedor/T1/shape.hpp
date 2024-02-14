#include "base-types.hpp"
#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape
{
  public:
    virtual double getArea() = 0;
    virtual rectangle_t getFrameRect() = 0;
    virtual void move(double, double) = 0;
    virtual void move(point_t) = 0;
    virtual rectangle_t scale(double, double, double, rectangle_t) = 0;
};
#endif
