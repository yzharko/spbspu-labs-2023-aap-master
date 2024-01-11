#include "Shape.h"
#include "Diamond.h"
#include <iostream>
#include <locale.h>
#include <math.h>

Diamond::Diamond() {
  center_.setX(0);
  center_.setY(0);
  diagHor_ = 0;
  diagVert_ = 0;
}
Diamond::Diamond(Point& center, double diagHor, double diagVert) {
  if (diagHor > 0 && diagVert > 0) {
    diagHor_ = diagHor;
    diagVert_ = diagVert;
    center_ = center;
  }
  else {
    std::cerr << "The diamond is set incorrectly!";
    exit(-1);
  }
}
Diamond::Diamond(const Diamond& Diamond) {
  center_ = Diamond.center_;
  diagHor_ = Diamond.diagHor_;
  diagVert_ = Diamond.diagVert_;
}
Diamond::Diamond(Diamond&& Diamond) noexcept {
  center_ = Diamond.center_;
  diagHor_ = Diamond.diagHor_;
  diagVert_ = Diamond.diagVert_;
  Diamond.center_ = Point();
  Diamond.diagHor_ = 0;
  Diamond.diagVert_ = 0;
}
Diamond& Diamond::operator=(const Diamond& Diamond) {
  center_ = Diamond.center_;
  diagHor_ = Diamond.diagHor_;
  diagVert_ = Diamond.diagVert_;
  return *this;
}
Diamond& Diamond::operator=(Diamond&& Diamond) noexcept {
  if (this != &Diamond) {
    center_ = Diamond.center_;
    diagHor_ = Diamond.diagHor_;
    diagVert_ = Diamond.diagVert_;
    Diamond.center_ = Point();
    Diamond.diagHor_ = 0;
    Diamond.diagVert_ = 0;
  }
  return *this;
}
Diamond::Diamond(double x, double y, double diagHor, double diagVert) {
  if (diagHor > 0 && diagVert > 0) {
    diagHor_ = diagHor;
    diagVert_ = diagVert;
    center_.setX(x);
    center_.setY(y);
  }
  else {
    std::cerr << "The diamond is set incorrectly!";
    exit(-1);
  }
}
Diamond::~Diamond() {}
Point Diamond::getCenter() {
  return center_;
}
double Diamond::getdiagHor() {
  return diagHor_;
}
double Diamond::getdiagVert() {
  return diagVert_;
}
double Diamond::getArea() {
  double s1 = (diagHor_ * diagVert_) / 2;
  return s1;
}
FrameRectangle Diamond::getFrameRectangle() {
  FrameRectangle rect(center_, diagHor_, diagVert_);
  return rect;
}
void Diamond::move(double xdist, double ydist) {
  if (xdist != 0 || ydist != 0) {
    center_.setX(center_.getX() + xdist);
    center_.setY(center_.getY() + ydist);
  }
  else {
    std::cout << "Both distances are zero!\n";
  }
}
void Diamond::scale(double k) {
  if (k > 0) {
    diagHor_ *= k;
    diagVert_ *= k;
  }
  else {
    std::cout << "The coefficient cannot be less than or equal to zero!";
    exit(-1);
  }
}
Shape* Diamond::clone() {
  return new Diamond(center_, diagHor_, diagVert_);
}
std::string Diamond::getName() const {
  return "DIAMOND";
}