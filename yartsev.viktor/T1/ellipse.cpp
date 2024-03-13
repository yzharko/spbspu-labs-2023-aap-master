#include "ellipse.hpp"
#include <stdexcept>
#include "base-types.hpp"

yartsev::Ellipse::Ellipse() :
  center_(),
  radiusX_(0),
  radiusY_(0)
{}

yartsev::Ellipse::Ellipse(point_t & center, double radiusX, double radiusY) :
  center_(center),
  radiusX_(radiusX),
  radiusY_(radiusY)
{
  if (radiusX <= 0 || radiusY <= 0) {
    throw std::logic_error("Radius is below or equals zero\n");
  }
}

double yartsev::Ellipse::getArea() const
{
  double PI = 3.1415926535;
  return PI * radiusX_ * radiusY_;
}

yartsev::rectangle_t yartsev::Ellipse::getFrameRect()
{
  return rectangle_t(radiusX_ * 2, radiusY_ * 2, center_);
}

void yartsev::Ellipse::move(const point_t & to)
{
  center_ = to;
}

void yartsev::Ellipse::move(const double & dx, const double & dy)
{
  center_.x_ += dx;
  center_.y_ += dy;
}

void yartsev::Ellipse::scale(const double & scaling)
{
  radiusX_ *= scaling;
  radiusY_ *= scaling;
}

void yartsev::Ellipse::pointScale(point_t to, double scaling)
{
  radiusX_ *= scaling;
  radiusY_ *= scaling;
  center_.x_ = to.x_ + (center_.x_ - to.x_) * scaling;
  center_.y_ = to.y_ + (center_.y_ - to.y_) * scaling;
}

