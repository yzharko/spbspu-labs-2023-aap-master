#include "Circle.h"
#include "FrameRectangle.h"
#include <cmath>
#include <iostream>
#include <string>

Circle::Circle() {
  center_ = Point(0.0, 0.0);
  radius_ = 0.0;
}

Circle::Circle(const Point& center, double radius) {
  center_ = center;
  radius_ = radius;
}

Circle::~Circle() {}

Point Circle::getCenter() {
  return center_;
}

double Circle::getRadius() {
  return radius_;
}

double Circle::getArea() {
  return 3.14 * pow(radius_, 2);
}

FrameRectangle Circle::getFrameRectangle() {
  double width = radius_ * 2;
  double height = radius_ * 2;
  Point pos;
  pos.setX(center_.getX() - width / 2);
  pos.setY(center_.getY() - height / 2);
  FrameRectangle frameRect(width, height, pos);
  return frameRect;
}

void Circle::move(double dx, double dy) {
  center_ = Point(center_.getX() + dx, center_.getY() + dy);
}

void Circle::scale(double size) {
  radius_ *= size;
}

Shape* Circle::clone() {
  return new Circle(*this);
}

std::string Circle::getName() {
  return "CIRCLE";
}