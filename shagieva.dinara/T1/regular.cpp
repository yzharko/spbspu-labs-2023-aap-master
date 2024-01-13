#include "regular.hpp"
#include <cmath>
#include <algorithm>
#include <stdexcept>

using namespace shagieva;

Regular::Regular(const point_t & centerPoint, const point_t & smallRadiusPoint, const point_t & bigRadiusPoint)
{
  points[0] = centerPoint;
  points[1] = smallRadiusPoint;
  points[2] = bigRadiusPoint;

  double a = std::pow(points[1].x - points[0].x, 2) + std::pow(points[1].y - points[0].y, 2);
  double b = std::pow(points[2].x - points[1].x, 2) + std::pow(points[2].y - points[1].y, 2);
  double c = std::pow(points[2].x - points[0].x, 2) + std::pow(points[2].y - points[0].y, 2);

  if (c != (a + b))
  {
    throw std::invalid_argument("Triangle is incorrect");
  }
  else
  {
    double angle = getCenterAngle();
    numberOfSides = 180 / angle;
    bool regularIsWrong = (std::abs(std::round(numberOfSides) - numberOfSides) > 0.01);

    if (regularIsWrong)
    {
      throw std::invalid_argument("Regular does not exist");
    }
  }

  numberOfSides = std::round(numberOfSides);
}

double Regular::getArea() const
{
  double triangleBase = getLength(points[1], points[2]);
  double triangleHeight = getLength(points[0], points[1]);
  double triangleArea = (triangleBase * triangleHeight) / 2;

  return numberOfSides * triangleArea * 2;
}

rectangle_t Regular::getFrameRect() const
{
  double width = 0;
  if (std::fabs(points[1].x - points[0].x) > std::fabs(points[2].x - points[0].x))
  {
    width = 2 * std::fabs(points[1].x - points[0].x);
  }
  else
  {
    width = 2 * std::fabs(points[2].x - points[0].x);
  }

  double height = 0;
  if (std::fabs(points[1].y - points[0].y) > std::fabs(points[2].y - points[0].y))
  {
    height = 2 * std::fabs(points[1].y - points[0].y);
  }
  else
  {
    height = 2 * std::fabs(points[2].y - points[0].y);
  }

  double rectSide = (width > height ? width : height);
  return { rectSide, rectSide, points[0] };
}

void Regular::move(const double & dx, const double & dy)
{
  for (int i = 0; i < 3; ++i)
  {
    points[i].x += dx;
    points[i].y += dy;
  }
}

void Regular::move(const point_t & newCenter)
{
  double dx = newCenter.x - points[0].x;
  double dy = newCenter.y - points[0].y;
  move(dx, dy);
}

void Regular::doScale(const double scaleFactor)
{
  for (int i = 1; i < 3; ++i)
  {
    points[i].x = (points[i].x - points[0].x) * scaleFactor + points[0].x;
    points[i].y = (points[i].y - points[0].y) * scaleFactor + points[0].y;
  }
}

double Regular::getLength(const point_t & point1, const point_t & point2) const
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
