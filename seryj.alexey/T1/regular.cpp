#include "regular.hpp"
#include <cmath>
#include <iostream>
#define PI 3.1415926535
using namespace seryj;
Regular::Regular(point_t a, point_t b, point_t c)
{
  double side_ab = sqrt(pow(a.x - b.x, 2) + pow(a.y + b.y, 2));
  double side_ac = sqrt(pow(a.x - c.x, 2) + pow(a.y + c.y, 2));
  hypotenuse_ = fmax(side_ab, side_ac);
  cathetus_ = fmin(side_ab, side_ac);
  n_ = round(PI / cos(cathetus_ / hypotenuse_));
  std::cout << hypotenuse_ << " " << cathetus_ << " " << n_ << "\n";
  pos_ = a;
}
double Regular::getArea()
{
  return hypotenuse_ * hypotenuse_ * n_ * sin(PI / n_) / 2;
}
rectangle_t Regular::getFrameRect()
{
  return rectangle_t{hypotenuse_ * 2, hypotenuse_ * 2, pos_ };
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
