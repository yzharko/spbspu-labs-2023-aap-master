#include "ring.hpp"
#include <iostream>
#include <cmath>

reznikova::Ring::Ring(point_t center, double big_rad, double small_rad):
  center_(center),
  big_rad_(big_rad),
  small_rad_(small_rad)
{
  if ((big_rad <= small_rad) || (big_rad <= 0) || (small_rad <= 0))
  {
    throw std::runtime_error("wrong parameters\n");
  }
}

double reznikova::Ring::getArea() const
{
  double Area1 = M_PI * big_rad_ * big_rad_;
  double Area2 = M_PI * small_rad_ * small_rad_;
  return std::abs(Area1 - Area2);
}

reznikova::rectangle_t reznikova::Ring::getFrameRect() const
{
  double width = 0;
  double height = 0;
  width = height = 2 * big_rad_;
  rectangle_t rectangle{width, height, center_};
  return rectangle;
}

void reznikova::Ring::move(const double& dx, const double& dy)
{
  center_.x += dx;
  center_.y += dy;
}

void reznikova::Ring::move(const point_t& new_center)
{
  center_.x = new_center.x;
  center_.y = new_center.y;
}

void reznikova::Ring::scale(const double n)
{
  big_rad_ *= n;
  small_rad_ *= n;
}
