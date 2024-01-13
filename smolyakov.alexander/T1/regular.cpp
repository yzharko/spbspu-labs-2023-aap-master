#include "regular.hpp"
#include <iostream>
#include <limits>
#include <stdexcept>
#include <cmath>
#include "base-types.hpp"

smolyakov::Regular::Regular(point_t center, point_t secondPoint, point_t thirdPoint)
{
  calculateParameters(center, secondPoint, thirdPoint);
}

double smolyakov::Regular::getArea() const
{
  double sectorArea = outerRadius_ * outerRadius_ * sin(360.0 / sides_);
  return sectorArea * sides_;
}

smolyakov::rectangle_t smolyakov::Regular::getFrameRect() const
{
  return rectangle_t{center_, outerRadius_, outerRadius_};
}

void smolyakov::Regular::moveTo(point_t shift)
{
  center_ = shift;
}

void smolyakov::Regular::moveBy(point_t shift)
{
  center_.x += shift.x;
  center_.y += shift.y;
}

void smolyakov::Regular::scale(double factor)
{
  innerRadius_ *= factor;
  outerRadius_ *= factor;
}

void smolyakov::Regular::calculateParameters(point_t center, point_t secondPoint, point_t thirdPoint)
{
  const double epsilon = 1e-5;
  double firstSide = hypot(center.x - secondPoint.x, center.y - secondPoint.y);
  double secondSide = hypot(center.x - thirdPoint.x, center.y - thirdPoint.y);
  innerRadius_ = firstSide < secondSide ? firstSide : secondSide;
  outerRadius_ = firstSide < secondSide ? secondSide : firstSide;
  double sides = M_PI / acos(innerRadius_ / outerRadius_);
  if (sides - round(sides) > epsilon)
  {
    std::cout << sides << '\n';
    std::cout << (long)sides << '\n';
    throw std::invalid_argument("Invalid regular shape control points.");
  }
  sides_ = round(sides);
}
