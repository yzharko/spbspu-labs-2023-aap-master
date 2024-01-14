#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include " base-types.hpp"

namespace kaseev
{
  class Rectangle : public shape {
  public:
    Rectangle(point_t lPoint, point_t rPoint);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double nx, double ny);
    void move(point_t center);
    void scale(double k);
  private:
    point_t lPoint;
    point_t rPoint;
  };
}
#endif
