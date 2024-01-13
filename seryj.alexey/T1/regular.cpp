#include "regular.hpp"
#define _USE_MATH_DEFINES
#include <cmath>
#include <exception>
#include <iostream>
#include <iomanip>
using namespace seryj;
Regular::Regular(point_t a, point_t b, point_t c)
{
  p_b_ = b;
  p_c_ = c;
  double side_ab = sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
  double side_ac = sqrt(pow(a.x - c.x, 2) + pow(a.y - c.y, 2));
  double side_bc = sqrt(pow(b.x - c.x, 2) + pow(b.y - c.y, 2));
  hypotenuse_ = fmax(side_ab, side_ac);
  n_ = M_PI / cos(fmin(side_ab, side_ac) / hypotenuse_);
  pos_ = a;
  if (round(side_bc * 100) != round(hypotenuse_ * sin(M_PI / n_) * 100))
    throw std::logic_error("Cant build a regular\n");
  if (round(n_ * 1000) != round(round(n_)*1000))
    throw std::logic_error("Wrong regular coordinates\n");
}
double Regular::getArea()const
{
  return pow(hypotenuse_, 2) * n_ * sin(2 * M_PI / n_) / 2;
}
rectangle_t Regular::getFrameRect()const
{
  double rec_side = fmax(fmax(abs(p_b_.x - pos_.x), abs(p_c_.x - pos_.x)), fmax(abs(p_b_.y - pos_.y), abs(p_c_.y - pos_.y)));
  return rectangle_t{rec_side * 2, rec_side * 2, pos_ };
}
void Regular::move(point_t to_go)
{
  pos_ = to_go;
}
void Regular::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
}
void Regular::scale(double k)
{
  hypotenuse_ *= k;
  p_b_.x *= k;
  p_b_.y *= k;
  p_c_.x *= k;
  p_c_.y *= k;
}
