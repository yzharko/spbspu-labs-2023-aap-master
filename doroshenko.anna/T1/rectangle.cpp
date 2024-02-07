#include "rectangle.hpp"
#include <iostream>

using namespace doroshenko;

Rectangle::Rectangle(point_t lowerLeft, point_t upperRight) :
  lowerLeft_(lowerLeft),
  upperRight_(upperRight)
{}

double Rectangle::getArea() const
{
  rectangle_t frame = getFrameRect();
  return frame.width * frame.height;
}

rectangle_t Rectangle::getFrameRect() const
{
  double width = upperRight_.x - lowerLeft_.x;
  double height = upperRight_.y - lowerLeft_.y;
  double posX = 0.5 * (upperRight_.x + lowerLeft_.x);
  double posY = 0.5 * (upperRight_.y + lowerLeft_.y);
  point_t pos = { posX, posY };
  return rectangle_t{ width, height, pos };
}

void Rectangle::move(const point_t& destination)
{
  rectangle_t frame = getFrameRect();
  double moveX = destination.x - frame.pos.x;
  double moveY = destination.y - frame.pos.y;
  move(moveX, moveY);
}

void Rectangle::move(double moveX, double moveY)
{
  lowerLeft_.x += moveX;
  lowerLeft_.y += moveY;
  upperRight_.x += moveX;
  upperRight_.y += moveY;
}

void Rectangle::scale(double coefficient)
{
  rectangle_t frame = getFrameRect();
  double moveX = frame.width * (coefficient - 1) * 0.5;
  double moveY = frame.height * (coefficient - 1) * 0.5;
  lowerLeft_.x -= moveX;
  lowerLeft_.y -= moveY;
  upperRight_.x += moveX;
  upperRight_.y += moveY;
}
