#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace gorbunova
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t pointOne, point_t pointTwo);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t center);
    virtual void move(double xMove, double yMove);
    virtual void scale(double k);
  private:
    point_t pointOne_;
    point_t pointTwo_;
  };
}
#endif
