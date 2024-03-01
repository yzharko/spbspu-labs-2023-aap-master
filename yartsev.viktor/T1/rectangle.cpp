#include "rectangle.hpp"
#include <cmath>
#include "base-types.hpp"

yartsev::Rectangle::Rectangle(const point_t & bottomLeftPoint, const point_t & topRightPoint)
{
  rectangle_.height_ = abs(bottomLeftPoint.y_ - topRightPoint.y_);
  rectangle_.width_ = abs(bottomLeftPoint.x_ - topRightPoint.x_);
  rectangle_.pos_ = {(bottomLeftPoint.x_ + topRightPoint.x_) / 2, (bottomLeftPoint.y_ + topRightPoint.y_) / 2};
};

double yartsev::Rectangle::getArea() const
{
  return rectangle_.width_ * rectangle_.height_;
}

yartsev::rectangle_t yartsev::Rectangle::getFrameRect()
{
  return rectangle_;
}

void yartsev::Rectangle::move(const point_t & to) 
{
  rectangle_.pos_ = to;
}

void yartsev::Rectangle::move(const double & dx, const double & dy) 
{
  rectangle_.pos_.x_ += dx;
  rectangle_.pos_.y_ += dy;
}

void yartsev::Rectangle::scale(const double & scaling)
{
  rectangle_.height_ *= scaling;
  rectangle_.width_ *= scaling;
}

void yartsev::Rectangle::pointScale(point_t to, double scaling)
{
  rectangle_.width_ *= scaling;
  rectangle_.height_ *= scaling;
  rectangle_.pos_.x_ = to.x_ + (rectangle_.pos_.x_ - to.x_) * scaling;
  rectangle_.pos_.y_ = to.y_ + (rectangle_.pos_.y_ - to.y_) * scaling;
}

