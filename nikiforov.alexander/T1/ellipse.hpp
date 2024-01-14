#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"

namespace nikiforov
{
  class Ellipse : public Shape
  {
  public:
    ~Ellipse() = default;
    Ellipse(point_t firstPoint, double firstRad, double secondRad);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(double x_m, double y_m);
    virtual void move(point_t center);
    virtual void scale(double ratio);
    point_t lPoint;
    point_t rPoint;
  private:
    point_t center;
    point_t movePoint;
    double firstRad;
    double secondRad;
    double width_rect;
    double height_rect;
  };
}

#endif
