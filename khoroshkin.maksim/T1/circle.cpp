#include "circle.hpp"
#include <cmath>

khoroshkin::Circle::Circle(point_t centerPoint, double r) :
  Point(centerPoint), radius(r)
{}

double khoroshkin::Circle::getArea()
{
  return PI * radius * radius;
}

rectangle_t khoroshkin::Circle::getFrameRect()
{
  point_t leftPoint = {Point.x - radius, Point.y - radius};
  point_t rightPoint = {Point.x + radius, Point.y + radius};
  return {fabs(leftPoint.x - rightPoint.x), fabs(leftPoint.y - rightPoint.y),
  {(leftPoint.x + rightPoint.x)/2, (leftPoint.y + rightPoint.y)/2}};
}

void khoroshkin::Circle::move(point_t newPoint)
{
  Point = newPoint;
}

void khoroshkin::Circle::move(double dx, double dy)
{
  Point.x += dx;
  Point.y += dy;
}

void khoroshkin::Circle::scale(double k)
{
  radius *= k;
}
