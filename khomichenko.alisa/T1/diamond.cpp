#include "diamond.hpp"

khomichenko::Diamond::Diamond(point_t first, point_t second, point_t third):
  first(first),
  second(second),
  third(third)
{}

double khomichenko::Diamond::getArea()
{
  return (second.y - third.y)*(third.x - first.x);
}

rectangle_t khomichenko::Diamond::getFrameRect()
{
  point_t topX = third.x + (third.x-first.x);
  double topY = second.y;
  point_t botX = first.x;
  double botY = third.y - (second.y - third.y);
  return rectangle_t {{botX, botY}, {topX, topY}};
}

void khomichenko::Diamond::move(double dX, double dY)
{
  third.x+=dX;
  third.y+=dY;
  first.x+=dX;
  first.y+=dY;
  second.x+=dX;
  second.y+=dY;
}

void khomichenko::Diamond::move(point_t dPos)
{
  point_t delta = {third.x-dPos.x, third.y - dPos.y};
  khomichenko::Rectangle::move(delta.x, delta.y);
}

void khomichenko::Diamond::scale(point_t pos, double k)
{
  double height = (second.y - third.y) * k;
  double widht = (third.x - first.x) * k;
  first.x = third.x - widht;
  second.y = third.y + height;
}
