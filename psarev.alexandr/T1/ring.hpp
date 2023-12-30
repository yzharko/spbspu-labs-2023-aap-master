#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"

namespace psarev
{
  class Ring : public Shape
  {
  public:
    Ring(point_t point, double firRad, double secRad);
    virtual double getArea() override;
    virtual rectangle_t getFrameRect() override;
    virtual void move(point_t newCenter) override;
    virtual void move(double xCh, double yCh) override;
    virtual void scale(double coef) override;
  private:
    point_t center;
    double exterRad;
    double interRad;
  };
}

#endif
