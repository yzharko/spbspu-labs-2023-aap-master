#include "ellipse.hpp"

yartsev::Ellipse::Ellipse() :
  center_(),
  radiusX_(0),
  radiusY_(0)
{}

yartsev::Ellipse::Ellipse(point_t & center, double radiusX, double radiusY) :
  center_(center),
  radiusX_(radiusX),
  radiusY_(radiusY)
{}

double yartsev::Ellipse::getArea() const
{
  double PI = 3.1415926535;
  return PI * radiusX_ * radiusY_;
}
