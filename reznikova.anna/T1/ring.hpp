#ifndef RING_HPP
#define RING_HPP
#include <stdio.h>
#include "shape.hpp"
#include "base-types.hpp"

namespace reznikova
{
  class Ring : public Shape
  {
  public:
    Ring(point_t center, double r1, double r2);
    ~Ring() override = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t new_center) override;
    void scale(double n) override;
    void scale(point_t scale_center, double n) override;
  private:
    point_t center_;
    double r1_;
    double r2_;
  };
}

#endif
