#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "base-tapes.hpp"
#include "shape.hpp"

namespace sadofeva
{
  class Ellipse : public Shape
  {
    Ellipse(Point_t point, double r_1, double r_2);
    double getArea() const override;
    Rectangle_t getFrameRect() const override;
    void move(double _x, double _y) override;
    void move(Point_t point) override;
    void scale(double k);
  private:
    double r1,r2;
    Rectangle_t rectangle_t;
  };
}

#endif
