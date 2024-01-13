#include "FrameRectangle.h"
#include "Point.h"

FrameRectangle::FrameRectangle() {
  pos_ = Point();
  width_ = 0;
  height_ = 0;
}
FrameRectangle::FrameRectangle(Point& pos, double width, double height) {
  pos_ = pos;
  width_ = width;
  height_ = height;
}
void FrameRectangle::scale(double k) {
  if (k > 0) {
    width_ *= k;
    height_ *= k;
  }
  else {
    std::cout << "The coefficient cannot be less than or equal to zero!";
    exit(-1);
  }
}
void FrameRectangle::move(double xdist, double ydist) {
  if (xdist != 0 || ydist != 0) {
    pos_.setX(pos_.getX() + xdist);
    pos_.setY(pos_.getY() + xdist);
  }
  else {
    std::cout << "Both distances are zero!\n";
  }
}
FrameRectangle::~FrameRectangle() {}
Point FrameRectangle::getLeftCorner() {
  Point corner;
  corner.setX(pos_.getX() - (width_ / 2));
  corner.setY(pos_.getY() - (height_ / 2));
  return corner;
}
Point FrameRectangle::getRightCorner() {
  Point corner2;
  corner2.setX(pos_.getX() + (width_ / 2));
  corner2.setY(pos_.getY() + (height_ / 2));
  return corner2;
}
Point FrameRectangle::getCenter() {
  return pos_;
}
double FrameRectangle::getWidth() {
  return width_;
}
double FrameRectangle::getHeight() {
  return height_;
}
void FrameRectangle::show() {
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << "RECTANGLE " << getLeftCorner().getX() << " " << getLeftCorner().getY() << " " << getRightCorner().getX() << " " << getRightCorner().getY() << "\n";
}
