#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"

namespace sobolevsky
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram(point_t Point1_1, point_t Point2_1, point_t Point3_1);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t newCenter) override;
    void move(double moveX, double moveY) override;
    void scale(double n) override;
  private:
    rectangle_t rectangle;
    point_t Point1;
    point_t Point2;
    point_t Point3;
    point_t centerPoint;
  };
}

#endif
