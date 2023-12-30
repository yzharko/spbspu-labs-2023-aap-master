#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace shagieva
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t & firstPoint, const point_t & secondPoint);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & newPos);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double scaleFactor);

  private:
    point_t cornerA;
    point_t cornerC;
    point_t pos;
  };
}

#endif
