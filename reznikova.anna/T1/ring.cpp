#include "ring.hpp"
#include <iostream>
#include <cmath>

Ring::Ring(point_t center, double r1, double r2):
  center_(center),
  r1_(r1),
  r2_(r2)
{
  if (r1 < r2)
  {
    throw std::runtime_error("wrong parameters\n");
  }
}

double Ring::getArea()
{
  double Area1 = M_PI * r1_ * r1_;
  double Area2 = M_PI * r2_ * r2_;
  return std::abs(Area1 - Area2);
}

rectangle_t Ring::getFrameRect()
{
  double width = 0;
  double height = 0;
  width = height = 2 * r2_;
  rectangle_t rectangle(width, height, center_);
  return rectangle;
}

void Ring::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Ring::move(point_t new_center)
{
  center_.x = new_center.x;
  center_.y = new_center.y;
}

void Ring::scale(double n)
{
  r1_ *= n;
  r2_ *= n;
}
