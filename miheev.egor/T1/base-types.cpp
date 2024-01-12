#include "base-types.hpp"
#include <cmath>

miheev::point_t::point_t():
  x(0),
  y(0)
{}

miheev::point_t::point_t(double x, double y):
  x(x),
  y(y)
{}

double miheev::point_t::distTo(miheev::point_t p) const
{
  double dx = x - p.x;
  double dy = y - p.y;

  return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
}

miheev::point_t miheev::point_t::findMiddle(point_t rhs) const
{
  double middleX = (x + rhs.x) / 2;
  double middleY = (y + rhs.y) / 2;
  return miheev::point_t(middleX, middleY);
}

void miheev::point_t::move(double dx, double dy)
{
  x += dx;
  y += dy;
}

miheev::rectangle_t::rectangle_t():
  width(0),
  height(0),
  pos({0, 0})
{}

miheev::rectangle_t::rectangle_t(point_t pos, double width, double height):
  width(width),
  height(height),
  pos(pos)
{}