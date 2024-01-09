#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "baseTypes.hpp"
#include "Shape.hpp"

namespace taskaev
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t leftpoint, point_t rightpoint);
    double getArea();
    rectangle_t getFrameRect();
    void move(double x, double y);
    void move( point_t center);
    void scale(double k);


  private:
    point_t leftPoint_;
    point_t rightPoint_;
  };
}
#endif
