#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"

namespace shagieva
{
  class Complexquad: public Shape
  {
  public:
    Complexquad(const point_t point1, const point_t point2, const point_t point3, const point_t point4);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const double dx, const double dy);
    virtual void move(const point_t newCenter);
    virtual void scale(const double scaleFactor);

  private:
    point_t points[4];
    point_t getCenter() const;
    double getTriangleArea(const point_t pointA, const point_t pointB, const point_t pointC) const;
  };
}

#endif
