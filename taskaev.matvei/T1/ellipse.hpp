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
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(double x, double y);
    virtual void move(const point_t& newCenter);
    virtual void scale(double k);

  private:
    point_t center_;
    double verticalRad_;
    double gorisontRad_;
  };
}
#endif
