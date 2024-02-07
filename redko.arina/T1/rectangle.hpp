#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace redko
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t & firstPoint, const point_t & secondPoint);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t & dest);
    void move(double xDist, double yDist);
  private:
    point_t firstPoint_;
    point_t secondPoint_;
    void doScale(double coefficient);
  };
}

#endif
