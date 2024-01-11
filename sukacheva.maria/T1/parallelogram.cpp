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


void sukacheva::Parallelogram::scale(point_t center, double k)
{
  double xSideA = A_.x_ - center.x_;
  double ySideA = A_.y_ - center.y_;
  double xSideB = B_.x_ - center.x_;
  double ySideB = B_.y_ - center.y_;
  double xSideC = C_.x_ - center.x_;
  double ySideC = C_.y_ - center.y_;

  A_.x_ = center.x_ + xSideA * k;
  A_.y_ = center.y_ + ySideA * k;
  B_.x_ = center.x_ + xSideB * k;
  B_.y_ = center.y_ + ySideB * k;
  C_.x_ = center.x_ + xSideC * k;
  C_.y_ = center.y_ + ySideC * k;
}

sukacheva::rectangle_t sukacheva::Parallelogram::getFrameRect()
{
  double height = std::abs(A_.y_ - C_.y_);
  double width = std::abs(B_.x_ - C_.y_);
  point_t cos(((A_.x_ + B_.x_) / 2), ((A_.y_ + C_.y_) / 2));
  return rectangle_t(width, height, cos);
}
