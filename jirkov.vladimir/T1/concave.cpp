#include "concave.hpp"
#include <cmath>
#include <stdexcept>
using namespace jirkov;
Concave::Concave(const point_t& firstPoint, const point_t& secondPoint, const point_t& thirdPoint, const point_t& fourthPoint) :
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint),
  fourthPoint_(fourthPoint)
{}

double Concave::getArea() const
{
  double dx1 = firstPoint_.x - secondPoint_.x;
  double dy1 = firstPoint_.y - secondPoint_.y;
  double dx2 = secondPoint_.x - thirdPoint_.x;
  double dy2 = secondPoint_.y - thirdPoint_.y;
  double dx3 = thirdPoint_.x - firstPoint_.x;
  double dy3 = thirdPoint_.y - firstPoint_.y;

  double firstSqrt = sqrt(dx1 * dx1 + dy1 * dy1);
  double secondSqrt = sqrt(dx2 * dx2 + dy2 * dy2);
  double thirdSqrt = sqrt(dx3 * dx3 + dy3 * dy3);

  double mediumSqrt = (firstSqrt + secondSqrt + thirdSqrt) / 2;

  double firstSquare = sqrt(mediumSqrt * (mediumSqrt - firstSqrt) * (mediumSqrt - secondSqrt) * (mediumSqrt - thirdSqrt));

  double maxSide1 = std::max(std::max(firstSqrt, secondSqrt), thirdSqrt);

  if (maxSide1 >= firstSqrt + secondSqrt + thirdSqrt - maxSide1) {
    throw std::logic_error("Triangle error");
  }

  double dx4 = fourthPoint_.x - secondPoint_.x;
  double dy4 = fourthPoint_.y - secondPoint_.y;
  double dx5 = secondPoint_.x - thirdPoint_.x;
  double dy5 = secondPoint_.y - thirdPoint_.y;
  double dx6 = thirdPoint_.x - fourthPoint_.x;
  double dy6 = thirdPoint_.y - fourthPoint_.y;
  double fourthSqrt = sqrt(dx4 * dx4 + dy4 * dy4);
  double fifthSqrt = sqrt(dx5 * dx5 + dy5 * dy5);
  double sixthSqrt = sqrt(dx6 * dx6 + dy6 * dy6);

  double seventhSqrt = (fourthSqrt + fifthSqrt + sixthSqrt) * 0.5;
  double secondSquare = sqrt(seventhSqrt * (seventhSqrt - fourthSqrt) * (seventhSqrt - fifthSqrt) * (seventhSqrt - sixthSqrt));
  double maxSide2 = std::max(std::max(fourthSqrt, fifthSqrt), sixthSqrt);

  if (maxSide2 >= fourthSqrt + fifthSqrt + sixthSqrt - maxSide2) {
    throw std::logic_error("Triangle error");
  }
  double dx7 = firstPoint_.x - thirdPoint_.x;
  double dy7 = firstPoint_.y - thirdPoint_.y;
  double dx8 = thirdPoint_.x - fourthPoint_.x;
  double dy8 = thirdPoint_.y - fourthPoint_.y;
  double dx9 = fourthPoint_.x - firstPoint_.x;
  double dy9 = fourthPoint_.y - firstPoint_.y;

  double eighthSqrt = sqrt(dx7 * dx7 + dy7 * dy7);
  double ninthSqrt = sqrt(dx8 * dx8 + dy8 * dy8);
  double tenthSqrt = sqrt(dx9 * dx9 + dy9 * dy9);

  double maxSide3 = std::max(std::max(eighthSqrt, ninthSqrt), tenthSqrt);

  if (maxSide3 >= eighthSqrt + ninthSqrt + tenthSqrt - maxSide3) {
    throw std::logic_error("Triangle error");
  }
  return firstSquare - secondSquare;
}

rectangle_t Concave::getFrameRect() const
{
  double maxX = std::max({firstPoint_.x, secondPoint_.x, thirdPoint_.x, fourthPoint_.x});
  double maxY = std::max({firstPoint_.y, secondPoint_.y, thirdPoint_.y, fourthPoint_.y});
  double minX = std::min({firstPoint_.x, secondPoint_.x, thirdPoint_.x, fourthPoint_.x});
  double minY = std::min({firstPoint_.y, secondPoint_.y, thirdPoint_.y, fourthPoint_.y});

  point_t pos = {(maxX + minX) / 2, (maxY + minY) / 2};
  double width = maxX - minX;
  double height = maxY - minY;
  return { width, height, pos };
}

void Concave::move(const point_t & center)
{
  double moveX = center.x - fourthPoint_.x;
  double moveY = center.y - fourthPoint_.y;
  move(moveX, moveY);
}

void Concave::move(const double moveX, const double moveY)
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
  double factor = k - 1;
  point_t points[] = {firstPoint_, secondPoint_, thirdPoint_};

  for (auto& point : points) {
    point.x += (point.x - pos.x) * factor;
    point.y += (point.y - pos.y) * factor;
  }
}
