#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace ponomarev
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t lowerLeft, point_t upperRight);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(point_t destination);
    virtual void move(double moveX, double moveY);
    virtual void scale(point_t pos, double coefficient);
  private:
    point_t lowerLeft;
    point_t upperRight;
  };
}

#endif
