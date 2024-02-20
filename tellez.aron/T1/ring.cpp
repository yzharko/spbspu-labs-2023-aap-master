#include "ring.hpp"
#include <stdexcept>

using namespace tellez;

Ring::Ring(point_t center, double outerRadius, double innerRadius) :
  center_(center),
  outerRadius_(outerRadius),
  innerRadius_(innerRadius)
{
  if (outerRadius <= 0.0 || innerRadius <= 0.0 || outerRadius <= innerRadius)
  {
    throw std::logic_error("bad ring size");
  }
}

double Ring::getArea() const
{
  return 3.14 * (outerRadius_ * outerRadius_ - innerRadius_ * innerRadius_);
}

rectangle_t Ring::getFrameRect() const
{
  return {center_, 2.0 * outerRadius_, 2.0 * outerRadius_};
}

void Ring::move(double dx, double dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Ring::move(point_t position)
{
  center_ = position;
}

Shape* Ring::clone() const
{
  return new Ring(center_, outerRadius_, innerRadius_);
}

void Ring::scale(double ds)
{
  outerRadius_ *= ds;
  innerRadius_ *= ds;
}
