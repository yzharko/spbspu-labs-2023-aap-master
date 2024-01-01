#include "triangle.hpp"
#include <cmath>

doroshenko::Triangle::Triangle(point_t firstPoint, point_t secondPoint, point_t thirdPoint) :
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint)
{}

double doroshenko::Triangle::getArea()
{
  double a = sqrt(pow((firstPoint_.x_ - secondPoint_.x_), 2) + pow((firstPoint_.y_ - secondPoint_.y_), 2));
  double b = sqrt(pow((secondPoint_.x_ - thirdPoint_.x_), 2) + pow((secondPoint_.y_ - thirdPoint_.y_), 2));
  double c = sqrt(pow((thirdPoint_.x_ - firstPoint_.x_), 2) + pow((thirdPoint_.y_ - firstPoint_.y_), 2));
  double p = 0.5 * (a + b + c);
  return sqrt(p * (p - a) * (p - b) * (p - c));
}

rectangle_t doroshenko::Triangle::getFrameRect()
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

void doroshenko::Triangle::move(point_t destination)
{
  double moveX = destination.x_ - (firstPoint_.x_ + secondPoint_.x_ + thirdPoint_.x_) / 3;
  double moveY = destination.y_ - (firstPoint_.y_ + secondPoint_.y_ + thirdPoint_.y_) / 3;
  firstPoint_.x_ += moveX;
  firstPoint_.y_ += moveY;
  secondPoint_.x_ += moveX;
  secondPoint_.y_ += moveY;
  thirdPoint_.x_ += moveX;
  thirdPoint_.y_ += moveY;
}

void doroshenko::Triangle::move(double moveX, double moveY)
{
  firstPoint_.x_ += moveX;
  firstPoint_.y_ += moveY;
  secondPoint_.x_ += moveX;
  secondPoint_.y_ += moveY;
  thirdPoint_.x_ += moveX;
  thirdPoint_.y_ += moveY;
}

void doroshenko::Triangle::scale(point_t pos, double coefficient)
{
  firstPoint_.x_ *= coefficient;
  firstPoint_.y_ *= coefficient;
  secondPoint_.x_ *= coefficient;
  secondPoint_.y_ *= coefficient;
  thirdPoint_.x_ *= coefficient;
  thirdPoint_.y_ *= coefficient;
}
