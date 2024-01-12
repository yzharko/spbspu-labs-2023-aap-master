#include "rectangle.hpp"
#include <iostream>

using namespace anikanov;

double Rectangle::getArea() const
{
  return width * height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t{cPoint, width, height};
}

void Rectangle::move(const point_t newCPoint)
{
  cPoint = newCPoint;
}

void Rectangle::move(const double x, const double y)
{
  cPoint = point_t{x, y};
}

void Rectangle::scale(const double k)
{
  if (k < 0) {
    throw std::logic_error("Invalid scale argument");
  }
  width *= 2;
  height *= 2;
  cPoint.x += (k - 1) * getDX(cPoint, point_t{0, 0});
  cPoint.y += (k - 1) * getDY(cPoint, point_t{0, 0});
}

namespace anikanov {
  std::istream &operator>>(std::istream &in, Rectangle &rec)
  {
    point_t leftBottom, rightTop;
    if (!(in >> leftBottom >> rightTop)) {
      throw std::overflow_error("Invalid Input Rectangle");
    }
    if (rightTop.x <= leftBottom.x || rightTop.y <= leftBottom.y) {
      throw std::overflow_error("Invalid Input Rectangle");
    }
    rec.width = rightTop.x - leftBottom.x;
    rec.height = rightTop.y - leftBottom.y;
    rec.cPoint = point_t{leftBottom.x + rec.width / 2, leftBottom.y + rec.height / 2};
    return in;
  }

  point_t Rectangle::getCPoint()
  {
    return cPoint;
  }
}

double Rectangle::getDX(point_t fp, point_t sp)
{
  return fp.x - sp.x;
}

double Rectangle::getDY(point_t fp, point_t sp)
{
  return fp.y - sp.y;
}
