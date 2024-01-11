#include "parallelogram.hpp"

namespace sobolevsky
{
  Parallelogram::Parallelogram(Point_t Point1_1, Point_t Point2_1, Point_t Point3_1)
  {
    Point1 = Point1_1;
    Point2 = Point2_1;
    Point3 = Point3_1;
    centerPoint.x = (Point2.x + Point3.x) / 2;
    centerPoint.y = (Point2.y + Point3.y) / 2;
  }

  double Parallelogram::getArea()
  {
    return ((Point2.x - Point1.x) * (Point1.y - Point3.y));
  }

  Rectangle_t Parallelogram::getFrameRect()
  {
    rectangle.pos = centerPoint;
    rectangle.height = (Point1.y - Point3.y);
    rectangle.width = (Point2.x - Point1.x);
    return rectangle;
  }

  void Parallelogram::move(double moveX, double moveY)
  {
    Point1.x += moveX;
    Point1.y += moveY;
    Point2.x += moveX;
    Point2.y += moveY;
    Point3.x += moveX;
    Point3.y += moveY;
    centerPoint.x += moveX;
    centerPoint.y += moveY;
  }

  void Parallelogram::move(Point_t newCenter)
  {
    double moveX = centerPoint.x - newCenter.x;
    double moveY = centerPoint.y - newCenter.y;
    centerPoint = newCenter;
    Point1.x += moveX;
    Point1.y += moveY;
    Point2.x += moveX;
    Point2.y += moveY;
    Point3.x += moveX;
    Point3.y += moveY;
  }

  void Parallelogram::scale(double n)
  {
    Point1.x *= n;
    Point1.y *= n;
    Point2.x *= n;
    Point2.y *= n;
    Point3.x *= n;
    Point3.y *= n;
  }
}
