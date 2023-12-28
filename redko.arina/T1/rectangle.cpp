#include "rectangle.hpp"
#include <stdexcept>

redko::Rectangle::Rectangle(point_t firstPoint, point_t secondPoint) :
  firstPoint_(firstPoint), secondPoint_(secondPoint)
{}

double redko::Rectangle::getArea() const
{
  rectangle_t frame_ = getFrameRect();
  return (frame_.height_ * frame_.width_);
}

rectangle_t redko::Rectangle::getFrameRect() const
{
  return { secondPoint_.x_ - firstPoint_.x_, secondPoint_.y_ - firstPoint_.y_, { (firstPoint_.x_ + secondPoint_.x_) / 2, ((firstPoint_.y_ + secondPoint_.y_) / 2) } };
}

void redko::Rectangle::move(point_t dest)
{
  rectangle_t frame = getFrameRect();
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

void redko::Rectangle::scale(point_t pos, double coefficient)
{
  if (coefficient < 0)
  {
    throw std::invalid_argument("negative coefficient\n");
  }
  firstPoint_.x_ = (firstPoint_.x_ - pos.x_) * coefficient;
  firstPoint_.y_ = (firstPoint_.y_ - pos.y_) * coefficient;
  secondPoint_.x_ = (secondPoint_.x_ - pos.x_) * coefficient;
  secondPoint_.y_ = (secondPoint_.y_ - pos.y_) * coefficient;
}
