#ifndef REGULAR_HPP
#define REGULAR_HPP
#include "shape.hpp"

namespace shagieva
{
  class Regular: public Shape
  {
  public:
    Regular(const point_t & centerPoint, const point_t & smallRadiusPoint, const point_t & BigRadiusPoint);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const double & dx, const double & dy);
    virtual void move(const point_t & newCenter);

  private:
    point_t points[3];
    double numberOfSides;
    virtual void doScale(const double scaleFactor);
    double getLength(const point_t & point1, const point_t & point2) const;
    double getCenterAngle() const;
  };
}

#endif
