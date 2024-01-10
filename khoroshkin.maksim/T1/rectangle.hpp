#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace khoroshkin
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t newLeftPoint, point_t newRightPoint);
    virtual double getArea() const override;
    virtual rectangle_t getFrameRect() const override;
    virtual void move(point_t newPoint) override;
    virtual void move(double dx, double dy) override;
    virtual void scale(double k) override;
  private:
    rectangle_t rectangle;
    point_t leftPoint;
    point_t rightPoint;
  };
}

#endif
