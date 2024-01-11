#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace sukacheva
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t rp, point_t lp);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double x, double y);
    void move(point_t center);
    void scale(double k);
    void newScale(point_t center, double k);
  private:
    point_t right_point;
    point_t left_point;
  };
}
#endif
