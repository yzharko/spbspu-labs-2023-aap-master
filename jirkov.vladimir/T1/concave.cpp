#include "concave.hpp"
#include <cmath>
#include <stdexcept>
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
  double mediumSqrt = (firstSqrt + secondSqrt + thirdSqrt) / 2;
  double firstSquare = sqrt(mediumSqrt * (mediumSqrt - firstSqrt) * (mediumSqrt - secondSqrt) * (mediumSqrt - thirdSqrt));
  double maxSide = firstSqrt >= secondSqrt ? firstSqrt : secondSqrt;
  maxSide = maxSide >= thirdSqrt ? maxSide : thirdSqrt;
  if (maxSide >= firstSqrt + secondSqrt + thirdSqrt - maxSide)
  {
    throw std::logic_error("Triangle error\n");
  }
  double fourthSqrt = sqrt(pow((fourthPoint_.x - secondPoint_.x), 2) + pow((fourthPoint_.y - secondPoint_.y), 2));
  double fifthSqrt = sqrt(pow((secondPoint_.x - thirdPoint_.x), 2) + pow((secondPoint_.y - thirdPoint_.y), 2));
  double sixthSqrt = sqrt(pow((thirdPoint_.x - fourthPoint_.x), 2) + pow((thirdPoint_.y - fourthPoint_.y), 2));
  double seventhSqrt = (fourthSqrt + fifthSqrt + sixthSqrt) / 2;
  double secondSquare = sqrt(seventhSqrt * (seventhSqrt - fourthSqrt) * (seventhSqrt - fifthSqrt) * (seventhSqrt - sixthSqrt));
  maxSide = fourthSqrt >= fifthSqrt ? fourthSqrt : fifthSqrt;
  maxSide = maxSide >= sixthSqrt ? maxSide : sixthSqrt;
  if (maxSide >= fourthSqrt + fifthSqrt + sixthSqrt - maxSide)
  {
    throw std::logic_error("Triangle error\n");
  }
  double eighthSqrt = sqrt(pow((firstPoint_.x - secondPoint_.x), 2) + pow((firstPoint_.y - secondPoint_.y), 2));
  double ninthSqrt = sqrt(pow((secondPoint_.x - fourthPoint_.x), 2) + pow((secondPoint_.y - fourthPoint_.y), 2));
  double tenthSqrt = sqrt(pow((fourthPoint_.x - firstPoint_.x), 2) + pow((fourthPoint_.y - firstPoint_.y), 2));
  maxSide = eighthSqrt >= ninthSqrt ? eighthSqrt : ninthSqrt;
  maxSide = maxSide >= tenthSqrt ? maxSide : tenthSqrt;
  if (maxSide >= eighthSqrt + ninthSqrt + tenthSqrt - maxSide)
  {
    throw std::logic_error("Triangle error\n");
  }
  eighthSqrt = sqrt(pow((firstPoint_.x - thirdPoint_.x), 2) + pow((firstPoint_.y - thirdPoint_.y), 2));
  ninthSqrt = sqrt(pow((thirdPoint_.x - fourthPoint_.x), 2) + pow((thirdPoint_.y - fourthPoint_.y), 2));
  tenthSqrt = sqrt(pow((fourthPoint_.x - firstPoint_.x), 2) + pow((fourthPoint_.y - firstPoint_.y), 2));
  maxSide = eighthSqrt >= ninthSqrt ? eighthSqrt : ninthSqrt;
  maxSide = maxSide >= tenthSqrt ? maxSide : tenthSqrt;
  if (maxSide >= eighthSqrt + ninthSqrt + tenthSqrt - maxSide)
  {
    throw std::logic_error("Triangle error\n");
  }
  return firstSquare - secondSquare;
}
rectangle_t Concave::getFrameRect() const
{
  double maxX = firstPoint_.x >= secondPoint_.x ? firstPoint_.x : secondPoint_.x;
  maxX = maxX >= thirdPoint_.x ? maxX : thirdPoint_.x;
  double minX = firstPoint_.x <= secondPoint_.x ? firstPoint_.x : secondPoint_.x;
  minX = minX <= thirdPoint_.x ? minX : thirdPoint_.x;
  double maxY = firstPoint_.y >= secondPoint_.y ? firstPoint_.y : secondPoint_.y;
  maxY = maxY >= thirdPoint_.y ? maxY : thirdPoint_.y;
  double minY = firstPoint_.y <= secondPoint_.y ? firstPoint_.y : secondPoint_.y;
  minY = minY <= thirdPoint_.y ? minY : thirdPoint_.y;
  double width = maxX - minX;
  double height = maxY - minY;
  double posX = (maxX + minX) / 2;
  double posY = (maxY + minY) / 2;
  point_t pos = { posX, posY };
  return rectangle_t{ width, height, pos };
}

void Concave::move(point_t destination)
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
  point_t pos;
  pos.x = fourthPoint_.x;
  pos.y = fourthPoint_.y;
  firstPoint_.x += (firstPoint_.x - pos.x) * (k - 1);
  firstPoint_.y += (firstPoint_.y - pos.y) * (k - 1);
  secondPoint_.x += (secondPoint_.x - pos.x) * (k - 1);
  secondPoint_.y += (secondPoint_.y - pos.y) * (k - 1);
  thirdPoint_.x += (thirdPoint_.x - pos.x) * (k - 1);
  thirdPoint_.y += (thirdPoint_.y - pos.y) * (k - 1);
}
