#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"

namespace nikiforov
{
  class Ellipse : public shape
  {
  public:
    Ellipse(point_t firstPoint, double firstRad, double secondRad);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(double x_m, double y_m);
    virtual void move(point_t center);
    virtual void scale(double ratio);
    virtual void point(Ellipse A);
    point_t center;
    point_t movePoint;
    double firstRad;
    double secondRad;
    double width_rect;
    double height_rect;
  private:

  };
}

#endif