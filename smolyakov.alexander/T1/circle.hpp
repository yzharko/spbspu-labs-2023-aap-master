#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace smolyakov
{
  class Circle : public Shape
  {
  public:
    Circle(point_t center, double radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void moveTo(double x, double y) override;
    void moveBy(double x, double y) override;
    void scale(double factor) override;
  private:
    point_t center_;
    double radius_;
  };
}

#endif
