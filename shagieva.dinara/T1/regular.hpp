#ifndef REGULAR_HPP
#define REGULAR_HPP
#include "shape.hpp"

namespace shagieva
{
  class Regular: public Shape
  {
  public:
    Regular(const point_t point1, const point_t point2, const point_t point3);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const double dx, const double dy);
    virtual void move(const point_t newCenter);
    virtual void scale(const double scaleFactor);

  private:
    point_t points[3];
    double getLength(const point_t point1, const point_t point2) const;
    double getCenterAngle() const;
    int getNumberOfSides() const;
  };
}

#endif
