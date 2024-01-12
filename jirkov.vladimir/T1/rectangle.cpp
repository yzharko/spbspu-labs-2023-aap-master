#include "rectangle.hpp"
using namespace jirkov;
Rectangle::Rectangle(point_t bottomLeft, point_t topRight) :
  bottomLeft_(bottomLeft),
  topRight_(topRight)
{}

double Rectangle::getArea() const
{
  jirkov::rectangle_t frame = getFrameRect();
  return frame.width_ * frame.height_;
}

jirkov::rectangle_t Rectangle::getFrameRect() const
{
  double width = topRight_.x_ - bottomLeft_.x_;
  double height = topRight_.y_ - bottomLeft_.y_;
  double posX = (topRight_.x_ + bottomLeft_.x_) / 2.0;
  double posY = (topRight_.y_ + bottomLeft_.y_) / 2.0;
  point_t pos = { posX, posY };
  return rectangle_t{ width, height, pos };
}

void Rectangle::move(point_t destination)
{
  rectangle_t frame = getFrameRect();
  double moveX = destination.x_ - frame.pos_.x_;
  double moveY = destination.y_ - frame.pos_.y_;
  move(moveX, moveY);
}

void Rectangle::move(double moveX, double moveY)
{
  bottomLeft_.x_ += moveX;
  bottomLeft_.y_ += moveY;
  topRight_.x_ += moveX;
  topRight_.y_ += moveY;
}

void Rectangle::scale(double k)
{
  rectangle_t frame = getFrameRect();
  double moveX = frame.width_ * (k - 1) / 2.0;
  double moveY = frame.height_ * (k - 1) / 2.0;
  bottomLeft_.x_ -= moveX;
  bottomLeft_.y_ -= moveY;
  topRight_.x_ += moveX;
  topRight_.y_ += moveY;
}
