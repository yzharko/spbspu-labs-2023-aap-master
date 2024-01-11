#include "parallelogram.hpp"
#include <cmath>

redko::Parallelogram::Parallelogram(point_t firstPoint, point_t secondPoint, point_t thirdPoint) :
  firstPoint_(firstPoint), secondPoint_(secondPoint), thirdPoint_(thirdPoint)
{}

double redko::Parallelogram::getArea() const
{
  rectangle_t frame = getFrameRect();
  if (firstPoint_.y_ == secondPoint_.y_)
  {
    return (abs(firstPoint_.x_ - secondPoint_.x_) * frame.height_);
  }
  else
  {
    return (abs(firstPoint_.x_ - thirdPoint_.x_) * frame.height_);
  }
}

rectangle_t redko::Parallelogram::getFrameRect() const
{
  double width = abs(firstPoint_.x_ - secondPoint_.x_) + abs(firstPoint_.x_ - thirdPoint_.x_);

  double height = 0;
  if (firstPoint_.y_ == secondPoint_.y_)
  {
    height = abs(firstPoint_.y_ - thirdPoint_.y_);
  }
  else
  {
    height = abs(firstPoint_.y_ - secondPoint_.y_);
  }

  double x = 0;
  if (firstPoint_.x_ <= secondPoint_.x_ && firstPoint_.x_ <= thirdPoint_.x_)
  {
    x = firstPoint_.x_ + (width / 2);
  }
  else if (secondPoint_.x_ <= firstPoint_.x_ && secondPoint_.x_ <= thirdPoint_.x_)
  {
    x = secondPoint_.x_ + (width / 2);
  }
  else
  {
    x = thirdPoint_.x_ + (width / 2);
  }

  double y = 0;
  if (firstPoint_.y_ > secondPoint_.y_ || firstPoint_.y_ > thirdPoint_.y_)
  {
    y = firstPoint_.y_ - (height / 2);
  }
  else
  {
    y = firstPoint_.y_ + (height / 2);
  }

  return { width, height, { x, y } };
}

void redko::Parallelogram::move(point_t dest)
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
}

void redko::Parallelogram::move(double xDist, double yDist)
{
  firstPoint_.x_ += xDist;
  firstPoint_.y_ += yDist;
  secondPoint_.x_ += xDist;
  secondPoint_.y_ += yDist;
  thirdPoint_.x_ += xDist;
  thirdPoint_.y_ += yDist;
}

void redko::Parallelogram::scale(point_t pos, double coefficient)
{
  firstPoint_.x_ = (firstPoint_.x_ - pos.x_) * coefficient;
  firstPoint_.y_ = (firstPoint_.y_ - pos.y_) * coefficient;
  secondPoint_.x_ = (secondPoint_.x_ - pos.x_) * coefficient;
  secondPoint_.y_ = (secondPoint_.y_ - pos.y_) * coefficient;
  thirdPoint_.x_ = (thirdPoint_.x_ - pos.x_) * coefficient;
  thirdPoint_.y_ = (thirdPoint_.y_ - pos.y_) * coefficient;
}
