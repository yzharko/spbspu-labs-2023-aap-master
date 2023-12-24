#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace smolyakov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t bottomLeft, point_t upperRight);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void moveTo(double x, double y) override;
    void moveBy(double x, double y) override;
    void scale(double factor) override;
  private:
    point_t center_;
    double width_;
    double height_;
  };
}

#endif
