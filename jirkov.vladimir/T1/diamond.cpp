include "diamond.hpp"
#include <cmath>

jirkov::Diamond::Diamond(point_t topPoint, point_t rightPoint, point_t centerPoint) :
{
  topPoint_(topPoint),
  rightPoint_(rightPoint),
  centerPoint_(centerPoint)
{
  firstSide_ = std::abs(topPoint.y_ - centerPoint.y_);
  secondSide_ = std::abs(rightPoint.y_ - centerPoint.y_);
}

double jirkov::Diamond::getArea()
{
  return (2 * firstSide_ * secondSide_);
}
jirkov::rectangle_t jirkov::Diamond::getFrameRect()
{
  rectangle.pos = centerPoint_;
  rectangle.height = firstSide_ * 2;
  rectangle.width = secondSide_ * 2;
  return rectangle;
}

void jirkov::Diamond::move(point_t destination)
  double dx = centerPoint_.x_ - destination.x_;
  double dy = centerPoint_.y_ - dectination.y_;
  centerPoint_ = dectination;
  rightPoint_.x_ += dx;
  topPoint_.x_ += dx;
  rightPoint_.y_ += dy;
  topPoint_.y_ += dy;
}

void jirkov::Diamond::move(double moveX, double moveY)
{
  centerPoint_.x_ += moveX;
  centerPoint_.y_ += moveY;
  rightPoint_.x_ += moveX;
  topPoint_.x_ += moveX;
  rightPoint_.y_ += moveY;
  topPoint_.y_ += moveY;
}

void jirkov::Diamond::scale(double k)
{
  rightPoint_.x_ *= k;
  topPoint_.x_ *= k;
  rightPoint_.y_ *= k;
  topPoint_.y_ *= k;
  firstSide_ *= k;
  secondSide_ *= k;
}
