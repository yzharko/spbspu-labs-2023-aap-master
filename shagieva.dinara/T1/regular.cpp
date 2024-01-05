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
  point_t smallR = getCoordinates(points[0], points[1]);
  point_t bigR = getCoordinats(points[0], points[2]);

  double lenSmallR = getLength(smallR);
  double lenBigR = getLength(bigR);

  double cos = getCos(smallR, bigR, lenSmallR, lenBigR);
  double sin = getSin(cos);

  double triangleArea = getTriangleArea(lenSmallR, lenBigR, sin);
  double angle = asin(sin);

  return triangleArea * (360 / angle);
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

point_t shagieva::Regular::getCoordinates(const point_t & point1, const point_t & point2) const
{
  return { point2.x - point1.x, points2.y - points1.y }
}

double shagieva::Regular::getLength(const point_t & seg) const
{
  return std::hypot(seg.x, seg.y);
}

double shagieva::Regular::getCos(const point_t & seg1, const point_t & seg2, const double & lenSeg1, const double & lenSeg2) const
{
  return (seg1.x * seg2.x + seg1.y * seg2.y) / (lenSeg1 * lenSeg2);
}

double shagieva::Regular::getSin(const double & cos) const
{
  return std::sqrt(1 - cos * cos);
}
