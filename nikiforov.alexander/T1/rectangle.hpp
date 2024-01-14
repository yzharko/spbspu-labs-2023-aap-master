#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace nikiforov
{
  class Rectangle : public Shape
  {
  public:
    ~Rectangle() = default;
    Rectangle(point_t firstPoint, point_t secondPoint);
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
    double width_rect;
    double height_rect;
  };
}

#endif
