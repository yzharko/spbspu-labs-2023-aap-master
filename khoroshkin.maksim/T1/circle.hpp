#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace khoroshkin
{
  class Circle : public Shape
  {
  public:
    Circle(point_t centerPoint, double r);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t & newPoint) override;
    void move(double dx, double dy) override;
  private:
    void doScale(double k) override;
    point_t Point;
    double radius;
    const double PI = 3.14;
  };
}

#endif
