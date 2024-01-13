#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"

namespace psarev
{
  class Ring : public Shape
  {
  public:
    Ring(point_t point, double firRad, double secRad);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newCenter) override;
    void move(double xCh, double yCh) override;
    void scale(double coef) override;
  private:
    point_t center;
    double exterRad;
    double interRad;
  };
}

#endif
