#include "base-types.hpp"

likhachev::point_t likhachev::point_t::operator+(const point_t& rhs)
{
  likhachev::point_t result;
  result.x = x + rhs.x;
  result.y = y + rhs.y;
  return result;
}

likhachev::point_t likhachev::point_t::operator-(const point_t& rhs)
{
  likhachev::point_t result;
  result.x = x - rhs.x;
  result.y = y - rhs.y;
  return result;
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
