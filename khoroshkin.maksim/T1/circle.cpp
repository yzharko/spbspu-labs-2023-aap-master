#include "circle.hpp"
#include <cmath>

using namespace khoroshkin;
Circle::Circle(point_t centerPoint, double r) :
  Point(centerPoint), radius(r)
{}

double Circle::getArea() const
{
  return PI * radius * radius;
}

rectangle_t Circle::getFrameRect() const
{
  point_t leftPoint = {Point.x - radius, Point.y - radius};
  point_t rightPoint = {Point.x + radius, Point.y + radius};
  return {fabs(leftPoint.x - rightPoint.x), fabs(leftPoint.y - rightPoint.y),
  {(leftPoint.x + rightPoint.x)/2, (leftPoint.y + rightPoint.y)/2}};
}

void Circle::move(const point_t & newPoint)
{
  Point = newPoint;
}

void Circle::move(double dx, double dy)
{
  Point.x += dx;
  Point.y += dy;
}

void Circle::scale(double k)
{
  radius *= k;
}
