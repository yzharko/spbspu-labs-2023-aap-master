#include "rectangle.hpp"

namespace shagieva
{
  Rectangle::Rectangle(const point_t & point1, const point_t & point2):
    pointA(point1),
    pointC(point2)
  {}

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

  void Rectangle::scale(const point_t & scaleCenter, const double & scaleFactor)
  {
    pointA.x = (pointA.x - scaleCenter.x) * scaleFactor + scaleCenter.x;
    pointA.y = (pointA.y - scaleCenter.y) * scaleFactor + scaleCenter.y;
    pointC.x = (pointC.x - scaleCenter.x) * scaleFactor + scaleCenter.x;
    pointC.y = (pointC.y - scaleCenter.y) * scaleFactor + scaleCenter.y;
  }
}
