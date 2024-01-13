#include "Shape.h"
#include "Circle.h"
#include <iostream>
#include <locale.h>
#include <math.h>

Circle::Circle() {
  center_.setX(0);
  center_.setY(0);
  rad_ = 0;
}
Circle::Circle(Point& center, double rad) {
  if (rad > 0) {
    rad_ = rad;
    center_ = center;
  }
  else {
    std::cerr << "The circle is set incorrectly!";
    exit(-1);
  }
}
Circle::Circle(const Circle& circle) {
  center_ = circle.center_;
  rad_ = circle.rad_;
}
Circle::Circle(Circle&& circle) noexcept {
  center_ = circle.center_;
  rad_ = circle.rad_;

  circle.center_ = Point();
  circle.rad_ = 0;
}
Circle& Circle::operator=(const Circle& circle) {
  center_ = circle.center_;
  rad_ = circle.rad_;
  return *this;
}
Circle& Circle::operator=(Circle&& circle) noexcept {
  if (this != &circle) {
    center_ = circle.center_;
    rad_ = circle.rad_;
    circle.center_ = Point();
    circle.rad_ = 0;
  }
  return *this;
}
Circle::Circle(double x, double y, double rad) {
  if (rad > 0) {
    rad_ = rad;
    center_.setX(x);
    center_.setY(y);
  }
  else {
    std::cerr << "The circle is set incorrectly!";
    exit(-1);
  }
}
Circle::~Circle() {}
Point Circle::getCenter() {
  return center_;
}
double Circle::getRad() {
  return rad_;
}
double Circle::getArea() {
  double s1 = atan(1) * 4 * rad_ * rad_;
  return s1;
}
FrameRectangle Circle::getFrameRectangle() {
  FrameRectangle rect(center_, rad_ * 2, rad_ * 2);
  return rect;
}
void Circle::move(double xdist, double ydist) {
  if (xdist != 0 || ydist != 0) {
    center_.setX(center_.getX() + xdist);
    center_.setY(center_.getY() + ydist);
  }
  else {
    std::cout << "Both distances are zero!\n";
  }
}
void Circle::scale(double k) {
  if (k > 0) {
    rad_ *= k;
  }
  else {
    std::cout << "The coefficient cannot be less than or equal to zero!";
    exit(-1);
  }
}
Shape* Circle::clone() {
  return new Circle(center_, rad_);
}
std::string Circle::getName() const {
  return "CIRCLE";
}
void Circle::show() {
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << "CIRCLE " << center_.getX() << " " << center_.getY() << " " << rad_ << "\n";
}
