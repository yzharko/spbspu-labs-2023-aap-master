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

  }

  Rectangle_t Parallelogram::getFrameRect()
  {

  }
  
  void Parallelogram::move(Point_t newCenter)
  {

  }
  
  void Parallelogram::move(double moveX, double moveY)
  {

  }
  
  void Parallelogram::scale(double n)
  {

  }
}
