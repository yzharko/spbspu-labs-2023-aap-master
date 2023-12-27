#include "rectangle.hpp"

ponomarev::Rectangle::Rectangle(point_t lowerLeft, point_t upperRight) :
  lowerLeft(lowerLeft),
  upperRight(upperRight)
{}

double ponomarev::Rectangle::getArea()
{
  rectangle_t frame = getFrameRect();
  return frame.width * frame.height;
}

rectangle_t ponomarev::Rectangle::getFrameRect()
{
  double width = upperRight.x - lowerLeft.x;
  double height = upperRight.y - lowerLeft.y;
  point_t pos = { 0.5 * (upperRight.x - lowerLeft.x), 0.5 * (upperRight.y - lowerLeft.y) };
  return rectangle_t{ width, height, pos };
}

void ponomarev::Rectangle::move(point_t destination)
{
  rectangle_t frame = getFrameRect();
  double moveX = destination.x - frame.pos.x;
  double moveY = destination.y - frame.pos.y;
  lowerLeft.x += moveX;
  lowerLeft.y += moveY;
  upperRight.x += moveX;
  upperRight.y += moveY;
}

void ponomarev::Rectangle::move(double moveX, double moveY)
{
  lowerLeft.x += moveX;
  lowerLeft.y += moveY;
  upperRight.x += moveX;
  upperRight.y += moveY;
}

void ponomarev::Rectangle::scale(point_t pos, double coefficient)
{
  lowerLeft.x *= coefficient;
  lowerLeft.y *= coefficient;
  upperRight.x *= coefficient;
  upperRight.y *= coefficient;
}
