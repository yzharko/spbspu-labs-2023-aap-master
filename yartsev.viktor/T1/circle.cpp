#include "circle.hpp"
#include "base-types.hpp"

yartsev::Circle::Circle() :
  center_(),
  radius_(0)
{}

yartsev::Circle::Circle(point_t & center, double radius) :
  center_(center),
  radius_(radius)
{}

double yartsev::Circle::getArea() const
{
  double const PI = 3.1415926535;
  return PI * radius_ * radius_;
}

yartsev::rectangle_t yartsev::Circle::getFrameRect()
{
    yartsev::point_t bottomLeftPoint(center_.x_ - radius_, center_.y_ - radius_);
    yartsev::point_t topRightPoint(center_.x_ + radius_, center_.y_ + radius_);
    yartsev::rectangle_t rez(topRightPoint.x_ - bottomLeftPoint.x_, topRightPoint.y_ - bottomLeftPoint.y_, center_);
    return rez;
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

void yartsev::Circle::pointScale(point_t to, double scaling)
{
  radius_ *= scaling;
  center_.x_ = to.x_ + (center_.x_ - to.x_) * scaling;
  center_.y_ = to.y_ + (center_.y_ - to.y_) * scaling;
}
