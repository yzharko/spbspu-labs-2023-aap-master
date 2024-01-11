#include <algorithm>
#include "complexquad.hpp"
#include "helpfunctions.hpp"

sadofeva::Complexquad::Complexquad(Point_t& point1, Point_t& point2, Point_t& point3, Point_t& point4)
{
  _p1 = (point1);
  _p2 = (point2);
  _p3 = (point3);
  _p4 = (point4);
}
double sadofeva::Complexquad::getArea()
{
  Point_t center = point_intersection(_p1, _p2, _p3, _p4);
}

void sadofeva::Complexquad::move(double _x, double _y)
{
  _p1.x += _x;
  _p1.y += _y;
  _p2.x += _x;
  _p2.y += _y;
  _p3.x += _x;
  _p3.y += _y;
  _p4.x += _x;
  _p4.y += _y;
}

void sadofeva::Complexquad::move(Point_t point)
{
  Point_t center = point_intersection(_p1, _p2, _p3, _p4);
  move(point.x - center.x, point.y - center.y);
}

sadofeva::Rectangle_t sadofeva::Complexquad::getFrameRect()
{
  double letfX = std::min(std::min(_p1.x, _p4.x), std::min(_p2.x, _p3.x);
}
