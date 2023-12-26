#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "baseTypes.hpp"

namespace taskaev
{
  class Rectangle : public virtual Shape
  {
  public:
    Rectangle(point_t rx ,point_t ry, point_t lx, point_t ly);
    double getArea();
    rectangle_t getFrameRect();
    void move(double dx, double dy);
    void move (point_t new_center);
    void scale(double c);
  private:
    point_t rp_x;
    point_t rp_y;
    point_t lp_x;
    point_t lp_y;
  };
}
#endif
