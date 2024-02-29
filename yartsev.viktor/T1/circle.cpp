#include "circle.hpp"
#include "base-types.hpp"

double yartsev::Circle::getArea() const
{
  double const PI = 3.14;
  return PI * radius_ * radius_;
}

yartsev::rectangle_t yartsev::Circle::getFrameRect()
{
    yartsev::point_t bottomLeftPoint(center_.x_ - radius_, center_.y_ - radius_);
    yartsev::point_t topRightPoint(center_.x_ + radius_, center_.y_ + radius_);
    yartsev::rectangle_t rez(topRightPoint.x_ - bottomLeftPoint.x_, topRightPoint.y_ - bottomLeftPoint.y_, center_);
}

void yartsev::Circle::move(const point_t & to) 
{
  center_ = to;
}

void yartsev::Circle::move(const double & dx, const double & dy)
{
  center_.x_ += dx;
  center_.y_ += dy;
}

void yartsev::Circle::scale(const double & scaling)
{
  radius_ *= scaling;
}
