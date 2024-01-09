#include "rectangle.hpp"
#include <cmath>

khoroshkin::Rectangle::Rectangle(point_t newLeftPoint, point_t newRightPoint) :
  leftPoint(newLeftPoint), rightPoint(newRightPoint)
{
  rectangle = {fabs(leftPoint.x-rightPoint.x),fabs(leftPoint.y-rightPoint.y), {(leftPoint.x+rightPoint.x)/2,(leftPoint.y+rightPoint.y)/2}};
}
double khoroshkin::Rectangle::getArea()
{
  return rectangle.height * rectangle.width;
}

rectangle_t khoroshkin::Rectangle::getFrameRect()
{
  return {fabs(leftPoint.x-rightPoint.x), fabs(leftPoint.y-rightPoint.y), {(leftPoint.x+rightPoint.x)/2, (leftPoint.y+rightPoint.y)/2}};
}

void khoroshkin::Rectangle::move(point_t newPoint)
{
  leftPoint = {leftPoint.x + (newPoint.x - rectangle.pos.x), leftPoint.y + (newPoint.y - rectangle.pos.y)};

  rightPoint = {rightPoint.x + (newPoint.x - rectangle.pos.x), rightPoint.y + (newPoint.y - rectangle.pos.y)};

  rectangle.pos = newPoint;
}

void khoroshkin::Rectangle::move(double dx, double dy)
{
  leftPoint = {leftPoint.x + dx, leftPoint.y + dy};

  rightPoint = {rightPoint.x + dx, rightPoint.y + dy};

  rectangle.pos = {rectangle.pos.x + dx, rectangle.pos.y + dy};
}

void khoroshkin::Rectangle::scale(double k)
{
  leftPoint = {rectangle.pos.x + k * (leftPoint.x - rectangle.pos.x), rectangle.pos.y + k * (leftPoint.y - rectangle.pos.y)};

  rightPoint = {rectangle.pos.x + k * (rightPoint.x - rectangle.pos.x), rectangle.pos.y + k * (rightPoint.y - rectangle.pos.y)};

  rectangle.height *= k;
  rectangle.width *= k;
}
