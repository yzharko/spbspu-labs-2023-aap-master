#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace gorbunova
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t pointOne, point_t pointTwo);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t center);
    void move(double xMove, double yMove);
    void scale(point_t posNew, double z);
  private:
    point_t pointOne_;
    point_t pointTwo_;
  };
}
#endif
