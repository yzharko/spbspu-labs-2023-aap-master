#include "rectangle.hpp"
#include <iostream>
#include "base-types.hpp"

reznikova::Rectangle::Rectangle(const rectangle_t& rect):
  rect_(rect)
{
  if (!rect_.width || !rect_.height)
  {
    throw std::logic_error("Bad rectangle!");
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
