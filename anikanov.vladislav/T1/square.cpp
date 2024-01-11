#include "square.hpp"
#include <iostream>

using namespace anikanov;

Square::Square()
{
  side = 0;
  cPoint = point_t();
}

void Square::setSide(float newSide)
{
  side = newSide;
}

float Square::getSide() const
{
  return side;
}

point_t Square::getCPoint() const
{
  return cPoint;
}

float Square::getArea()
{
  return side * side;
}

rectangle_t Square::getFrameRect()
{
  return rectangle_t(cPoint, side, side);
}

void Square::move(point_t newCPoint)
{
  cPoint = newCPoint;
}

void Square::move(float x, float y)
{
  cPoint = point_t(x, y);
}

void Square::scale(float k, point_t center)
{
  if (k < 0) {
    throw std::logic_error("Invalid scale argument");
  }
  side *= k;
  cPoint.x += (k - 1) * getDX(cPoint, center);
  cPoint.y += (k - 1) * getDY(cPoint, center);
}

namespace anikanov {

  std::istream &operator>>(std::istream &in, Square &square)
  {
    point_t leftBottom;
    if (!(in >> leftBottom >> square.side) || square.side <= 0) {
      throw std::overflow_error("Invalid Input Square");
    }
    square.cPoint = point_t(leftBottom.x + square.side / 2,
                           leftBottom.y + square.side / 2);
    return in;
  }
}
