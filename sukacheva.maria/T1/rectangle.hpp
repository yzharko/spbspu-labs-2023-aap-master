#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace sukacheva
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t rightPoint, point_t leftPoint);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const double& x, const double& y);
    void move(const point_t& center);
    void newScale(const point_t& center, const double& k);
    void scale(double k);
  private:
    point_t right_point;
    point_t left_point;
  };
}
#endif
