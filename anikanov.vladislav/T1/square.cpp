#include "square.hpp"
#include <iostream>

using namespace anikanov;

point_t Square::getCPoint()
{
  return cPoint;
}

double Square::getArea() const
{
  return side * side;
}

rectangle_t Square::getFrameRect() const
{
  return rectangle_t{cPoint, side, side};
}

void Square::move(const point_t newCPoint)
{
  cPoint = newCPoint;
}

void Square::move(const double x, const double y)
{
  cPoint = point_t(x, y);
}

void Square::scale(const double k)
{
  if (k < 0) {
    throw std::logic_error("Invalid scale argument");
  }
  side *= k;
}

namespace anikanov {

  std::istream &operator>>(std::istream &in, Square &square)
  {
    point_t leftBottom;
    if (!(in >> leftBottom >> square.side) || square.side <= 0) {
      throw std::overflow_error("Invalid Input Square");
    }
    square.cPoint = point_t{leftBottom.x + square.side / 2, leftBottom.y + square.side / 2};
    return in;
  }
}

double Square::getDX(point_t fp, point_t sp)
{
  return fp.x - sp.x;
};

double Square::getDY(point_t fp, point_t sp)
{
  return fp.y - sp.y;
};
