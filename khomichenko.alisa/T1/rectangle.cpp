#include "rectangle.hpp"
#include "base-types.hpp"

khomichenko::Rectangle::Rectangle(point_t leftBottom, point_t rightTop):
  leftBottom(leftBottom),
  rightTop(rightTop)
{}

double khomichenko::Rectangle::getArea()
{
  double width = rightTop.x - leftBottom.x;
  double height = rightTop.y - leftBottom.y;
  return width*height;
}

khomichenko::rectangle_t khomichenko::Rectangle::getFrameRect()
{
  point_t pos = { 0.5 * (rightTop.x + leftBottom.x), 0.5 * (rightTop.y + leftBottom.y)};
  double width = rightTop.x - leftBottom.x;
  double height = -rightTop.y + leftBottom.y;
  return {width, height, pos};
}

void khomichenko::Rectangle::move(double dX, double dY)
{
  leftBottom.x+=dX;
  leftBottom.y+=dY;
  rightTop.x+=dX;
  rightTop.y+=dY;
}

void khomichenko::Rectangle::move(point_t newPos)
{
  rectangle_t rect = getFrameRect();
  point_t delta = {newPos.x - rect.pos.x, newPos.y - rect.pos.y};
  khomichenko::Rectangle::move(delta.x, delta.y);
}

void khomichenko::Rectangle::scale(double k)
{
  point_t pos = { 0.5 * (rightTop.x + leftBottom.x), 0.5 * (rightTop.y + leftBottom.y)};
  point_t changed = {0.5 * (rightTop.x - leftBottom.x),0.5 * (rightTop.y - leftBottom.y)};
  point_t newCoordinates = {changed.x * k, changed.y * k};
  rightTop.x = pos.x + newCoordinates.x;
  leftBottom.x = pos.x - newCoordinates.x;
  rightTop.y = pos.y + newCoordinates.y;
  leftBottom.y = pos.y - newCoordinates.y;
}
