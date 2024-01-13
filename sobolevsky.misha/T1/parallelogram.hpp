#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"

namespace sobolevsky
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram(Point_t Point1_1, Point_t Point2_1, Point_t Point3_1);
    double getArea() const override;
    Rectangle_t getFrameRect() const override;
    void move(Point_t newCenter) override;
    void move(double moveX, double moveY) override;
    void scale(double n) override;
  private:
    Rectangle_t rectangle;
    Point_t Point1;
    Point_t Point2;
    Point_t Point3;
    Point_t centerPoint;
  };
}

#endif