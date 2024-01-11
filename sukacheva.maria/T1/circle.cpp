#include "circle.hpp"
#include "base-types.hpp"
#include <iostream>

sukacheva::Circle::Circle(point_t center, double radius) :
  center_(center),
  radius_(radius)
{
  if (radius_ <= 0) {
    throw std::logic_error("wrong parameters\n");
  }
}

double sukacheva::Circle::getArea() {
  return (3.14 * radius_ * radius_);
}

void sukacheva::Circle::move(double x, double y) {
  center_.x_ += x;
  center_.y_ += y;
}

void sukacheva::Circle::move(point_t center) {
  center_ = center;
}

void sukacheva::Circle::scale(point_t scaleCenter, double k) {
  double xSide = center_.x_ - scaleCenter.x_;
  double ySide = center_.y_ - scaleCenter.y_;
  center_.x_ = scaleCenter.x_ + xSide * k;
  center_.y_ = scaleCenter.y_ + ySide * k;
  radius_ = radius_ * k;
}

sukacheva::rectangle_t sukacheva::Circle::getFrameRect() {
  return rectangle_t(2 * radius_, 2 * radius_, center_);
}
