#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace redko
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t firstPoint, point_t secondPoint);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t dest);
    void move(double xDist, double yDist);
    void scale(point_t pos, double coefficient);
  protected:
    point_t firstPoint_;
    point_t secondPoint_;
  };
}

#endif
