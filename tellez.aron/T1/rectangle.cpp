#include "rectangle.hpp"
#include <stdexcept>

using namespace tellez;

double Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(double dx, double dy)
{
  rect_.pos.x = rect_.pos.x + dx;
  rect_.pos.y = rect_.pos.y + dy;
}

void Rectangle::move(point_t position)
{
  rect_.pos = position;
}

void Rectangle::scale(double ds)
{
  rect_.width = rect_.width * ds;
  rect_.height = rect_.height * ds;
}

Rectangle::Rectangle(point_t one, point_t two):
  rect_({{(one.x + two.x) / 2.0, (one.y + two.y) / 2.0}, two.x - one.x, two.y - one.y})
{
  if (rect_.width <= 0.0 || rect_.height <= 0.0)
  {
    throw std::logic_error("bad rectangle size");
  }
}

Shape * Rectangle::clone() const
{
  return new Rectangle(rect_);
}

Rectangle::Rectangle(rectangle_t rectangle):
  rect_(rectangle)
{}
