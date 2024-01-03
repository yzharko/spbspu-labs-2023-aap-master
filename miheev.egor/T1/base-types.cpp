#include "base-types.hpp"
#include <cmath>

miheev::point_t::point_t():
  x_(0),
  y_(0)
{}

miheev::point_t::point_t(double x, double y):
  x_(x),
  y_(y)
{}

double miheev::point_t::distTo(miheev::point_t p) const
{
  double dx = x_ - p.x_;
  double dy = y_ - p.y_;

  return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
}

miheev::point_t miheev::point_t::findMiddle(point_t rhs) const
{
  double middleX = (x_ + rhs.x_) / 2;
  double middleY = (y_ + rhs.y_) / 2;
  return miheev::point_t(middleX, middleY);
}

void miheev::point_t::move(double dx, double dy)
{
  x_ += dx;
  y_ += dy;
}

miheev::rectangle_t::rectangle_t(point_t pos, double width, double height):
  width_(width),
  height_(height),
  pos_(pos)
{}