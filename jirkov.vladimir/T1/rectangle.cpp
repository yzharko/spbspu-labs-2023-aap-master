#include "rectangle.hpp"
using namespace jirkov;
Rectangle::Rectangle(point_t bottomLeft, point_t topRight) :
  bottomLeft_(bottomLeft),
  topRight_(topRight)
{}

double Rectangle::getArea() const
{
  rectangle_t frame = getFrameRect();
  return frame.width * frame.height;
}
rectangle_t Rectangle::getFrameRect() const
{
  double width = topRight_.x - bottomLeft_.x;
  double height = topRight_.y - bottomLeft_.y;
  double posX = (topRight_.x + bottomLeft_.x) * 0.5;
  double posY = (topRight_.y + bottomLeft_.y) * 0.5;
  point_t pos = { posX, posY };
  return rectangle_t{ width, height, pos };
}

void Rectangle::move(const point_t & destination)
{
  rectangle_t frame = getFrameRect();
  double moveX = destination.x - frame.pos.x;
  double moveY = destination.y - frame.pos.y;
  move(moveX, moveY);
}

void Rectangle::move(double moveX, double moveY)
{
  bottomLeft_.x += moveX;
  bottomLeft_.y += moveY;
  topRight_.x += moveX;
  topRight_.y += moveY;
}

void Rectangle::scale(double k)
{
  rectangle_t frame = getFrameRect();
  double moveX = frame.width * (k - 1) * 0.5;
  double moveY = frame.height * (k - 1) * 0.5;
  bottomLeft_.x -= moveX;
  bottomLeft_.y -= moveY;
  topRight_.x += moveX;
  topRight_.y += moveY;
}
