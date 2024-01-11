#include "helpfunct.h"
#include "base-tapes.h"

Point_t  point_intersection(Point_t point1, Point_t point2, Point_t point3, Point_t point4)
{
  Point_t p1, p2, p3, p4;
  double x_0 = 0.0;
  double y_0 = 0.0;
  if (point1.x < point2.x)
  {
    p1 = point1;
    p2 = point2;
  }
  else
  {
    p1 = point2;
    p2 = point1;
  }
  if (point3.x < point4.x)
  {
    p3 = point3;
    p4 = point4;
  }
  else
  {
    p3 = point4;
    p4 = point3;
  }
  if (p1.x - p2.x == 0)
  {
    x_0 = p1.x;
    double a2 = (p3.y - p4.y) / (p3.x - p4.x);
    double b1 = p1.y - a2 * p1.x;
    y_0 = a2 * x_0 + b1;
  }
  else
  {
    double a1 = (p1.y - p2.y) / (p1.x - p2.x);
    double a2 = (p3.y - p4.y) / (p3.x - p4.x);
    double b1 = p1.y - a1 * p1.x;
    double b2 = p3.y - a2 * p3.x;
    x_0 = (b2 - b1) / (a1 - a2);
    y_0 = (x_0 - p1.x) * a1 + p1.y;
  }
  return (x_0, y_0);
}
