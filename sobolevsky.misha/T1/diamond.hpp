#ifndef DIAMOND_HPP
#define DIAMOND_HPP
#include "shape.hpp"

namespace sobolevsky
{
  class Diamond : public Shape
  {
  public:
    Diamond(Point_t upPoint2, Point_t rightPoint2, Point_t centerPoint2);
    double getArea();
    Rectangle_t getFrameRect();
    void move(Point_t newCenter);
    void move(double moveX, double moveY);
    void scale(double n);
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
