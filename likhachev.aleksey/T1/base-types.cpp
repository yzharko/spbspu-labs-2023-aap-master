#include "base-types.hpp"

likhachev::point_t likhachev::operator+(const point_t& firstRhs, const point_t& secondRhs)
{
  likhachev::point_t result;
  result.x = firstRhs.x + secondRhs.x;
  result.y = firstRhs.y + secondRhs.y;
  return result;
}

likhachev::point_t likhachev::operator-(const point_t& decrRhs, const point_t& subtrRhs)
{
  likhachev::point_t result;
  result.x = decrRhs.x - subtrRhs.x;
  result.y = decrRhs.y - subtrRhs.y;
  return result;
}

bool likhachev::operator==(const point_t& firstRhs, const point_t& secondRhs)
{
  if (firstRhs.x == secondRhs.x && firstRhs.y == secondRhs.y) {
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
