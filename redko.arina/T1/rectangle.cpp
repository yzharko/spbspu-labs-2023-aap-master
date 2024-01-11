#include "rectangle.hpp"

redko::Rectangle::Rectangle(redko::point_t firstPoint, redko::point_t secondPoint) :
  firstPoint_(firstPoint), secondPoint_(secondPoint)
{}

double redko::Rectangle::getArea() const
{
  rectangle_t frame = getFrameRect();
  return (frame.height_ * frame.width_);
}

redko::rectangle_t redko::Rectangle::getFrameRect() const
{
  double width = secondPoint_.x_ - firstPoint_.x_;
  double height = secondPoint_.y_ - firstPoint_.y_;
  double x = firstPoint_.x_ + ((secondPoint_.x_ - firstPoint_.x_) / 2.0);
  double y = firstPoint_.y_ + ((secondPoint_.y_ - firstPoint_.y_) / 2.0);
  return { width, height, { x, y } };
}

void redko::Rectangle::move(redko::point_t dest)
{
  redko::rectangle_t frame = getFrameRect();
  double xDist = dest.x_ - frame.pos_.x_;
  double yDist = dest.y_ - frame.pos_.y_;
  firstPoint_.x_ += xDist;
  firstPoint_.y_ += yDist;
  secondPoint_.x_ += xDist;
  secondPoint_.y_ += yDist;
}

void redko::Rectangle::move(double xDist, double yDist)
{
  firstPoint_.x_ += xDist;
  firstPoint_.y_ += yDist;
  secondPoint_.x_ += xDist;
  secondPoint_.y_ += yDist;
}

void redko::Rectangle::scale(double coefficient)
{
  rectangle_t frame = getFrameRect();
  firstPoint_.x_ = frame.pos_.x_ + (firstPoint_.x_ - frame.pos_.x_) * coefficient;
  firstPoint_.y_ = frame.pos_.y_ + (firstPoint_.y_ - frame.pos_.y_) * coefficient;
  secondPoint_.x_ = frame.pos_.x_ + (secondPoint_.x_ - frame.pos_.x_) * coefficient;
  secondPoint_.y_ = frame.pos_.y_ + (secondPoint_.y_ - frame.pos_.y_) * coefficient;
}
