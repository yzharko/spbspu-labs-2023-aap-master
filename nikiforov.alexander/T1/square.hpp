#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "shape.hpp"

namespace nikiforov
{
  class Square : public Shape
  {
  public:
    Square(point_t firstPoint, double length);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(double x_m, double y_m);
    virtual void move(point_t center);
    virtual void scale(double ratio);
    point_t lPoint;
    point_t rPoint;
    point_t center;
    point_t movePoint;
    double length;
  private:

  };
}

#endif
