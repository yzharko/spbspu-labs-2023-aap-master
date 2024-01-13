#include "regular.hpp"
#include <stdexcept>
#include <cmath>
#include "base-types.hpp"

smolyakov::Regular::Regular(point_t center, point_t secondPoint, point_t thirdPoint)
{
  calculateParameters(center, secondPoint, thirdPoint);
}

double smolyakov::Regular::getArea() const
{
  double sectorArea = 0.5 * outerRadius_ * outerRadius_ * sin(2.0 / sides_ * M_PI);
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
  double thirdSide = hypot(thirdPoint.x - secondPoint.x, thirdPoint.y - secondPoint.y);

  bool isRightTriangle = (std::abs(firstSide * firstSide - secondSide * secondSide - thirdSide * thirdSide) < epsilon)
    || (std::abs(secondSide * secondSide - thirdSide * thirdSide - firstSide * firstSide) < epsilon)
    || (std::abs(thirdSide * thirdSide - firstSide * firstSide - secondSide * secondSide) < epsilon);
  if (!isRightTriangle)
  {
    throw std::invalid_argument("The given triangle is not a right triangle.");
  }

  innerRadius_ = firstSide < secondSide ? firstSide : secondSide;
  outerRadius_ = firstSide < secondSide ? secondSide : firstSide;
  double sides = M_PI / acos(innerRadius_ / outerRadius_);
  if (sides - round(sides) > epsilon)
  {
    throw std::invalid_argument("Invalid regular shape control points.");
  }
  sides_ = round(sides);
}
