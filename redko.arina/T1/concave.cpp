#include "concave.hpp"
#include <algorithm>

redko::Concave::Concave(point_t firstPoint, point_t secondPoint, point_t thirdPoint, point_t fourthPoint) :
  firstPoint_(firstPoint), secondPoint_(secondPoint), thirdPoint_(thirdPoint), fourthPoint_(fourthPoint)
{}

double redko::Concave::getArea() const
{
  double bigTriangle = abs((firstPoint_.x_ * (secondPoint_.y_ - thirdPoint_.y_) + \
    secondPoint_.x_ * (thirdPoint_.y_ - firstPoint_.y_) + thirdPoint_.x_ * (firstPoint_.y_ - secondPoint_.y_)) / 2);
  double smallTriangle = abs((fourthPoint_.x_ * (secondPoint_.y_ - thirdPoint_.y_) + \
    secondPoint_.x_ * (thirdPoint_.y_ - fourthPoint_.y_) + thirdPoint_.x_ * (fourthPoint_.y_ - secondPoint_.y_)) / 2);
  return bigTriangle - smallTriangle;
}

rectangle_t redko::Concave::getFrameRect() const
{
  double maxX = std::max(std::max(firstPoint_.x_, secondPoint_.x_), thirdPoint_.x_);
  double minX = std::min(std::min(firstPoint_.x_, secondPoint_.x_), thirdPoint_.x_);
  double width = maxX - minX;
  double maxY = std::max(std::max(firstPoint_.y_, secondPoint_.y_), thirdPoint_.y_);
  double minY = std::min(std::min(firstPoint_.y_, secondPoint_.y_), thirdPoint_.y_);
  double height = maxY - minY;
  return { width, height, fourthPoint_ };
}

void redko::Concave::move(point_t dest)
{
  rectangle_t frame = getFrameRect();
  double xDist = dest.x_ - frame.pos_.x_;
  double yDist = dest.y_ - frame.pos_.y_;
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

void redko::Concave::scale(point_t pos, double coefficient)
{
  firstPoint_.x_ = (firstPoint_.x_ - pos.x_) * coefficient;
  firstPoint_.y_ = (firstPoint_.y_ - pos.y_) * coefficient;
  secondPoint_.x_ = (secondPoint_.x_ - pos.x_) * coefficient;
  secondPoint_.y_ = (secondPoint_.y_ - pos.y_) * coefficient;
  thirdPoint_.x_ = (thirdPoint_.x_ - pos.x_) * coefficient;
  thirdPoint_.y_ = (thirdPoint_.y_ - pos.y_) * coefficient;
  fourthPoint_.x_ = (fourthPoint_.x_ - pos.x_) * coefficient;
  fourthPoint_.y_ = (fourthPoint_.y_ - pos.y_) * coefficient;
}
