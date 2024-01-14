#include <iostream>
#include <stdexcept>
#include "ellipse.hpp"
#include "baseTypes.hpp"

taskaev::Ellipse::Ellipse(point_t center, double verticalRad, double gorisontRad):
  center_(center), verticalRad_(verticalRad), gorisontRad_(gorisontRad)
{
  if(verticalRad <= 0 || gorisontRad <= 0)
  {
    throw std::logic_error("Error, not ellipse");
  }
}

double taskaev::Ellipse::getArea()
{
  return PI * verticalRad_ * gorisontRad_;
}

rectangle_t taskaev::Ellipse::getFrameRect()
{
  double width = verticalRad_ * 2;
  double height = gorisontRad_ * 2;
  point_t pos = center_;
  return rectangle_t{ width, height, pos };
}

void taskaev::Ellipse::move(double x, double y)
{
  center_.X = center_.X + x;
  center_.Y = center_.Y + y;
}

void taskaev::Ellipse::move(const point_t& newCenter)
{
  center_ = newCenter;
}

void taskaev::Ellipse::scale(double k)
{
  verticalRad_ += k;
  gorisontRad_ += k;
}
