#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace jirkov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t bottomLeft, point_t topRight);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(const point_t & center);
    virtual void move(const double moveX, const double moveY);
    virtual void scale(double k);
  private:
    point_t bottomLeft_;
    point_t topRight_;
  };
}

#endif
