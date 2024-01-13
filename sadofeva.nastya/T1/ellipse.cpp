#include <stdexcept>
#include "base-tapes.hpp"
#include "ellipse.hpp"

double sadofeva::Ellipse::getArea() const
{
  return r1 * r2 * 3.14;
}

sadofeva::Rectangle_t sadofeva::Ellipse::getFrameRect() const
{
  return rectangle_t;
}

void sadofeva::Ellipse::move(double _x. double _y)
{
  rectangle_t.pos.x = rectangle_t.pos.x + _x;
  rectangle_t.pos.y = rectangle_t.pos.y + _y;
}

void sadofeva::Ellipse::move(Point_t point)
{
  rectangle_t.pos = point;
}

sadofeva::Ellipse::Ellipse(Point_t point, double r_1, double r_2):
  rectangle_t({{point.x , point.y}, r_1 * 2.0 , r_2 * 2.0}),
  r1(r_1),
  r2(r_2)
{
  if (r1 <= 0.0 || r2 <= 0.0)
  {
    throw std::logic_error("not size ellipse");
  }
}
