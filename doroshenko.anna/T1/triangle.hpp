#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

namespace doroshenko
{
  class Triangle : public Shape
  {
  public:
    Triangle(point_t firstPoint, point_t secondPoint, point_t thirdPoint);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(point_t destination);
    virtual void move(double moveX, double moveY);
    virtual void scale(double coefficient);
  private:
    point_t firstPoint_;
    point_t secondPoint_;
    point_t thirdPoint_;
  };
}

#endif
