#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

namespace psarev
{
  class Triangle : public Shape
  {
  public:
    Triangle(point_t firCorner, point_t secCorner, point_t thirCorner);
    virtual double getArea() override;
    virtual rectangle_t getFrameRect() override;
    virtual void move(point_t newCenter) override;
    virtual void move(double xCh, double yCh) override;
    virtual void scale(double coef) override;
  private:
    point_t firCorner;
    point_t secCorner;
    point_t thirCorner;
    point_t center;
  };
}

#endif
