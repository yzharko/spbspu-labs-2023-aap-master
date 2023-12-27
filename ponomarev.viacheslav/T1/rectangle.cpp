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

void ponomarev::Rectangle::move(point_t toThePoint)
{
  rectangle_t frame = getFrameRect();
  double aX = destination.x - frame.pos.x;
  double aY = destination.y - frame.pos.y;
  lowerLeft.x += aX;
  lowerLeft.y += aY;
  upperRight.x += aX;
  upperRight.y += aY;
}

void ponomarev::Rectangle::move(double aX, double aY)
{
  lowerLeft.x += aX;
  lowerLeft.y += aY;
  upperRight.x += aX;
  upperRight.y += aY;
}

void ponomarev::Rectangle::scale(point_t pos, double k)
{
  lowerLeft.x *= k;
  lowerLeft.y *= k;
  upperRight.x *= k;
  upperRight.y *= k;
}
