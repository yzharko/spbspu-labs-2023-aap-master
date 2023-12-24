#include "FrameRectangle.h"

FrameRectangle::FrameRectangle() {
  width_ = 0.0;
  height_ = 0.0;
  pos_ = Point(0.0, 0.0);
}

FrameRectangle::FrameRectangle(double width, double height, const Point& pos) {
  width_ = width;
  height_ = height;
  pos_ = pos;
}

FrameRectangle::~FrameRectangle() {}

void FrameRectangle::setWidth(double width) {
  width_ = width;
}

void FrameRectangle::setHeight(double height) {
  height_ = height;
}

void FrameRectangle::setPos(const Point& pos) {
  pos_ = pos;
}

double FrameRectangle::getWidth() {
  return width_;
}

double FrameRectangle::getHeight() {
  return height_;
}

Point FrameRectangle::getPos() {
  return pos_;
}