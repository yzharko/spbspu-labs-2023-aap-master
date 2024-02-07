#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"

namespace ponomarev
{
  class Ellipse: public Shape
  {
  public:
    Ellipse(const point_t & centrPoint, const double & firstRadius, const double & secondRadius);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & newCenter);
    virtual void move(const double & offsetX, const double & offsetY);
  private:
    point_t centrPoint;
    double firstRadius;
    double secondRadius;
    virtual void scaling(const double k);
  };
}

#endif
