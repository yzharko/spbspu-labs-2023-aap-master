#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace sobolevsky
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(Point_t leftDownPoint, Point_t rightUpPoint);
    double getArea();
    Rectangle_t getFrameRect();
    void move(Point_t newCenter);
    void move(double moveX, double moveY);
    void scale(double n);
  private:
    Rectangle_t rectangle;
  };
}

#endif
