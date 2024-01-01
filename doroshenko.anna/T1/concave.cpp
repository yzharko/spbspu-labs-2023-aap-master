#include "concave.hpp"
#include <cmath>

doroshenko::Concave::Concave(point_t firstPoint, point_t secondPoint, point_t thirdPoint, point_t fourthPoint) :
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint),
  fourthPoint_(fourthPoint)
{}

double doroshenko::Concave::getArea()
{
  double aF = sqrt(pow((firstPoint_.x_ - secondPoint_.x_), 2) + pow((firstPoint_.y_ - secondPoint_.y_), 2));
  double bF = sqrt(pow((secondPoint_.x_ - thirdPoint_.x_), 2) + pow((secondPoint_.y_ - thirdPoint_.y_), 2));
  double cF = sqrt(pow((thirdPoint_.x_ - firstPoint_.x_), 2) + pow((thirdPoint_.y_ - firstPoint_.y_), 2));
  double pF = 0.5 * (aF + bF + cF);
  double firstArea = sqrt(pF * (pF - aF) * (pF - bF) * (pF - cF));

  double aS = sqrt(pow((fourthPoint_.x_ - secondPoint_.x_), 2) + pow((fourthPoint_.y_ - secondPoint_.y_), 2));
  double bS = sqrt(pow((secondPoint_.x_ - thirdPoint_.x_), 2) + pow((secondPoint_.y_ - thirdPoint_.y_), 2));
  double cS = sqrt(pow((thirdPoint_.x_ - fourthPoint_.x_), 2) + pow((thirdPoint_.y_ - fourthPoint_.y_), 2));
  double pS = 0.5 * (aS + bS + cS);
  double secondArea = sqrt(pS * (pS - aS) * (pS - bS) * (pS - cS));

  return firstArea - secondArea;
}

rectangle_t doroshenko::Concave::getFrameRect()
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
  point_t pos = { 0.5 * (maxX - minX), 0.5 * (maxY - minY) };
  return rectangle_t{ width, height, pos };
}

void doroshenko::Concave::move(point_t destination)
{
  double moveX = destination.x_ - fourthPoint_.x_;
  double moveY = destination.y_ - fourthPoint_.y_;
  firstPoint_.x_ += moveX;
  firstPoint_.y_ += moveY;
  secondPoint_.x_ += moveX;
  secondPoint_.y_ += moveY;
  thirdPoint_.x_ += moveX;
  thirdPoint_.y_ += moveY;
  fourthPoint_.x_ += moveX;
  fourthPoint_.y_ += moveY;
}

void doroshenko::Concave::move(double moveX, double moveY)
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

void doroshenko::Concave::scale(point_t pos, double coefficient)
{
  firstPoint_.x_ *= coefficient;
  firstPoint_.y_ *= coefficient;
  secondPoint_.x_ *= coefficient;
  secondPoint_.y_ *= coefficient;
  thirdPoint_.x_ *= coefficient;
  thirdPoint_.y_ *= coefficient;
  fourthPoint_.x_ *= coefficient;
  fourthPoint_.y_ *= coefficient;
}
