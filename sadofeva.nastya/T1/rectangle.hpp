#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-tapes.hpp"

namespace sadofeva
{
  class Rectangle: public Shape
  {
  public:
    double getArea() const override;
    Rectangle(Point_t point_1, Point_t point_2);
    Rectangle_t getFrameRect() const override;
    void move(Point_t point) override;
    void move(double _x, double _y) override;
    explicit Rectangle(Rectangle_t rectangle);
    Rectangle_t rectangle_;
    void scale(double k) override;
  };
}
#endif
