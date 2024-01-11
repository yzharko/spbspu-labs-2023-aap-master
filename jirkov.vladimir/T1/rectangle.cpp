#include "rectangle.hpp"

jirkov::Rectangle::Rectangle(point_t bottomLeft, point_t topRight) :
  bottomLeft_(bottomLeft),
  topRight_(topRight)
{}

double jirkov::Rectangle::getArea()
{
  jirkov::rectangle_t frame = getFrameRect();
  return frame.width_ * frame.height_;
}

jirkov::rectangle_t jirkov::Rectangle::getFrameRect()
{
  double width = topRight_.x_ - bottomLeft_.x_;
  double height = topRight_.y_ - bottomLeft_.y_;
  double posX = (topRight_.x_ + bottomLeft_.x_) / 2.0;
  double posY = (topRight_.y_ + bottomLeft_.y_) / 2.0;
  jirkov::point_t pos = { posX, posY };
  return jirkov::rectangle_t{ width, height, pos };
}

void jirkov::Rectangle::move(point_t destination)
{
  jirkov::rectangle_t frame = getFrameRect();
  double moveX = destination.x_ - frame.pos_.x_;
  double moveY = destination.y_ - frame.pos_.y_;
  move(moveX, moveY);
}

void jirkov::Rectangle::move(double moveX, double moveY)
{
  bottomLeft_.x_ += moveX;
  bottomLeft_.y_ += moveY;
  topRight_.x_ += moveX;
  topRight_.y_ += moveY;
}

void jirkov::Rectangle::scale(double k)
{
  jirkov::rectangle_t frame = getFrameRect();
  double moveX = frame.width_ * (k - 1) / 2.0;
  double moveY = frame.height_ * (k - 1) / 2.0;
  bottomLeft_.x_ -= moveX;
  bottomLeft_.y_ -= moveY;
  topRight_.x_ += moveX;
  topRight_.y_ += moveY;
}
