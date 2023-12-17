#include "Point.h"

Point::Point() {
  x_ = 0.0;
  y_ = 0.0;
}

Point::Point(double x, double y) {
  x_ = x;
  y_ = y;
}

Point::Point(const Point& point) {
  x_ = point.x_;
  y_ = point.y_;
}

Point::~Point() {}

void Point::setX(double x) {
  x_ = x;
}

void Point::setY(double y) {
  y_ = y;
}

double Point::getX() {
  return x_;
}

double Point::getY() {
  return y_;
}