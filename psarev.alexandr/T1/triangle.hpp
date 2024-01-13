#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
#include <cmath>

namespace psarev
{
  class Triangle : public Shape
  {
  public:
    Triangle(point_t firCorner, point_t secCorner, point_t thirCorner);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newCenter) override;
    void move(double xCh, double yCh) override;
    void scale(double coef) override;
  private:
    point_t firCorner;
    point_t secCorner;
    point_t thirCorner;
  };
}

#endif
