#include "rectangle.hpp"

using namespace ponomarev;

Rectangle::Rectangle(const point_t lowerLeft, const point_t upperRight):
  lowerLeft(lowerLeft),
  upperRight(upperRight)
{
  if (lowerLeft.x >= upperRight.x || lowerLeft.y >= upperRight.y)
  {
    throw std::invalid_argument("Rectangle is wrong");
  }
}

double Rectangle::getArea()
{
  rectangle_t frame = getFrameRect();
  return frame.width * frame.height;
}

rectangle_t Rectangle::getFrameRect()
{
  double width = upperRight.x - lowerLeft.x;
  double height = upperRight.y - lowerLeft.y;
  point_t center = { 0.5 * (upperRight.x - lowerLeft.x), 0.5 * (upperRight.y - lowerLeft.y) };
  return { width, height, center };
}

void Rectangle::move(const point_t & newCenter)
{
  rectangle_t frame = getFrameRect();
  double offsetX = newCenter.x - frame.center.x;
  double offsetY = newCenter.y - frame.center.y;
  move(offsetX, offsetY);
}

void Rectangle::move(const double & offsetX, const double & offsetY)
{
  lowerLeft.x += offsetX;
  lowerLeft.y += offsetY;
  upperRight.x += offsetX;
  upperRight.y += offsetY;
}

void Rectangle::scale(double k)
{
  point_t center = { 0.5 * (upperRight.x - lowerLeft.x), 0.5 * (upperRight.y - lowerLeft.y) };
  lowerLeft.x = (lowerLeft.x - center.x) * k + center.x;
  lowerLeft.y = (lowerLeft.y - center.y) * k + center.y;
  upperRight.x = (upperRight.x - center.x) * k + center.x;
  upperRight.y = (upperRight.y - center.y) * k + center.y;
}
