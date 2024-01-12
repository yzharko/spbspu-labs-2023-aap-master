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

sukacheva::rectangle_t sukacheva::Circle::getFrameRect() const {
  rectangle_t frameRect = { 2 * radius_, 2 * radius_, center_ };
  return frameRect;
}

double sukacheva::Circle::getArea() const {
  const double piNumber = 3.14;
  return (piNumber * radius_ * radius_);
}

void sukacheva::Circle::move(const double& x, const double& y) {
  center_.x += x;
  center_.y += y;
}

void sukacheva::Circle::move(const point_t& center) {
  center_ = center;
}

void sukacheva::Circle::newScale(const point_t& scaleCenter, const double& k) {
  double xSide = center_.x - scaleCenter.x;
  double ySide = center_.y - scaleCenter.y;
  center_.x = scaleCenter.x + xSide * k;
  center_.y = scaleCenter.y + ySide * k;
  radius_ = radius_ * k;
}

void sukacheva::Circle::scale(double k) {
  radius_ = radius_ * k;
}
