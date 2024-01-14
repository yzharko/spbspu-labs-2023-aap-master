#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace ponomarev
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t & lowerLeft, const point_t & upperRight);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & newCenter);
    virtual void move(const double & offsetX, const double & offsetY);

  private:
    point_t lowerLeft;
    point_t upperRight;
    virtual void scaling(const double k);
  };
}

#endif
