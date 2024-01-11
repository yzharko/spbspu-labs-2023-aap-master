#include "base-tapes.h"
#include "rectangle.h"

sadofeva::Rectangle::Rectangle(Rectangle_t rectangle):
  rectangle_(rectangle)
{}

double sadofeva::Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

sadofeva::Rectangle_t sadofeva::Rectangle::getFrameRect() const
{
  return rectangle_;
}

void sadofeva::Rectangle::move(Point_t point)
{
  rectangle_.pos = point;
}

void sadofeva::Rectangle::move(double _x, double _y)
{
  rectangle_.pos.x += _x;
  rectangle_.pos.y += _y;
}
