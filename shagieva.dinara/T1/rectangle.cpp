#include "rectangle.hpp"

using namespace shagieva;

Rectangle::Rectangle(const point_t & bottomLeftPoint, const point_t & topRightPoint):
  pointA(bottomLeftPoint),
  pointC(topRightPoint)
{
  if (pointA.x >= pointC.x && pointA.y >= pointC.y)
  {
    throw std::invalid_argument("Rectangle is incorrect");
  }
}

double Rectangle::getArea() const
{
  double width = pointC.x - pointA.x;
  double height = pointC.y - pointA.y;
  return width * height;
}

rectangle_t Rectangle::getFrameRect() const
{
  double width = pointC.x - pointA.x;
  double height = pointC.y - pointA.y;
  point_t center = { (pointA.x + pointC.x) / 2, (pointA.y + pointC.y) / 2 };
  return { width, height, center };
}

void Rectangle::move(const double & dx, const double & dy)
{
  pointA.x += dx;
  pointA.y += dy;
  pointC.x += dx;
  pointC.y += dy;
}

void Rectangle::move(const point_t & newCenter)
{
  double dx = newCenter.x - (pointA.x + pointC.x) / 2;
  double dy = newCenter.y - (pointA.y + pointC.y) / 2;
  move(dx, dy);
}

void Rectangle::doScale(const double scaleFactor)
{
  point_t center = { (pointA.x + pointC.x) / 2, (pointA.y + pointC.y) / 2 };
  pointA.x = (pointA.x - center.x) * scaleFactor + center.x;
  pointA.y = (pointA.y - center.y) * scaleFactor + center.y;
  pointC.x = (pointC.x - center.x) * scaleFactor + center.x;
  pointC.y = (pointC.y - center.y) * scaleFactor + center.y;
}
