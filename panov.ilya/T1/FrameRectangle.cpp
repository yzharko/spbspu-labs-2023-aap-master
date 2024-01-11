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