#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace shagieva
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t & bottomLeftPoint, const point_t & topRightPoint);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const double & dx, const double & dy);
    virtual void move(const point_t & newCenter);

  private:
    point_t pointA;
    point_t pointC;
    virtual void doScale(const double scaleFactor);
  };
}

#endif
