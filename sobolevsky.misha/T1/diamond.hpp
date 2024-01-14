#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"

namespace sobolevsky
{
  class Diamond : public Shape
  {
  public:
    Diamond(point_t upPoint2, point_t rightPoint2, point_t centerPoint2);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newCenter) override;
    void move(double moveX, double moveY) override;
    void scale(double n) override;
  private:
    rectangle_t rectangle;
    point_t upPoint;
    point_t rightPoint;
    point_t centerPoint;
    double firstDiagonal;
    double secondDiagonal;
  };
}

#endif
