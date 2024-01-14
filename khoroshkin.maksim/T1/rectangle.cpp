#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>

using namespace khoroshkin;
Rectangle::Rectangle(point_t newLeftPoint, point_t newRightPoint) :
  leftPoint(newLeftPoint), rightPoint(newRightPoint)
{
  double width = fabs(leftPoint.x-rightPoint.x);
  double height = fabs(leftPoint.y-rightPoint.y);
  point_t pos = {(leftPoint.x + rightPoint.x) / 2,(leftPoint.y + rightPoint.y) / 2};
  rectangle = {width, height, pos};
}

double khoroshkin::Rectangle::getArea() const
{
  return rectangle.height * rectangle.width;
}

rectangle_t Rectangle::getFrameRect() const
{
  return {fabs(leftPoint.x-rightPoint.x), fabs(leftPoint.y-rightPoint.y), {(leftPoint.x+rightPoint.x)/2, (leftPoint.y+rightPoint.y)/2}};
}

void Rectangle::move(const point_t & newPoint)
{
  leftPoint = {leftPoint.x + (newPoint.x - rectangle.pos.x), leftPoint.y + (newPoint.y - rectangle.pos.y)};

  rightPoint = {rightPoint.x + (newPoint.x - rectangle.pos.x), rightPoint.y + (newPoint.y - rectangle.pos.y)};

  rectangle.pos = newPoint;
}

void Rectangle::move(double dx, double dy)
{
  leftPoint = {leftPoint.x + dx, leftPoint.y + dy};

  rightPoint = {rightPoint.x + dx, rightPoint.y + dy};

  rectangle.pos = {rectangle.pos.x + dx, rectangle.pos.y + dy};
}

void Rectangle::scale(double k)
{
  if (k <= 0)
  {
    throw std::invalid_argument("Error: scale factor must be >0\n");
  }
  else
  {
    leftPoint = {rectangle.pos.x + k * (leftPoint.x - rectangle.pos.x), rectangle.pos.y + k * (leftPoint.y - rectangle.pos.y)};
    rightPoint = {rectangle.pos.x + k * (rightPoint.x - rectangle.pos.x), rectangle.pos.y + k * (rightPoint.y - rectangle.pos.y)};

    rectangle.height *= k;
    rectangle.width *= k;
  }
}
