#include "rectangle.hpp"
#include <iostream>

using namespace anikanov;

Rectangle::Rectangle()
{
  width = 0;
  height = 0;
  cPoint = point_t();
}

void Rectangle::setWidth(float newWidth)
{
  width = newWidth;
}

float Rectangle::getWidth() const
{
  return width;
}

void Rectangle::setHeight(float newHeight)
{
  height = newHeight;
}

float Rectangle::getHeight() const
{
  return height;
}

point_t Rectangle::getCPoint() const
{
  return cPoint;
}

double Rectangle::getArea() const
{
  return width * height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_t(cPoint, width, height);
}

void Rectangle::move(const point_t newCPoint)
{
  cPoint = newCPoint;
}

void Rectangle::move(const float x, const float y)
{
  cPoint = point_t(x, y);
}

void Rectangle::scale(const double k, const point_t center)
{
  if (k < 0) {
    throw std::logic_error("Invalid scale argument");
  }
  width *= 2;
  height *= 2;
  cPoint.x += (k - 1) * getDX(cPoint, center);
  cPoint.y += (k - 1) * getDY(cPoint, center);
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
    rec.cPoint = point_t(leftBottom.x + rec.width / 2,
                        leftBottom.y + rec.height / 2);
    return in;
  }

  void Rectangle::scale(const double k)
  {
    (*this).scale(k, point_t(0, 0));
  }
}
