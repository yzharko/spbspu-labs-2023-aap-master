#include "Circle.hpp"
#include "base-types.hpp"

Circle::Circle(point_t center, double radius) :
  center_(center),
  radius_(radius)
{}

double Circle::getArea() {
  return (3.14 * radius_ * radius_);
}

void Circle::move(double x, double y) {
  center_.x_ += x;
  center_.y_ += y;
}

void Circle::move(point_t center) {
  center_ = center;
}

void Circle::scale(double k) {
  radius_ = radius_ * k;
}

rectangle_t Circle::getFrameRect() {
  return rectangle_t(2 * radius_, 2 * radius_, center_);
}