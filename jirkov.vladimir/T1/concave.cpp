#include "concave.hpp"
#include <cmath>
#include <stdexcept>
#include <algorithm>
using namespace jirkov;
Concave::Concave(point_t firstPoint, point_t secondPoint, point_t thirdPoint, point_t fourthPoint) :
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint),
  fourthPoint_(fourthPoint)
{}
double Concave::getArea() const
{
  double firstSqrt = sqrt(pow((firstPoint_.x - secondPoint_.x), 2) + pow((firstPoint_.y - secondPoint_.y), 2));
  double secondSqrt = sqrt(pow((secondPoint_.x - thirdPoint_.x), 2) + pow((secondPoint_.y - thirdPoint_.y), 2));
  double thirdSqrt = sqrt(pow((thirdPoint_.x - firstPoint_.x), 2) + pow((thirdPoint_.y - firstPoint_.y), 2));

  double semiPerimeter = (firstSqrt + secondSqrt + thirdSqrt) * 0.5;

  double firstSquare = sqrt(semiPerimeter * (semiPerimeter - firstSqrt) * (semiPerimeter - secondSqrt) * (semiPerimeter - thirdSqrt));

  double maxSide = std::max({firstSqrt, secondSqrt, thirdSqrt});

  if (maxSide >= firstSqrt + secondSqrt + thirdSqrt - maxSide)
  {
    throw std::logic_error("Triangle error\n");
  }

  double fourthSqrt = sqrt(pow((fourthPoint_.x - secondPoint_.x), 2) + pow((fourthPoint_.y - secondPoint_.y), 2));
  double fifthSqrt = sqrt(pow((secondPoint_.x - thirdPoint_.x), 2) + pow((secondPoint_.y - thirdPoint_.y), 2));
  double sixthSqrt = sqrt(pow((thirdPoint_.x - fourthPoint_.x), 2) + pow((thirdPoint_.y - fourthPoint_.y), 2));

  double secondSemiPerimeter = (fourthSqrt + fifthSqrt + sixthSqrt) * 0.5;

  double secondSquare = sqrt(secondSemiPerimeter * (secondSemiPerimeter - fourthSqrt) * (secondSemiPerimeter - fifthSqrt) * (secondSemiPerimeter - sixthSqrt));

  maxSide = std::max({fourthSqrt, fifthSqrt, sixthSqrt});

  if (maxSide >= fourthSqrt + fifthSqrt + sixthSqrt - maxSide)
  {
    throw std::logic_error("Triangle error\n");
  }

  double eighthSqrt = sqrt(pow((firstPoint_.x - secondPoint_.x), 2) + pow((firstPoint_.y - secondPoint_.y), 2));
  double ninthSqrt = sqrt(pow((secondPoint_.x - fourthPoint_.x), 2) + pow((secondPoint_.y - fourthPoint_.y), 2));
  double tenthSqrt = sqrt(pow((fourthPoint_.x - firstPoint_.x), 2) + pow((fourthPoint_.y - firstPoint_.y), 2));

  maxSide = std::max({eighthSqrt, ninthSqrt, tenthSqrt});

  if (maxSide >= eighthSqrt + ninthSqrt + tenthSqrt - maxSide)
  {
    throw std::logic_error("Triangle error\n");
  }

  eighthSqrt = sqrt(pow((firstPoint_.x - thirdPoint_.x), 2) + pow((firstPoint_.y - thirdPoint_.y), 2));
  ninthSqrt = sqrt(pow((thirdPoint_.x - fourthPoint_.x), 2) + pow((thirdPoint_.y - fourthPoint_.y), 2));
  tenthSqrt = sqrt(pow((fourthPoint_.x - firstPoint_.x), 2) + pow((fourthPoint_.y - firstPoint_.y), 2));

  maxSide = std::max({eighthSqrt, ninthSqrt, tenthSqrt});

  if (maxSide >= eighthSqrt + ninthSqrt + tenthSqrt - maxSide)
  {
    throw std::logic_error("Triangle error\n");
  }
  return firstSquare - secondSquare;
}
rectangle_t Concave::getFrameRect() const
{
  double maxX = std::max({ firstPoint_.x, secondPoint_.x, thirdPoint_.x });
  double minX = std::min({ firstPoint_.x, secondPoint_.x, thirdPoint_.x });
  double maxY = std::max({ firstPoint_.y, secondPoint_.y, thirdPoint_.y });
  double minY = std::min({ firstPoint_.y, secondPoint_.y, thirdPoint_.y });
  double width = maxX - minX;
  double height = maxY - minY;
  double posX = (maxX + minX) * 0.5;
  double posY = (maxY + minY) * 0.5;
  point_t pos = { posX, posY };
  return rectangle_t{ width, height, pos };
}
void Concave::move(const point_t & destination)
{
  double moveX = destination.x - fourthPoint_.x;
  double moveY = destination.y - fourthPoint_.y;
  move(moveX, moveY);
}

void Concave::move(double moveX, double moveY)
{
  firstPoint_.x += moveX;
  firstPoint_.y += moveY;
  secondPoint_.x += moveX;
  secondPoint_.y += moveY;
  thirdPoint_.x += moveX;
  thirdPoint_.y += moveY;
  fourthPoint_.x += moveX;
  fourthPoint_.y += moveY;
}

void Concave::scale(double k)
{
  point_t pos = fourthPoint_;

  double dx = (firstPoint_.x - pos.x) * (k - 1);
  double dy = (firstPoint_.y - pos.y) * (k - 1);
  firstPoint_.x += dx;
  firstPoint_.y += dy;

  dx = (secondPoint_.x - pos.x) * (k - 1);
  dy = (secondPoint_.y - pos.y) * (k - 1);
  secondPoint_.x += dx;
  secondPoint_.y += dy;

  dx = (thirdPoint_.x - pos.x) * (k - 1);
  dy = (thirdPoint_.y - pos.y) * (k - 1);
  thirdPoint_.x += dx;
  thirdPoint_.y += dy;
}
