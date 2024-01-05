#include "rectangle.hpp"
#include <stdexcept>

Rectangle::Rectangle(point_t one, point_t two) :
    rectangle({ {(one.x + two.x) / 2.0, (one.y + two.y) / 2.0}, two.x - one.x, two.y - one.y })
{
  if (rectangle.width <= 0.0 || rectangle.height <= 0.0)
  {
    throw std::invalid_argument("Invalid rectangle size");
  }
}
Rectangle::Rectangle(rectangle_t rectangle) :
    rectangle(rectangle)
{}
double Rectangle::getArea() const
{
    return rectangle.width * rectangle.height;
}
rectangle_t Rectangle::getFrameRect() const
{
    return rectangle;
}
void Rectangle::move(point_t point)
{
    rectangle.pos = point;
}
void Rectangle::scale(double k)
{
    rectangle.width *= k;
    rectangle.height *= k;
}
