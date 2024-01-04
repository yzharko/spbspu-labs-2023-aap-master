#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace shagieva
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t & point1, const point_t & point2);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & newCenter);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double scaleFactor);

  private:
    point_t pointA;
    point_t pointC;
    point_t center;
  };
}

#endif
