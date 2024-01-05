#include "regular.hpp"
#include <cmath>

shagieva::Regular::Regular(const point_t & point1, const point_t & point2, const point_t & point3)
{
  points[0] = point1;
  points[1] = point2;
  points[2] = point3;
}

double shagieva::Regular::getArea() const
{

}

rectangle_t shagieva::Regular::getFrameRect() const
{

}

void shagieva::Regular::move(const double & dx, const double & dy)
{
  for (int i = 0; i < 3; ++i)
  {
    points[i].x += dx;
    points[i].y += dy;
  }
}

void shagieva::Regular::move(const point_t & newCenter)
{
  double dx = newCenter.x - points[0].x;
  double dy = newCenter.y - points[0].y;
  move(dx, dy);
}

void shagieva::Regular::scale(const double & scaleFactor)
{
  for (int i = 1; i < 3; ++i)
  {
    points[i].x = (points[i].x - points[0].x) * scaleFactor + points[0].x;
    points[i].y = (points[i].y - points[0].y) * scaleFactor + points[0].y;
  }
}

double shagieva::Rectangle::getLength(const point_t & point1, const point_t & point2) const
{
  return std::hypot(point2.x - point1.x, point2.y - point1.y);
}
