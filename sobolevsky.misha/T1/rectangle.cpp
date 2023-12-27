#include "rectangle.hpp"

namespace sobolevsky
{
  Rectangle::Rectangle(Point_t leftDownPoint, Point_t rightUpPoint)
  {
    Point_t center;
    center.x = (leftDownPoint.x - rightUpPoint.x) / 2;
    center.y = (leftDownPoint.y - rightUpPoint.y) / 2;
    rectangle.pos = center;
    rectangle.width = leftDownPoint.x - rightUpPoint.x;
    rectangle.height = leftDownPoint.y - rightUpPoint.y;
  }

  double Rectangle::getArea()
  {
    return rectangle.width * rectangle.height;
  }
  
  Rectangle_t Rectangle::getFrameRect()
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
