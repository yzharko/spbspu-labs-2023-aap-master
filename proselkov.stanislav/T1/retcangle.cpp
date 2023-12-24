#include "rectangle.hpp"
#include <stdexept>

Rectangle::Rectangle(point_t p1, point_t p2) :
  p_1(p1), p_2(p2)
{}

double Rectangle::getArea() const
{
  return (rectangle.height * rectangle.width);
}

rectangle_t Rectangle::getFrameRect() const
{
    return { p_2.x - p_1.x, p_2.y - p_1.y, { (p_1.x + p_2.x) / 2, ((p_1.y + p_2.y) / 2) } };
}

void Rectangle::move(point_t newpoint)
{
  rectangle_t frame = getFrameRect();
  double x = newpoint.x - frame.pos_.x;
  double y = newpoint.y - frame.pos_.y;
  p_1.x += x;
  p_1.y += y;
  p_2.x += x;
  p_2.y += y;
}

void Rectangle::move(point_t point)
{
    rectangle.pos = newpoint;
}
