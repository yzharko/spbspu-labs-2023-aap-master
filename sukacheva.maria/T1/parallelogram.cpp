#include "parallelogram.hpp"
#include "base-types.hpp"
#include <iostream>
#include <cmath>
#include "equalityOfPoints.hpp"

sukacheva::Parallelogram::Parallelogram(point_t A, point_t B, point_t C):
  A_(A),
  B_(B),
  C_(C)
{

  if ((sukacheva::arePointsEqual(A_, B_) && sukacheva::arePointsEqual(C_, B_))
    || !(A_.y == B_.y || B_.y == C_.y))
  {
    throw std::logic_error("wrong parameters\n");
  }
}

double sukacheva::Parallelogram::getArea() const
{
  double height = std::abs(std::max(std::max(A_.y, B_.y), C_.y) -
    std::min(std::min(A_.y, B_.y), C_.y));
  double lenght = A_.y == B_.y ? std::abs(A_.x - B_.x) : B_.y == C_.y ?
    std::abs(C_.x - B_.x) : std::abs(A_.x - C_.x);
  return height * lenght;
}

sukacheva::rectangle_t sukacheva::Parallelogram::getFrameRect() const
{
  double height = std::abs(std::max(std::max(A_.y, B_.y), C_.y)
    - std::min(std::min(A_.y, B_.y), C_.y));
  double width = std::abs(std::max(std::max(A_.x, B_.x), C_.x) -
    std::min(std::min(A_.x, B_.x), C_.x));
  point_t cos = { ((std::max(std::max(A_.x, B_.x), C_.x) + std::min(std::min(A_.x, B_.x), C_.x)) * 0.5),
    ((std::max(std::max(A_.y, B_.y), C_.y) + std::min(std::min(A_.y, B_.y), C_.y)) * 0.5) };
  rectangle_t frameRect = { width, height, cos };
  return frameRect;
}

void sukacheva::Parallelogram::move(const double& x, const double& y) {
  A_ = { A_.x + x, A_.y + y };
  B_ = { B_.x + x, B_.y + y };
  C_ = { C_.x + x, C_.y + y };
}

void sukacheva::Parallelogram::move(const point_t& center) {
  double newX = center.x;
  double newY = center.y;
  double oldX = (A_.x + B_.x) / 2;
  double oldY = (A_.y + C_.y) / 2;
  double dX = newX - oldX;
  double dY = newY - oldY;
  move(dX, dY);
}

void sukacheva::Parallelogram::scaling(double k)
{
  double centerX = (std::max(std::max(A_.x, B_.x), C_.x) +
    std::min(std::min(A_.x, B_.x), C_.x)) * 0.5;
  double centerY = (std::max(std::max(A_.y, B_.y), C_.y)
    + std::min(std::min(A_.y, B_.y), C_.y)) * 0.5;
  A_ = { (centerX + (A_.x - centerX) * k), (centerY + (A_.y - centerY) * k) };
  B_ = { (centerX + (B_.x - centerX) * k), (centerY + (B_.y - centerY) * k) };
  C_ = { (centerX + (C_.x - centerX) * k), (centerY + (C_.y - centerY) * k) };
}
