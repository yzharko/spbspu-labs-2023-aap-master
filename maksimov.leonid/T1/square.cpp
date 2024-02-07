#include "square.hpp"


Square::Square(double x, double y, double width) :
  pointLl{ x, y },
  pointUr{ x + width, x + width },
  width_{width},
  height_{width}
{
  this->pos_ = { width_ / 2, height_ / 2 };
}

double Square::getArea() const
{
  return width_ * height_;
}

rectangle_t Square::getFrameRect() const
{
  return { width_, height_, pos_ };
}

void Square::move(const double& dx, const double& dy)
{
  pointLl.x += dx;
  pointLl.y += dy;
  pointUr.x += dx;
  pointUr.y += dy;
  pos_.x += dx;
  pos_.y += dy;
}

void Square::move(const point_t& new_center)
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

void Square::scale(double k)
{
  width_ *= k;
  height_ *= k;
}
