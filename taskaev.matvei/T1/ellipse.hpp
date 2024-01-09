#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "baseTypes.hpp"
#include "Shape.hpp"

namespace taskaev
{
  class Ellipse : public Shape
  {
  public:
    Ellipse(point_t center, double verticalRad, double gorisontRad);
    double getArea();
    rectangle_t getFrameRect();
    void move(double x, double y);
    void move(point_t newCenter);
    void scale(double k);

  private:
    point_t center_;
    double verticalRad_;
    double gorisontRad_;
  };
}
#endif
