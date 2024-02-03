#include "rectangle.hpp"

Rectangle::Rectangle(double x1, double y1, double x2, double y2) :
  pointLl{ x1, y1 },
  pointUr{ x2, y2 }
{
  width_ = abs(pointUr.x) + abs(pointLl.x);
  height_ = abs(pointUr.y) + abs(pointLl.y);
  this->pos_ = { double(abs(pointUr.x) - abs(pointLl.x)) / 2, double(abs(pointUr.y) - abs(pointLl.y)) / 2 };
}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  return { width_, height_, pos_ };
}

void Rectangle::move(const double& dx, const double& dy)
{
  pointLl.x += dx;
  pointLl.y += dy;
  pointUr.x += dx;
  pointUr.y += dy;
  pos_.x += dx;
  pos_.y += dy;
}

void Rectangle::move(const point_t& new_center)
{
  double dx = pos_.x - new_center.x;
  double dy = pos_.y - new_center.y;
  pointLl.x += dx;
  pointLl.y += dy;
  pointUr.x += dx;
  pointUr.y += dy;
  pos_.x += dx;
  pos_.y += dy;
  pos_ = new_center;
}

void Rectangle::scale(double k)
{
  width_ *= k;
  height_ *= k;
}
