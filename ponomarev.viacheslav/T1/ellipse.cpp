#include "ellipse.hpp"

using namespace ponomarev;

Ellipse::Ellipse(const point_t & centrPoint, const double & firstRadius, const double & secondRadius):
  centrPoint(centrPoint),
  firstRadius(firstRadius),
  secondRadius(secondRadius)
{
  if (firstRadius <= 0 || secondRadius <= 0)
  {
    throw std::invalid_argument("Ellipse is wrong");
  }
}

double Ellipse::getArea() const
{
  return 3.1415926535 * firstRadius * secondRadius;
}

rectangle_t Ellipse::getFrameRect() const
{
  double width = secondRadius * 2;
  double hight = firstRadius * 2;
  point_t center = centrPoint;
  return { width, hight, center };
}

void Ellipse::move(const point_t & newCenter)
{
  double offsetX = newCenter.x - centrPoint.x;
  double offsetY = newCenter.y - centrPoint.y;
  move(offsetX, offsetY);
}

void Ellipse::move(const double & offsetX, const double & offsetY)
{
  centrPoint.x += offsetX;
  centrPoint.y += offsetY;
}

void Ellipse::scaling(double k)
{
  firstRadius *= k;
  secondRadius *= k;
}
