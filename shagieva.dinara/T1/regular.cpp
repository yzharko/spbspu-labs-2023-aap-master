#include "regular.hpp"
#include <cmath>
#include <algorithm>

using namespace shagieva;

Regular::Regular(const point_t point1, const point_t point2, const point_t point3)
{
  points[0] = point1;
  points[1] = point2;
  points[2] = point3;
}

double Regular::getArea() const
{
  double triangleBase = getLength(points[1], points[2]);
  double triangleHeight = getLength(points[0], points[1]);

  int numberOfSides = getNumberOfSides();
  double triangleArea = (triangleBase * triangleHeight) / 2;

  return numberOfSides * triangleArea * 2;
}

rectangle_t Regular::getFrameRect() const
{
  int numberOfSides = getNumberOfSides();
  double regularAngle = (numberOfSides - 2) * 180 / numberOfSides;
  double externalAngle = 180 - regularAngle;
  double regularSide = getLength(points[1], points[2]) * 2;
  double extraWidth = regularSide * std::cos(externalAngle * 3.14 / 180);
  double extraHeight = regularSide * std::sin(externalAngle * 3.14 / 180);
  return { extraWidth * 2 + regularSide, extraHeight + extraWidth , points[0] };
}

void Regular::move(const double dx, const double dy)
{
  for (int i = 0; i < 3; ++i)
  {
    points[i].x += dx;
    points[i].y += dy;
  }
}

void Regular::move(const point_t newCenter)
{
  double dx = newCenter.x - points[0].x;
  double dy = newCenter.y - points[0].y;
  move(dx, dy);
}

void Regular::scale(const double scaleFactor)
{
  for (int i = 1; i < 3; ++i)
  {
    points[i].x = (points[i].x - points[0].x) * scaleFactor + points[0].x;
    points[i].y = (points[i].y - points[0].y) * scaleFactor + points[0].y;
  }
}

double Regular::getLength(const point_t point1, const point_t point2) const
{
  return std::hypot(point2.x - point1.x, point2.y - point1.y);
}

double Regular::getCenterAngle() const
{
  point_t a = { points[1].x - points[0].x, points[1].y - points[0].y };
  point_t b = { points[2].x - points[0].x, points[2].y - points[0].y };

  double scalarProduct = a.x * b.x + a.y * b.y;
  double lenA = std::hypot(a.x, a.y);
  double lenB = std::hypot(b.x, b.y);

  double centerAngle = std::acos(std::fabs(scalarProduct) / (lenA * lenB));
  centerAngle *= (180 / 3.14);

  return centerAngle;
}

int Regular::getNumberOfSides() const
{

  double angle = getCenterAngle();
  double numberOfSides = 180 / angle;

  return static_cast<int>(round(numberOfSides));
}