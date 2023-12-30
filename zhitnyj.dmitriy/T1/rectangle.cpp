#include "rectangle.hpp"
#include <cassert>

Rectangle::Rectangle(const point_t& pos, float width, float height) : rect_{ width, height, pos }
{
  assert(width > 0 && height > 0);
}

float Rectangle::getArea() const
{
  return rect_.width * rect_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rect_;
}

void Rectangle::move(const point_t& newPos)
{
  rect_.pos = newPos;
}

void Rectangle::move(float dx, float dy)
{
  rect_.pos.x += dx;
  rect_.pos.y += dy;
}

void Rectangle::scale(float scaleFactor)
{
  assert(scaleFactor > 0);
  rect_.width *= scaleFactor;
  rect_.height *= scaleFactor;
}
