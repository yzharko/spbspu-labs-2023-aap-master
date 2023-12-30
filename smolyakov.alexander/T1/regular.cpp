#include "regular.hpp"
#include "base-types.hpp"
#include <stdexcept>

smolyakov::Regular::Regular(point_t center, point_t secondPoint, point_t thirdPoint)
{
  points_[0] = center;
  points_[1] = secondPoint;
  points_[2] = thirdPoint;
}

double smolyakov::Regular::getArea() const
{
  throw std::logic_error("Not implemented.");
}

smolyakov::rectangle_t smolyakov::Regular::getFrameRect() const
{
  throw std::logic_error("Not implemented.");
}

void smolyakov::Regular::moveTo(double x, double y)
{
  throw std::logic_error("Not implemented.");
}

void smolyakov::Regular::moveBy(double x, double y)
{
  throw std::logic_error("Not implemented.");
}

void smolyakov::Regular::scale(double factor)
{
  throw std::logic_error("Not implemented.");
}
