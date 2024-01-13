#include <stdexcept>
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

sadofeva::Rectangle::Recnagle(Point_t point1, Point_t point2):
  rectangle_({{(point1.x + point2.y) / 2.0 , (point1.y + point2.y) / 2.0} , point2.x - point1.x, point2.y - point1.y })
{
  if (rectangle_.width <= 0.0 || rectangle_.height <= 0.0)
  {
    throw std::logic_error("not size");
  }
}

void sadofeva::Rectangle::scale(double k)
{
  rectangle_.width *= k;
  rectangle_.height *= k;
}
