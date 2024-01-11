#include "Point.h"
#include <iostream>
#include <locale.h>

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
Point::~Point() {
}
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
bool Point::isEqual(const Point& point) {
  if (x_ == point.x_ && y_ == point.y_) {
    return true;
  }
  else return false;
}
double Point::getDistance(const Point& point) {
  double xdist = x_ - point.x_;
  double ydist = y_ - point.y_;
  double dist = sqrt(xdist * xdist + ydist * ydist);
  return dist;
}
void Point::move(double dist) {
  x_ += dist;
  y_ += dist;
}
void Point::operator=(const Point& p) {
  x_ = p.x_;
  y_ = p.y_;
}
bool Point::operator==(const Point& p) {
  if (x_ == p.x_ && y_ == p.y_) {
    return true;
  }
  else return false;
}
Point Point::operator+(double k) {
  return Point(x_ + k, y_ + k);
}
Point& Point::operator+=(double k) {
  this->x_ += k;
  this->y_ += k;
  return *this;
}
std::ostream& operator<<(std::ostream& out, Point& p) {
  out << ", coordinates:\nx: ";
  out << p.getX();
  out << " y: ";
  out << p.getY();
  out << '\n';
  return out;
}
std::istream& operator>>(std::istream& in, Point& p) {
  while (true) {
    try {
      in >> p.x_;
      if (in.fail()) {
        throw std::invalid_argument("Input error!\n");
      }
      in >> p.y_;
      if (in.fail()) {
        throw std::invalid_argument("Input error!\n");
      }
      break;
    }
    catch (std::exception& ex) {
      std::cerr << ex.what();
      in.clear();
      in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }
  return in;
}
