#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace nikiforov 
{
  class Rectangle : public shape
  {
  public:
    Rectangle(point_t firstPoint, point_t secondPoint);
    virtual double getArea();
    virtual rectangle_t getFrameRect();
    virtual void move(double x_m, double y_m);
    virtual void move(point_t center);
    virtual void scale(double ratio);
  private:
    point_t lPoint;
    point_t rPoint;
    double width_rect;
    double height_rect;
  };
}

#endif
