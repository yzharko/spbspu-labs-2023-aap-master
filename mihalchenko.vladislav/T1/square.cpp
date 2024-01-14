#include "square.hpp"
#include <cmath>

using namespace mihalchenko;

Square::Square(point_t pos1, double width) : pos1_(pos1), width_(width)
{
  rectangle_.width_ = width;
  rectangle_.height_ = width;
  rectangle_.pos_.x_ = pos1.x_ + width / 2;
  rectangle_.pos_.y_ = pos1.y_ + width / 2;

  pos2_.x_ = pos1_.x_ + width;
  pos2_.y_ = pos1_.y_ + width;
  pointCentre_.x_ = pos1.x_ + width / 2;
  pointCentre_.y_ = pos1.y_ + width / 2;
}

double mihalchenko::Square::getArea() const
{
  return {rectangle_.width_ * rectangle_.width_};
}

rectangle_t mihalchenko::Square::getFrameRect() const
{
  return {width_, width_, {pos1_.x_ + width_ / 2, pos1_.y_ + width_ / 2}};
}

void Square::move(const point_t &point)
{
  pos1_ = {pos1_.x_ + (point.x_ - rectangle_.pos_.x_), pos1_.y_ + (point.y_ - rectangle_.pos_.y_)};
  rectangle_.pos_ = point;
}

void Square::move(const double deltaX, const double deltaY)
{
  pos1_ = {pos1_.x_ + deltaX, pos1_.y_ + deltaY};
  rectangle_.pos_ = {rectangle_.pos_.x_ + deltaX, rectangle_.pos_.y_ + deltaY};
}

void Square::scale(double scaleKoef)
{
  pos1_ = {(pos1_.x_ + width_ / 2 * (1 - scaleKoef)), (pos1_.y_ + width_ / 2 * (1 - scaleKoef))};
  width_ = width_ * scaleKoef;
  rectangle_.height_ = scaleKoef * rectangle_.height_;
  rectangle_.width_ = scaleKoef * rectangle_.width_;
}
