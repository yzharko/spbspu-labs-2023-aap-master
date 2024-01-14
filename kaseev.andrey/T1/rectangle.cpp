#include <iostream>
#include "rectangle.hpp"
#include " base-types.hpp"

kaseev::Rectangle::Rectangle(point_t lPoint, point_t rPoint):
    lPoint(lPoint),
    rPoint(rPoint)
{}

double kaseev::Rectangle::getArea()
{
  double width = std::abs(rPoint.x - lPoint.x);
  double height = std::abs(rPoint.y - lPoint.y);
  return width * height;
}

rectangle_t kaseev::Rectangle::getFrameRect()
{
  double width = std::abs(rPoint.x - lPoint.x);
  double height = std::abs(rPoint.y - lPoint.y);
  point_t pos = { ((rPoint.x + lPoint.x)/2),((rPoint.y + lPoint.y)/2) };
  return rectangle_t{ width, height, pos};
}

void kaseev::Rectangle::move(double nx, double ny)
{
  lPoint.x += nx;
  lPoint.y += ny;
  rPoint.x += nx;
  rPoint.y += ny;
}

void kaseev::Rectangle::move(point_t center)
{
  double width = std::abs(rPoint.x - lPoint.x);
  double height = std::abs(rPoint.y - lPoint.y);
  rectangle_t New = {width, height, center};
}

void kaseev::Rectangle::scale(double k)
{
  lPoint.x *= k;
  lPoint.y *= k;
  rPoint.x *= k;
  rPoint.y *= k;
}
