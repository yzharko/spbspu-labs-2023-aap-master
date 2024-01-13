#include "rectangle.hpp"

namespace sobolevsky
{
  Rectangle::Rectangle(Point_t leftDownPoint, Point_t rightUpPoint)
  {
    Point_t center;
    center.x = (leftDownPoint.x - rightUpPoint.x) / 2;
    center.y = (leftDownPoint.y - rightUpPoint.y) / 2;
    rectangle.pos = center;
    rectangle.width = rightUpPoint.x - leftDownPoint.x;
    rectangle.height = rightUpPoint.y - leftDownPoint.y;
  }

  double Rectangle::getArea() const
  {
    return rectangle.width * rectangle.height;
  }

  Rectangle_t Rectangle::getFrameRect() const
  {
    return rectangle;
  }

  void Rectangle::move(Point_t newCenter)
  {
    rectangle.pos = newCenter;
  }

  void Rectangle::move(double moveX, double moveY)
  {
    rectangle.pos.x += moveX;
    rectangle.pos.y += moveY;
  }

  void Rectangle::scale(double n)
  {
    rectangle.width *= n;
    rectangle.height *= n;
  }
}
