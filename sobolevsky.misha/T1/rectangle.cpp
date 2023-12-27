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

  
}