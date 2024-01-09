#include "rectangle.hpp"

doroshenko::Rectangle::Rectangle(point_t lowerLeft, point_t upperRight) :
  lowerLeft_(lowerLeft),
  upperRight_(upperRight)
{}

double doroshenko::Rectangle::getArea()
{
  rectangle_t frame = getFrameRect();
  return frame.width_ * frame.height_;
}

rectangle_t doroshenko::Rectangle::getFrameRect()
{
  double width = upperRight_.x_ - lowerLeft_.x_;
  double height = upperRight_.y_ - lowerLeft_.y_;
  point_t pos = { 0.5 * (upperRight_.x_ - lowerLeft_.x_), 0.5 * (upperRight_.y_ - lowerLeft_.y_) };
  return rectangle_t{ width, height, pos };
}

void doroshenko::Rectangle::move(point_t destination)
{
  rectangle_t frame = getFrameRect();
  double moveX = destination.x_ - frame.pos_.x_;
  double moveY = destination.y_ - frame.pos_.y_;
  move(moveX, moveY);
}

void doroshenko::Rectangle::move(double moveX, double moveY)
{
  lowerLeft_.x_ += moveX;
  lowerLeft_.y_ += moveY;
  upperRight_.x_ += moveX;
  upperRight_.y_ += moveY;
}

void doroshenko::Rectangle::scale(double coefficient)
{
  rectangle_t frame = getFrameRect();
  double moveX = frame.width_ * (coefficient - 1) * 0.5;
  double moveY = frame.height_ * (coefficient - 1) * 0.5;
  lowerLeft_.x_ -= moveX;
  lowerLeft_.y_ -= moveY;
  upperRight_.x_ += moveX;
  upperRight_.y_ += moveY;
}
