#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"

namespace khoroshkin
{
  class Circle : public Shape
  {
  public:
    Circle(point_t centerPoint, double r);
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(point_t newPoint) override;
    virtual void move(double dx, double dy) override;
    virtual void scale(double k) override;
  private:
    point_t Point;
    double radius;
    const double PI = 3.14;
  };
}

#endif
