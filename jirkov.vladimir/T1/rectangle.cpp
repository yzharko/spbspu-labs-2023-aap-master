#include "rectangle.hpp"
using namespace jirkov;
Rectangle::Rectangle(point_t bottomLeft, point_t topRight) :
  bottomLeft_(bottomLeft),
  topRight_(topRight)
{}

double Rectangle::getArea() const
{
  double width = topRight_.x - bottomLeft_.x;
  double height = bottomLeft_.y - topRight_.y;
  double recSquare = width * height;
  return recSquare;
}
rectangle_t Rectangle::getFrameRect() const
{
  double width = topRight_.x - bottomLeft_.x;
  double height = topRight_.y - bottomLeft_.y;
  point_t pos = { (topRight_.x + bottomLeft_.x) / 2, (topRight_.y + bottomLeft_.y) / 2 };
  return rectangle_t{ width, height, pos };
}
void Rectangle::move(const point_t & destination)
{
  double dXbottom = bottomLeft_.x + (destination.x - rectangle.pos.x);
  double dYbottom = bottomLeft_.y + (destination.y - rectangle.pos.y);
  double dXtop = topRight_.x + (destination.x - rectangle.pos.x);
  double dYtop = topRight_.y + (destination.y - rectangle.pos.y);
  bottomLeft_ = { dXbottom, dYbottom };
  topRight_ = { dXtop, dYtop };
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
