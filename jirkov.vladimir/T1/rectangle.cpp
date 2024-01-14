#include "rectangle.hpp"
using namespace jirkov;

Rectangle::Rectangle(rectangle_t rect) :
  rectangle_(rect)
{}

double Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}

void Rectangle::move(const point_t& destination)
{
  rectangle_.pos = destination;
}

void Rectangle::move(double moveX, double moveY)
{
  rectangle_.pos.x += moveX;
  rectangle_.pos.y += moveY;
}

void Rectangle::scale(double k)
{
  rectangle_.width *= k;
  rectangle_.height *= k;
}
