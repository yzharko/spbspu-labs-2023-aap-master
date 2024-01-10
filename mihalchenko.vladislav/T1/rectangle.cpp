#include "rectangle.hpp"
#include <iostream>
#include <cmath>

mihalchenko::Rectangle::Rectangle(const point_t &pos1, const point_t &pos2) : pos_((pos2.x_ - pos1.x_) / 2, (pos2.y_ - pos1.y_) / 2),
                                                                              width_(std::abs(pos2.x_ - pos1.x_)),
                                                                              height_(std::abs(pos2.y_ - pos1.y_))
{
  if (width_ < 0.0 || height_ < 0.0)
  {
    throw std::invalid_argument("Invalid width or height");
  }
  else
  {
    std::cout << pos_.x_ << "; " << width_ << "; " << height_ << std::endl;
  }
}

double mihalchenko::Rectangle::getArea() const
{
  return {width_ * height_};
}

rectangle_t mihalchenko::Rectangle::getFrameRect() const
{
  return rectangle_t(pos_, width_, height_);
}

void mihalchenko::Rectangle::move(const point_t &point)
{
  pos_ = point;
}

void mihalchenko::Rectangle::move(const double dx, const double dy)
{
  pos_.x_ += dx;
  pos_.y_ += dy;
}

double mihalchenko::Rectangle::scale(double koef)
{
  width_ = width_ * koef;
  height_ = height_ * koef;
  return {width_ * height_};
}
