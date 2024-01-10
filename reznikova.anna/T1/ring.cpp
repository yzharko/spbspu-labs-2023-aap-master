#include "ring.hpp"
#include <iostream>
#include <cmath>

reznikova::Ring::Ring(point_t center, double r1, double r2):
  center_(center),
  r1_(r1),
  r2_(r2)
{
  if (r1 < r2)
  {
    throw std::runtime_error("wrong parameters\n");
  }
}

double reznikova::Ring::getArea()
{
  double Area1 = M_PI * r1_ * r1_;
  double Area2 = M_PI * r2_ * r2_;
  return std::abs(Area1 - Area2);
}

reznikova::rectangle_t reznikova::Ring::getFrameRect()
{
  double width = 0;
  double height = 0;
  width = height = 2 * r2_;
  rectangle_t rectangle(width, height, center_);
  return rectangle;
}

void reznikova::Ring::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void reznikova::Ring::move(point_t new_center)
{
  center_.x = new_center.x;
  center_.y = new_center.y;
}

void reznikova::Ring::scale(double n)
{
  r1_ *= n;
  r2_ *= n;
}
