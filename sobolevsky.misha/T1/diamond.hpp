#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"

namespace sobolevsky
{
  class Diamond : public Shape
  {
  public:
    Diamond(Point_t upPoint2, Point_t rightPoint2, Point_t centerPoint2);
    double getArea() const override;
    Rectangle_t getFrameRect() const override;
    void move(Point_t newCenter) override;
    void move(double moveX, double moveY) override;
    void scale(double n) override;
  private:
    Rectangle_t rectangle;
    Point_t upPoint;
    Point_t rightPoint;
    Point_t centerPoint;
    double firstDiagonal;
    double secondDiagonal;
  };
}

#endif
