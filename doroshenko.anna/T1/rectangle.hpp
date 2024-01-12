#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace doroshenko
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t lowerLeft, point_t upperRight);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& destination);
    virtual void move(double moveX, double moveY);
    virtual void scale(double coefficient);
  private:
    point_t lowerLeft_;
    point_t upperRight_;
  };
}

#endif
