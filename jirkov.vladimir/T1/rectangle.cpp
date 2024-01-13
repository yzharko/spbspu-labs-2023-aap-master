#include "rectangle.hpp"

using namespace jirkov;

Rectangle::Rectangle(double width, double height, const point_t& center) :
  width_(width),
  height_(height),
  center_(center)
{}

double Rectangle::getArea() const
{
  return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
  double width = width_;
  double height = height_;
  double centerX = center_.x;
  double centerY = center_.y;
  point_t center = { centerX, centerY };
  return rectangle_t{ width, height, center };
}

void Rectangle::move(const point_t& destination)
{
  double moveX = destination.x - center_.x;
  double moveY = destination.y - center_.y;
  move(moveX, moveY);
}

void Rectangle::move(double moveX, double moveY)
{
  center_.x += moveX;
  center_.y += moveY;
}

void Rectangle::scale(double k)
{
  double moveX = width_ * (k - 1) / 2;
  double moveY = height_ * (k - 1) / 2;
  center_.x -= moveX;
  center_.y -= moveY;
  width_ *= k;
  height_ *= k;
}
