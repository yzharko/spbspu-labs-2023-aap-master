#include "circle.hpp"
#include "base-types.hpp"

#define PI 3.14159265358979323856

smolyakov::Circle::Circle(point_t center, double radius)
{
  center_ = center;
  radius_ = radius;
}

double smolyakov::Circle::getArea() const
{
  return PI * radius_ * radius_;
}

smolyakov::rectangle_t smolyakov::Circle::getFrameRect() const
{
  double doubleRadius = 2 * radius_;
  return rectangle_t{center_, doubleRadius, doubleRadius};
}

void smolyakov::Circle::moveTo(point_t shift)
{
  center_ = point_t{shift.x, shift.y};
}

void smolyakov::Circle::moveBy(point_t shift)
{
  center_ = point_t{center_.x + shift.x, center_.y + shift.y};
}

void smolyakov::Circle::scale(double factor)
{
  radius_ *= factor;
}
