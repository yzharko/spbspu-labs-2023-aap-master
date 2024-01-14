#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>
using namespace seryj;
Rectangle::Rectangle(point_t lp, point_t rp)
{
  if (lp.x > rp.x || lp.y > rp.y)
  {
    throw std::logic_error("Rectangle coordinats are wrong\n");
  }
  left_point_ = lp;
  right_point_ = rp;
  pos_.x = (left_point_.x + right_point_.x) / 2;
  pos_.y = (left_point_.y + right_point_.y) / 2;
  width_ = abs(left_point_.x - right_point_.x);
  height_ = abs(left_point_.y - right_point_.y);
}
double Rectangle::getArea()const
{
  return height_ * width_;
}
rectangle_t Rectangle::getFrameRect()const
{
  return rectangle_t{ width_, height_, pos_ };
}
void Rectangle::move(const point_t& dest)
{
  double shift_x = dest.x - pos_.x;
  double shift_y = dest.y - pos_.y;
  pos_ = dest;
  left_point_ = { left_point_.x + shift_x, left_point_.y + shift_y };
  right_point_ = { right_point_.x + shift_x, right_point_.y + shift_y };
}
void Rectangle::move(const double& x, const double& y)
{
  pos_ = { pos_.x + x, pos_.y + y };
  left_point_ = { left_point_.x + x, left_point_.y + y };
  right_point_ = { right_point_.x + x, right_point_.y + y };
}
void Rectangle::scale(double k)
{
  height_ *= k;
  width_ *= k;
  left_point_.x *= k;
  left_point_.y *= k;
  right_point_.x *= k;
  right_point_.y *= k;
}
