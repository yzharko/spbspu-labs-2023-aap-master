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
  double firstDiffX = firstPoint_.x - secondPoint_.x;
  double firstDiffY = firstPoint_.y - secondPoint_.y;
  double secondDiffX = secondPoint_.x - thirdPoint_.x;
  double secondDiffY = secondPoint_.y - thirdPoint_.y;
  double thirdDiffX = thirdPoint_.x - firstPoint_.x;
  double thirdDiffY = thirdPoint_.y - firstPoint_.y;

  double firstSqrt = sqrt(firstDiffX * firstDiffX + firstDiffY * firstDiffY);
  double secondSqrt = sqrt(secondDiffX * secondDiffX + secondDiffY * secondDiffY);
  double thirdSqrt = sqrt(thirdDiffX * thirdDiffX + thirdDiffY * thirdDiffY);
  double mediumSqrt = (firstSqrt + secondSqrt + thirdSqrt) * 0.5;
  double firstSquare = sqrt(mediumSqrt * (mediumSqrt - firstSqrt) * (mediumSqrt - secondSqrt) * (mediumSqrt - thirdSqrt));

  double maxSide = (firstSqrt >= secondSqrt) ? firstSqrt : secondSqrt;
  maxSide = (maxSide >= thirdSqrt) ? maxSide : thirdSqrt;

  if (maxSide >= firstSqrt + secondSqrt + thirdSqrt - maxSide)
  {
    throw std::logic_error("Triangle error");
  }

  double fourthDiffX = fourthPoint_.x - secondPoint_.x;
  double fourthDiffY = fourthPoint_.y - secondPoint_.y;
  double fifthDiffX = secondPoint_.x - thirdPoint_.x;
  double fifthDiffY = secondPoint_.y - thirdPoint_.y;
  double sixthDiffX = thirdPoint_.x - fourthPoint_.x;
  double sixthDiffY = thirdPoint_.y - fourthPoint_.y;
  double fourthSqrt = sqrt(fourthDiffX * fourthDiffX + fourthDiffY * fourthDiffY);
  double fifthSqrt = sqrt(fifthDiffX * fifthDiffX + fifthDiffY * fifthDiffY);
  double sixthSqrt = sqrt(sixthDiffX * sixthDiffX + sixthDiffY * sixthDiffY);
  double seventhSqrt = (fourthSqrt + fifthSqrt + sixthSqrt) * 0.5;
  double secondSquare = sqrt(seventhSqrt * (seventhSqrt - fourthSqrt) * (seventhSqrt - fifthSqrt) * (seventhSqrt - sixthSqrt));

  maxSide = (fourthSqrt >= fifthSqrt) ? fourthSqrt : fifthSqrt;
  maxSide = (maxSide >= sixthSqrt) ? maxSide : sixthSqrt;

  if (maxSide >= fourthSqrt + fifthSqrt + sixthSqrt - maxSide)
  {
    throw std::logic_error("Triangle error");
  }

  double eighthDiffX = firstPoint_.x - secondPoint_.x;
  double eighthDiffY = firstPoint_.y - secondPoint_.y;
  double ninthDiffX = secondPoint_.x - fourthPoint_.x;
  double ninthDiffY = secondPoint_.y - fourthPoint_.y;
  double tenthDiffX = fourthPoint_.x - firstPoint_.x;
  double tenthDiffY = fourthPoint_.y - firstPoint_.y;

  maxSide = (firstSqrt >= secondSqrt) ? firstSqrt : secondSqrt;
  maxSide = (maxSide >= thirdSqrt) ? maxSide : thirdSqrt;

  if (maxSide >= firstSqrt + secondSqrt + thirdSqrt - maxSide)
  {
    throw std::logic_error("Triangle error");
  }

  eighthDiffX = firstPoint_.x - thirdPoint_.x;
  eighthDiffY = firstPoint_.y - thirdPoint_.y;
  ninthDiffX = thirdPoint_.x - fourthPoint_.x;
  ninthDiffY = thirdPoint_.y - fourthPoint_.y;
  tenthDiffX = fourthPoint_.x - firstPoint_.x;
  tenthDiffY = fourthPoint_.y - firstPoint_.y;

  maxSide = (firstSqrt >= secondSqrt) ? firstSqrt : secondSqrt;
  maxSide = (maxSide >= thirdSqrt) ? maxSide : thirdSqrt;

  if (maxSide >= firstSqrt + secondSqrt + thirdSqrt - maxSide)
  {
    throw std::logic_error("Triangle error");
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
void Concave::move(const point_t& destination)
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
  double scalingFactor = k - 1;
  point_t pos = fourthPoint_;

  firstPoint_.x += (firstPoint_.x - pos.x) * scalingFactor;
  firstPoint_.y += (firstPoint_.y - pos.y) * scalingFactor;
  secondPoint_.x += (secondPoint_.x - pos.x) * scalingFactor;
  secondPoint_.y += (secondPoint_.y - pos.y) * scalingFactor;
  thirdPoint_.x += (thirdPoint_.x - pos.x) * scalingFactor;
  thirdPoint_.y += (thirdPoint_.y - pos.y) * scalingFactor;
}
