#include "regular.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <exception>
#include <iostream>
#include <iomanip>
using namespace seryj;
Regular::Regular(point_t a, point_t b, point_t c)
{
  double side_ab = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
  double side_ac = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
  side_ = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
  cathetus_ = fmin(side_ab, side_ac);
  hypotenuse_ = fmax(side_ab, side_ac);;
  n_ = M_PI / cos(cathetus_ / hypotenuse_);
  pos_ = a;
  if (round(side_ * 100) != round(hypotenuse_ * sin(M_PI / n_) * 100))
    throw std::logic_error("Cant build a regular\n");
  if (round(pow(hypotenuse_,2) * 1000) != round((pow(cathetus_, 2) + pow(side_, 2))*1000))
    throw std::logic_error("Wrong regular coordinates\n");
}
double Regular::getArea()const
{
  return pow(hypotenuse_, 2) * n_ * sin(2 * M_PI / n_) / 2;
}
rectangle_t Regular::getFrameRect()const
{
  double rec_side = 0;
  if (n_ == 4)
    rec_side = cathetus_;
  else rec_side = hypotenuse_;
  return rectangle_t{rec_side * 2, rec_side * 2, pos_ };
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
  side_ *= k;
}
