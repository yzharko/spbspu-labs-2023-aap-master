#include "ring.hpp"
#include <cmath>
#include <cassert>

Ring::Ring(const point_t& center, float outerRadius, float innerRadius) :
    center_(center), outerRadius_(outerRadius), innerRadius_(innerRadius)
{
  assert(outerRadius > innerRadius && innerRadius > 0);
}

Ring* Ring::clone() const
{
  return new Ring(*this);
}

float Ring::getArea() const
{
  return M_PI * (outerRadius_ * outerRadius_ - innerRadius_ * innerRadius_);
}

rectangle_t Ring::getFrameRect() const
{
  return { outerRadius_ * 2, outerRadius_ * 2, center_ };
}

void Ring::move(const point_t& newPos)
{
  center_ = newPos;
}

void Ring::move(float dx, float dy)
{
  center_.x += dx;
  center_.y += dy;
}

void Ring::scale(float scaleFactor)
{
  assert(scaleFactor > 0);
  outerRadius_ *= scaleFactor;
  innerRadius_ *= scaleFactor;
}
