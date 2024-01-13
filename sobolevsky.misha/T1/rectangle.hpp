#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace sobolevsky
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(Point_t leftDownPoint, Point_t rightUpPoint);
    double getArea() const override;
    Rectangle_t getFrameRect() const override;
    void move(Point_t newCenter) override;
    void move(double moveX, double moveY) override;
    void scale(double n) override;
  private:
    Rectangle_t rectangle;
  };
}

#endif
