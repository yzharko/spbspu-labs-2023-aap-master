#include "rectangle.hpp"
#include <cmath>

using namespace mihalchenko;

Rectangle::Rectangle(point_t pos1, point_t pos2) : pos1_(pos1), pos2_(pos2)
{
  rectangle_.width_ = fabs(pos2_.x_ - pos1_.x_);
  rectangle_.height_ = fabs(pos2_.y_ - pos1_.y_);
  rectangle_.pos_.x_ = (pos2_.x_ + pos1_.x_) / 2;
  rectangle_.pos_.y_ = (pos2_.y_ + pos1_.y_) / 2;

  pos1_ = pos1;
  pos2_ = pos2;
  pointCentre_.x_ = (pos2_.x_ + pos1_.x_) / 2;
  pointCentre_.y_ = (pos2_.y_ + pos1_.y_) / 2;
}

double mihalchenko::Rectangle::getArea() const
{
  return {rectangle_.width_ * rectangle_.height_};
}

rectangle_t mihalchenko::Rectangle::getFrameRect() const
{
  return {fabs(pos2_.x_ - pos1_.x_), fabs(pos2_.y_ - pos1_.y_), {(pos2_.x_ + pos1_.x_) / 2, (pos2_.y_ + pos1_.y_) / 2}};
}

void Rectangle::move(const point_t &point)
{
  pos1_ = {pos1_.x_ + (point.x_ - rectangle_.pos_.x_), pos1_.y_ + (point.y_ - rectangle_.pos_.y_)};
  pos2_ = {pos2_.x_ + (point.x_ - rectangle_.pos_.x_), pos2_.y_ + (point.y_ - rectangle_.pos_.y_)};
  rectangle_.pos_ = point;
}

void Rectangle::move(const double deltaX, const double deltaY)
{
  pos1_ = {pos1_.x_ + deltaX, pos1_.y_ + deltaY};
  pos2_ = {pos2_.x_ + deltaX, pos2_.y_ + deltaY};
  rectangle_.pos_ = {rectangle_.pos_.x_ + deltaX, rectangle_.pos_.y_ + deltaY};
}

void Rectangle::scale(double scaleKoef)
{
  double deltaX = (1 - scaleKoef) * rectangle_.width_ / 2;
  double deltaY = (1 - scaleKoef) * rectangle_.height_ / 2;
  pos1_ = {pos1_.x_ + deltaX, pos1_.y_ + deltaY};
  deltaX = (scaleKoef - 1) * rectangle_.width_ / 2;
  deltaY = (scaleKoef - 1) * rectangle_.height_ / 2;
  pos2_ = {pos2_.x_ + deltaX, pos2_.y_ + deltaY};
  rectangle_.height_ = scaleKoef * rectangle_.height_;
  rectangle_.width_ = scaleKoef * rectangle_.width_;
}
