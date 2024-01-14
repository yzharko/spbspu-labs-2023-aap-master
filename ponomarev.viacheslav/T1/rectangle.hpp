#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace ponomarev
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t lowerLeft, const point_t upperRight);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(const point_t newCenter);
    virtual void move(const double offsetX, const double offsetY);
    virtual void scale(const double k);
  private:
    point_t lowerLeft;
    point_t upperRight;
  };
}

#endif
