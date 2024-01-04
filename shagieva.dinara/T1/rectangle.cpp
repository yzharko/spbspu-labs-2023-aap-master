#include "rectangle.hpp"

shagieva::Rectangle::Rectangle(const point_t & point1, const point_t & point2) :
  pointA(point1),
  pointC(point2)
{
  center = { (pointA.x + pointC.x) / 2, (pointA.y + pointC.y) / 2 };
}

double shagieva::Rectangle::getArea() const
{
  double width = pointC.x - pointA.x;
  double height = pointC.y - pointA.y;
  return width * height;
}

rectangle_t shagieva::Rectangle::getFrameRect() const
{
  double width = pointC.x - pointA.x;
  double height = pointC.y - pointA.y;
  return { width, height, center };
}

void shagieva::Rectangle::move(const double dx, const double dy)
{
  pointA.x += dx;
  pointA.y += dy;
  pointC.x += dx;
  pointC.y += dy;
  center = { center.x += dx, center.y += dy };
}

void shagieva::Rectangle::move(const point_t & newCenter)
{
  double dx = newCenter.x - center.x;
  double dy = newCenter.y - center.y;
  move(dx, dy);
}

void shagieva::Rectangle::scale(const double scaleFactor)
{
  pointA.x = (pointA.x - center.x) * scaleFactor + center.x;
  pointA.y = (pointA.y - center.y) * scaleFactor + center.y;
  pointC.x = (pointC.x - center.x) * scaleFactor + center.x;
  pointC.y = (pointC.y - center.y) * scaleFactor + center.y;
}
