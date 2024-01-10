#include "ring.hpp"
#include <iostream>

Ring::Ring(double x0, double y0, double rad1, double rad2):
  x(x0),
  y(y0),
  r1(rad1),
  r2(rad2)
{
  if (rad1 < rad2)
  {
    throw std::runtime_error("wrong parameters\n");
  }
}

double Ring::getArea()
{
  double Area1 = pi * r1 * r1;
  double Area2 = pi * r2 * r2;
  return std::abs(Area1 - Area2);
}

rectangle_t Ring::getFrameRect()
{
  double width = 0;
  double height = 0;
  width = height = 2 * (r1 > r2 ? r1 : r2);
  point_t pos(x, y);
  rectangle_t rectangle(width, height, pos);
  return rectangle;
}

void Ring::move(double dx, double dy)
{
  x += dx;
  y += dy;
}

void Ring::move(point_t new_center)
{
  x = new_center.x;
  y = new_center.y;
}

void Ring::scale(double n)
{
  r1 *= n;
  r2 *= n;
}

