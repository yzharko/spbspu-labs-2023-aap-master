#include "regular.hpp"
#include <cmath>
Regular::Regular(point_t a, point_t b, point_t c)
{
  const double pi = 3.14159265358979323846;
  double side_ab = sqrt(pow(a.x - b.x, 2) + pow(a.y + b.y, 2));
  double side_ac = sqrt(pow(a.x - c.x, 2) + pow(a.y + c.y, 2));
  hypotenuse_ = fmax(side_ab, side_ac);
  cathetus_ = fmin(side_ab, side_ac);
  double angle = cos(cathetus_ / hypotenuse_) * 180 / pi;
  n_ = round(360 / (180 - angle * 2));
  pos_ = a;
}
double Regular::getArea()
{
  return cathetus_ * hypotenuse_ * n_ * sin(180 / n_);
}
rectangle_t Regular::getFrameRect()
{
  return rectangle_t{ hypotenuse_ * 2, hypotenuse_ * 2, pos_ };
}
void Regular::move(point_t t)
{
  pos_ = t;
}
void Regular::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
}
void Regular::scale(double k)
{
  hypotenuse_ *= k;
  cathetus_ *= k;
}
