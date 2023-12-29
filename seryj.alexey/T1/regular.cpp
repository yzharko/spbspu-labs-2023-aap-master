#include "regular.hpp"
#include <exception>
#include <cmath>
Regular::Regular(point_t a, point_t b, point_t c)
{
  double radius1 = sqrt(pow(b.x + a.x, 2) + pow(b.y + c.y, 2));
  double radius2 = sqrt(pow(c.x + b.x, 2) + pow(c.y + b.y, 2));
  double radius3 = sqrt(pow(c.x + a.x, 2) + pow(c.y + a.y, 2));
  double side = fmin(radius1, fmin(radius2, radius3)) * 2;
  square_ = Square({ a.x - side / 2, a.y - side / 2 }, side);
}
double Regular::getArea()
{
  return square_.getArea();
}
rectangle_t Regular::getFrameRect()
{
  return square_.getFrameRect();
}
void Regular::move(point_t t)
{
  square_.move(t);
}
void Regular::move(double x, double y)
{
  square_.move(x, y);
}
void Regular::scale(double k)
{
  square_.scale(k);
}
