#include "diamond.hpp"
#include "base-types.hpp"

khomichenko::Diamond::Diamond(point_t first, point_t second, point_t third):
  first(first),
  second(second),
  third(third)
{}

double khomichenko::Diamond::getArea()
{
  return 2*(second.y - third.y)*(third.x - first.x);
}

khomichenko::rectangle_t khomichenko::Diamond::getFrameRect()
{
  double width = 2*(third.x - first.x);
  double height = 2*(second.y - third.y);
  return {width, height, third};
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
  khomichenko::Diamond::move(delta.x, delta.y);
}

void khomichenko::Diamond::scale(double k)
{
  double height = (second.y - third.y) * k;
  double widht = (third.x - first.x) * k;
  first.x = third.x - widht;
  second.y = third.y + height;
}
