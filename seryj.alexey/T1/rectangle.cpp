#include "rectangle.hpp"
#include <cmath>
#include <iostream>
#include <exception>
using namespace seryj;
Rectangle::Rectangle(point_t lp, point_t rp)
{
  if (lp.x > rp.x || lp.y > rp.y)
    throw std::logic_error("Rectangle coordinats are wrong\n");
  left_point_ = lp;
  right_point_ = rp;
  pos_.x = (left_point_.x + right_point_.x) / 2;
  pos_.y = (left_point_.y + right_point_.y) / 2;
  width_ = abs(left_point_.x - right_point_.x);
  height_ = abs(left_point_.y - right_point_.y);
}
double Rectangle::getArea()
{
  return height_ * width_;
}
rectangle_t Rectangle::getFrameRect()
{
  return rectangle_t{ width_, height_, pos_ };
}
void Rectangle::move(point_t p)
{
  pos_ = p;
  left_point_.x = p.x + left_point_.x;
  right_point_.x = p.x + right_point_.x;
}
void Rectangle::move(double x, double y)
{
  pos_.x += x;
  pos_.y += y;
  left_point_.x += x;
  left_point_.y += y;
  right_point_.x += x;
  right_point_.y += y;
}
void Rectangle::scale(double k)
{
  k = abs(k);
  height_ *= k;
  width_ *= k;
  left_point_.x -= pos_.x * (k - 1);
  left_point_.y -= pos_.y * (k - 1);
  right_point_.x += pos_.x * (k - 1);
  right_point_.y += pos_.y * (k - 1);
}
