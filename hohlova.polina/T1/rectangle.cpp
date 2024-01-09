#include "rectangle.hpp"
double hohlova::Rectangle::getArea()
{
  return height_ * width_;
}
rectangle_t hohlova::Rectangle::getFrameRect()
{
  return rectangle_t{ width_, height_, pos_ };
}
void hohlova::Rectangle::move(point_t p)
{
  pos_ = p;
  left_point_.x_ = p.x_ + left_point_.x_;
  right_point_.x_ = p.x_ + right_point_.x_;
}
void hohlova::Rectangle::move(double x, double y)
{
  pos_.x_ += x;
  pos_.y_ += y;
  left_point_.x_ += x;
  left_point_.y_ += y;
  right_point_.x_ += x;
  right_point_.y_+= y;
}
void hohlova::Rectangle::scale(double k)
{
  k = abs(k);
  height_ *= k;
  width_ *= k;
  left_point_.x_ -= pos_.x_ * (k - 1);
  left_point_.y_ -= pos_.y_ * (k - 1);
  right_point_.x_ += pos_.x_ * (k - 1);
  right_point_.y_ += pos_.y_ * (k - 1);
}
