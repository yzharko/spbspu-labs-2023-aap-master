#include "concave.hpp"
#include <cmath>
#include <stdexcept>

jirkov::Concave::Concave(point_t firstPoint, point_t secondPoint, point_t thirdPoint, point_t fourthPoint) :
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint),
  fourthPoint_(fourthPoint)
{}

double jirkov::Concave::getArea()
{
  double firstSqrt = sqrt(pow((firstPoint_.x_ - secondPoint_.x_), 2) + pow((firstPoint_.y_ - secondPoint_.y_), 2));
  double secondSqrt = sqrt(pow((secondPoint_.x_ - thirdPoint_.x_), 2) + pow((secondPoint_.y_ - thirdPoint_.y_), 2));
  double thirdSqrt = sqrt(pow((thirdPoint_.x_ - firstPoint_.x_), 2) + pow((thirdPoint_.y_ - firstPoint_.y_), 2));
  double maxSide = firstSqrt >= secondSqrt ? firstSqrt : secondSqrt;
  maxSide = maxSide >= thirdSqrt ? maxSide : thirdSqrt;
  if (maxSide >= firstSqrt + secondSqrt + thirdSqrt - maxSide)
  {
    throw std::logic_error("There is no such triangle\n");
  }
  double mediumSqrt = 0.5 * (firstSqrt + secondSqrt + thirdSqrt);
  double firstSquare = sqrt(mediumSqrt * (mediumSqrt - firstSqrt) * (mediumSqrt - secondSqrt) * (mediumSqrt - thirdSqrt));
  double fourthSqrt = sqrt(pow((fourthPoint_.x_ - secondPoint_.x_), 2) + pow((fourthPoint_.y_ - secondPoint_.y_), 2));
  double fifthSqrt = sqrt(pow((secondPoint_.x_ - thirdPoint_.x_), 2) + pow((secondPoint_.y_ - thirdPoint_.y_), 2));
  double sixthSqrt = sqrt(pow((thirdPoint_.x_ - fourthPoint_.x_), 2) + pow((thirdPoint_.y_ - fourthPoint_.y_), 2));
  double seventhSqrt = 0.5 * (fourthSqrt + fifthSqrt + sixthSqrt);
  double secondSquare = sqrt(seventhSqrt * (seventhSqrt - fourthSqrt) * (seventhSqrt - fifthSqrt) * (seventhSqrt - sixthSqrt));
  return firstSquare - secondSquare;
}

jirkov::rectangle_t jirkov::Concave::getFrameRect()
{
  double maxX = firstPoint_.x_ >= secondPoint_.x_ ? firstPoint_.x_ : secondPoint_.x_;
  maxX = maxX >= thirdPoint_.x_ ? maxX : thirdPoint_.x_;
  double minX = firstPoint_.x_ <= secondPoint_.x_ ? firstPoint_.x_ : secondPoint_.x_;
  minX = minX <= thirdPoint_.x_ ? minX : thirdPoint_.x_;
  double maxY = firstPoint_.y_ >= secondPoint_.y_ ? firstPoint_.y_ : secondPoint_.y_;
  maxY = maxY >= thirdPoint_.y_ ? maxY : thirdPoint_.y_;
  double minY = firstPoint_.y_ <= secondPoint_.y_ ? firstPoint_.y_ : secondPoint_.y_;
  minY = minY <= thirdPoint_.y_ ? minY : thirdPoint_.y_;
  double width = maxX - minX;
  double height = maxY - minY;
  double posX = (maxX + minX) / 2;
  double posY = (maxY + minY) / 2;
  jirkov::point_t pos = { posX, posY };
  return jirkov::rectangle_t{ width, height, pos };
}

void jirkov::Concave::move(point_t destination)
{
  double moveX = destination.x_ - fourthPoint_.x_;
  double moveY = destination.y_ - fourthPoint_.y_;
  move(moveX, moveY);
}

void jirkov::Concave::move(double moveX, double moveY)
{
  firstPoint_.x_ += moveX;
  firstPoint_.y_ += moveY;
  secondPoint_.x_ += moveX;
  secondPoint_.y_ += moveY;
  thirdPoint_.x_ += moveX;
  thirdPoint_.y_ += moveY;
  fourthPoint_.x_ += moveX;
  fourthPoint_.y_ += moveY;
}

void jirkov::Concave::scale(double k)
{
  jirkov::point_t pos;
  pos.x_ = fourthPoint_.x_;
  pos.y_ = fourthPoint_.y_;
  firstPoint_.x_ += (firstPoint_.x_ - pos.x_) * (k - 1);
  firstPoint_.y_ += (firstPoint_.y_ - pos.y_) * (k - 1);
  secondPoint_.x_ += (secondPoint_.x_ - pos.x_) * (k - 1);
  secondPoint_.y_ += (secondPoint_.y_ - pos.y_) * (k - 1);
  thirdPoint_.x_ += (thirdPoint_.x_ - pos.x_) * (k - 1);
  thirdPoint_.y_ += (thirdPoint_.y_ - pos.y_) * (k - 1);
}
