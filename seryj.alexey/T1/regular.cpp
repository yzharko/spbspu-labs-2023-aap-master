#include "regular.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <exception>
#include <iostream>
#include <iomanip>
using namespace seryj;
Regular::Regular(point_t a, point_t b, point_t c)
{
  point_b_ = b;
  point_c_ = c;
  pos_ = a;
  double side_ab = sqrt(pow(pos_.x - point_b_.x, 2) + pow(pos_.y - point_b_.y, 2));
  double side_ac = sqrt(pow(pos_.x - point_c_.x, 2) + pow(pos_.y - point_c_.y, 2));
  double side_bc = sqrt(pow(point_b_.x - point_c_.x, 2) + pow(point_b_.y - point_c_.y, 2));
  hypotenuse_ = fmax(side_ab, side_ac);
  n_ = M_PI / cos(fmin(side_ab, side_ac) / hypotenuse_);
  if (round(side_bc * 100) != round(hypotenuse_ * sin(M_PI / n_) * 100))
    throw std::logic_error("Cant build a regular\n");
}
double Regular::getArea()const
{
  return pow(hypotenuse_, 2) * n_ * sin(2 * M_PI / n_) / 2;
}
rectangle_t Regular::getFrameRect()const
{
  double rec_side = fmax(fmax(abs(point_b_.x - pos_.x), abs(point_c_.x - pos_.x)), fmax(abs(point_b_.y - pos_.y), abs(point_c_.y - pos_.y)));
  return rectangle_t{rec_side * 2, rec_side * 2, pos_ };
}
void Regular::move(const point_t& dest)
{
  pos_ = dest;
}
void Regular::move(const double& x,const double& y)
{
  pos_ = { pos_.x + x, pos_.y + y };
}
void Regular::scale(double k)
{
  hypotenuse_ *= k;
  point_b_.x *= k;
  point_b_.y *= k;
  point_c_.x *= k;
  point_c_.y *= k;
}
