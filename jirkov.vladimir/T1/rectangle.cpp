#include "rectangle.hpp"
#include <cmath>
using namespace jirkov;
Rectangle::Rectangle(point_t bottomLeft, point_t topRight) :
  bottomLeft_(bottomLeft),
  topRight_(topRight)
{}

double Rectangle::getArea() const
{
  double width = abs(topRight.x - bottomLeft.x);
  double height = abs(bottomLeft.y - topRight.y);
  double recSquare = width * height
  return recSquare;
}
rectangle_t Rectangle::getFrameRect() const
{
  double width = abs(topRight_.x - bottomLeft_.x);
  double height = abs(topRight_.y - bottomLeft_.y);
  point_t pos = { topRight_.x + bottomLeft_.x) / 2, topRight_.y + bottomLeft_.y) / 2 };
  return rectangle_t{ width, height, pos };
}

void Rectangle::move(const point_t & center)
{
  dXbottom = bottomLeft_.x + (center.x - rectangle.pos.x);
  dYbottom = bottomLeft_.y + (center.y - rectangle.pos.y)
  dXtop = topRight_.x + (center.x - rectangle.pos.x)
  dYtop = opRight_.y + (center.y - rectangle.pos.y)
  bottomLeft_ = { dXbottom, dYbottom };
  topRight_ = { dXtop, dYtop };
}

void Rectangle::move(const double moveX, const double moveY)
{
  bottomLeft_.x += moveX;
  bottomLeft_.y += moveY;
  topRight_.x += moveX;
  topRight_.y += moveY;
}

void Rectangle::scale(double k)
{
  double buttomFirst = rectangle.pos.x + k * (bottomLeft_.x - rectangle.pos.x);
  double buttomSecond = rectangle.pos.y + k * (bottomLeft_.y - rectangle.pos.y);
  double topFirst = rectangle.pos.x + k * (topRight_.x - rectangle.pos.x)
  double topSecond = rectangle.pos.y + k * (topRight_.y - rectangle.pos.y)

  bottomLeft_ = { buttomFirst, buttomSecond };
  topRight_ = { topFirst, topSecond };
  rectangle.height *= k;
  rectangle.width *= k;
}
