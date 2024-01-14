#include "base-types.hpp"
#include <iostream>

likhachev::point_t::point_t(double newX, double newY):
  x(newX),
  y(newY)
{}

likhachev::point_t likhachev::point_t::operator+(const point_t& rhs)
{
  return likhachev::point_t(x + rhs.x, y + rhs.y);
}

likhachev::point_t likhachev::point_t::operator-(const point_t& rhs)
{
  return likhachev::point_t(x - rhs.x, y - rhs.y);
}

bool likhachev::point_t::operator==(const point_t& rhs)
{
  if (x == rhs.x && y == rhs.y) {
    return true;
  }

  return false;
}

likhachev::point_t& likhachev::point_t::operator+=(const point_t& rhs)
{
  x += rhs.x;
  y += rhs.y;
  return *this;
}

likhachev::point_t& likhachev::point_t::operator-=(const point_t& rhs)
{
  x -= rhs.x;
  y -= rhs.y;
  return *this;
}

likhachev::rectangle_t::rectangle_t(double newWidth, double newHeight, likhachev::point_t newPos):
  width(newWidth),
  height(newHeight),
  pos(newPos)
{}
