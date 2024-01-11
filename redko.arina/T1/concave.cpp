#include "concave.hpp"
#include <algorithm>

redko::Concave::Concave(redko::point_t firstPoint, redko::point_t secondPoint, redko::point_t thirdPoint, redko::point_t fourthPoint) :
  firstPoint_(firstPoint), secondPoint_(secondPoint), thirdPoint_(thirdPoint), fourthPoint_(fourthPoint)
{}

double redko::Concave::getArea() const
{
  double bigTriangle = firstPoint_.x_ * (secondPoint_.y_ - thirdPoint_.y_) + secondPoint_.x_ * (thirdPoint_.y_ - firstPoint_.y_);
  bigTriangle = std::abs((bigTriangle + thirdPoint_.x_ * (firstPoint_.y_ - secondPoint_.y_)) / 2.0);
  double smallTriangle = fourthPoint_.x_ * (secondPoint_.y_ - thirdPoint_.y_) + secondPoint_.x_ * (thirdPoint_.y_ - fourthPoint_.y_);
  smallTriangle = std::abs((smallTriangle + thirdPoint_.x_ * (fourthPoint_.y_ - secondPoint_.y_)) / 2.0);
  return bigTriangle - smallTriangle;
}

redko::rectangle_t redko::Concave::getFrameRect() const
{
  double maxX = std::max(std::max(firstPoint_.x_, secondPoint_.x_), thirdPoint_.x_);
  double minX = std::min(std::min(firstPoint_.x_, secondPoint_.x_), thirdPoint_.x_);
  double width = maxX - minX;
  double maxY = std::max(std::max(firstPoint_.y_, secondPoint_.y_), thirdPoint_.y_);
  double minY = std::min(std::min(firstPoint_.y_, secondPoint_.y_), thirdPoint_.y_);
  double height = maxY - minY;
  double x = minX + width / 2.0;
  double y = minY + height / 2.0;
  return { width, height, { x, y } };
}

void redko::Concave::move(redko::point_t dest)
{
  double xDist = dest.x_ - fourthPoint_.x_;
  double yDist = dest.y_ - fourthPoint_.y_;
  firstPoint_.x_ += xDist;
  firstPoint_.y_ += yDist;
  secondPoint_.x_ += xDist;
  secondPoint_.y_ += yDist;
  thirdPoint_.x_ += xDist;
  thirdPoint_.y_ += yDist;
  fourthPoint_.x_ += xDist;
  fourthPoint_.y_ += yDist;
}

void redko::Concave::move(double xDist, double yDist)
{
  firstPoint_.x_ += xDist;
  firstPoint_.y_ += yDist;
  secondPoint_.x_ += xDist;
  secondPoint_.y_ += yDist;
  thirdPoint_.x_ += xDist;
  thirdPoint_.y_ += yDist;
  fourthPoint_.x_ += xDist;
  fourthPoint_.y_ += yDist;
}

void redko::Concave::scale(double coefficient)
{
  firstPoint_.x_ = fourthPoint_.x_ + (firstPoint_.x_ - fourthPoint_.x_) * coefficient;
  firstPoint_.y_ = fourthPoint_.y_ + (firstPoint_.y_ - fourthPoint_.y_) * coefficient;
  secondPoint_.x_ = fourthPoint_.x_ + (secondPoint_.x_ - fourthPoint_.x_) * coefficient;
  secondPoint_.y_ = fourthPoint_.y_ + (secondPoint_.y_ - fourthPoint_.y_) * coefficient;
  thirdPoint_.x_ = fourthPoint_.x_ + (thirdPoint_.x_ - fourthPoint_.x_) * coefficient;
  thirdPoint_.y_ = fourthPoint_.y_ + (thirdPoint_.y_ - fourthPoint_.y_) * coefficient;
}
