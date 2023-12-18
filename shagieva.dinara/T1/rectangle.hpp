#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace shagieva
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t firstPoint, const point_t secondPoint);
    virtual rectangle_t getFrameRect();
    virtual double getArea();
    virtual void move(point_t newCenter);
    virtual void move(double dX, double dY);
    virtual void scale(point_t pos, double k);

  private:
    point_t cornerA;
    point_t cornerC;
    point_t center;
  };
}

#endif
