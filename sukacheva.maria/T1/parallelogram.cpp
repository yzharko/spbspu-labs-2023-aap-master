#include "parallelogram.hpp"
#include "base-types.hpp"
#include <iostream>

sukacheva::Parallelogram::Parallelogram(point_t A, point_t B, point_t C) :
  A_(A),
  B_(B),
  C_(C)
{}

double sukacheva::Parallelogram::getArea()
{
  double height = std::abs(A_.y_ - C_.y_);
  double lenght = std::abs(B_.x_ - C_.y_);
  return height * lenght;
}

void sukacheva::Parallelogram::move(double x, double y) {
  A_ = point_t(A_.x_ + x, A_.y_ + y);
  B_ = point_t(B_.x_ + x, B_.y_ + y);
  C_ = point_t(C_.x_ + x, C_.y_ + y);
}

void sukacheva::Parallelogram::move(point_t center) {
  double newX = center.x_;
  double newY = center.y_;
  double oldX = (A_.x_ + B_.x_) / 2;
  double oldY = (A_.y_ + C_.y_) / 2;
  double dX = newX - oldX;
  double dY = newY - oldY;
  move(dX, dY);
}


void sukacheva::Parallelogram::scale(double k)
{
  double centerX = (A_.x_ + B_.x_) / 2;
  double centerY = (A_.y_ + C_.y_) / 2;

  A_ = point_t((centerX + (A_.x_ - centerX) * k), (centerY + (A_.y_ - centerY) * k));
  B_ = point_t((centerX + (B_.x_ - centerX) * k), (centerY + (B_.y_ - centerY) * k));
  C_ = point_t((centerX + (C_.x_ - centerX) * k), (centerY + (C_.y_ - centerY) * k));
}

sukacheva::rectangle_t sukacheva::Parallelogram::getFrameRect()
{
  double height = std::abs(A_.y_ - C_.y_);
  double width = std::abs(B_.x_ - C_.y_);
  point_t cos(((A_.x_ + B_.x_) / 2), ((A_.y_ + C_.y_) / 2));
  return rectangle_t(width, height, cos);
}
