#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace sobolevsky
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t leftDownPoint, point_t rightUpPoint);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newCenter) override;
    void move(double moveX, double moveY) override;
    void scale(double n) override;
  private:
    rectangle_t rectangle;
  };
}

#endif
