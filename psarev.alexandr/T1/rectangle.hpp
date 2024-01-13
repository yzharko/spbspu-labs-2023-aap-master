#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace psarev
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t firPoint, point_t secPoint);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newCenter) override;
    void move(double xCh, double yCh) override;
    void scale(double coef) override;
  private:
    point_t llCorner;
    point_t urCorner;
    point_t center;
  };
}

#endif
