#include "rectangle.hpp"
#include <iostream>
#include <exception>
#include "base-types.hpp"

reznikova::Rectangle::Rectangle(rectangle_t rect):
rectangle_(rect)
{
  if ((rect.width <= 0) || (rect.height <= 0))
  {
    throw std::runtime_error("wrong parameters\n");
  }
}

double reznikova::Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

reznikova::rectangle_t reznikova::Rectangle::getFrameRect() const
{
  return rectangle_;
}

void reznikova::Rectangle::move(const double& dx, const double& dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}

void reznikova::Rectangle::move(const point_t& new_center)
{
  rectangle_.pos.x = new_center.x;
  rectangle_.pos.y = new_center.y;
}

void reznikova::Rectangle::scale(const double n)
{
  rectangle_.width *= n;
  rectangle_.height *= n;
}
