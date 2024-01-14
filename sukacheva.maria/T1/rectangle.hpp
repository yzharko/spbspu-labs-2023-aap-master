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
  private:
    void scaling(double k) override;
    rectangle_t rectangle;
  };
}
#endif
