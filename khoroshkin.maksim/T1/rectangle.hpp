#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace khoroshkin
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t newLeftPoint, point_t newRightPoint);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & newPoint) override;
    void move(double dx, double dy) override;
    void scale(double k) override;
  private:
    rectangle_t rectangle;
    point_t leftPoint;
    point_t rightPoint;
  };
}

#endif
