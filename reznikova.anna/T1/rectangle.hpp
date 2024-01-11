#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include <stdio.h>
#include "shape.hpp"
#include "base-types.hpp"

namespace reznikova
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t leftpoint, point_t rightpoint);
    ~Rectangle() override = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t new_center) override;
    void scale(double n) override;
    void newscale(point_t scale_center, double n) override;
  private:
    point_t leftpoint_;
    point_t rightpoint_;
  };
}

#endif
