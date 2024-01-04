#include "rectangle.hpp"

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

rectangle_t khomichenko::Rectangle::getFrameRect()

{
Rectangle* rectangle1 = new Rectangle (leftBottom, rightTop);
return rectangle1;
}

/*/void khomichenko::Rectangle::move(double dX, double dY)
{
  point_t pos = { 0.5 * (rigtTop.x + leftBottom.x), 0.5 * (rightTop.y + leftBottom.y) };
  pos.x+=dX;
  pos.y+=dY;
  leftBottom.x+=dX;
  leftBottom.y+=dY;
  rightTop.x+=dX;
  rightTop.y+=dY;
}

//void khomichenko::Rectangle::move(point_t dPos)
{
  rectangle_t rect = getFrameRect();
  point_t delta = {dPos.x - rect.pos.x, dPos.y - rect.pos.y};
  khomichenko::Rectangle::move(delta.x, delta.y);
}

//void khomichenko::Rectangle::scale(point_t pos, double k)
{
  point_t changed = {0.5 * (rightTop.x - leftBottom.x),0.5 * (rightTop.y - leftBottom.y)};
  point_t newCoordinates = {changed.x * k, changed.y * k};
  rightTop.x = pos.x + newCoordinates.x;
  leftBottom.x = pos.x + newCoordinates.x;
  rightTop.y = pos.y + newCoordinates.y;
  leftBottom.y = pos.y + newCoordinates.y;
}
*/
