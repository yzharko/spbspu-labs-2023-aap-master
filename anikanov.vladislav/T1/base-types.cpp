#include "base-types.hpp"
#include <iostream>
#include <iomanip>

using namespace anikanov;

point_t::point_t()
{
  x = 0;
  y = 0;
}

point_t::point_t(float x, float y)
{
  this->x = x;
  this->y = y;
}

point_t::point_t(const point_t &other)
{
  x = other.x;
  y = other.y;
}

point_t &point_t::operator=(const point_t another_point)
{
  if (this == &another_point) {
    return *this;
  }
  this->x = another_point.x;
  this->y = another_point.y;
  return *this;
}

namespace anikanov {
  std::ostream &operator<<(std::ostream &out, const point_t &point)
  {
    out << std::fixed << std::setprecision(1);
    out << point.x << " " << point.y;
    return out;
  }

  std::istream &operator>>(std::istream &in, point_t &point)
  {
    if (!(in >> point.x >> point.y)) {
      if (std::cin.eof()) {
        throw std::logic_error("EOF");
      }
      throw std::overflow_error("Invalid Input");
    }
    return in;
  }
}

point_t &point_t::operator+(point_t another_point)
{
  x += another_point.x;
  y += another_point.y;
  return *this;
}

rectangle_t::rectangle_t()
{
  this->pos = point_t(0, 0);
  this->width = 0;
  this->height = 0;
}

rectangle_t::rectangle_t(point_t pos, float width, float height)
{
  this->pos = pos;
  this->width = width;
  this->height = height;
}

namespace anikanov {
  std::ostream &operator<<(std::ostream &out, const rectangle_t &rec)
  {
    point_t point(rec.pos.x - rec.width / 2.0f, rec.pos.y - rec.height / 2.0f);
    out << std::fixed << std::setprecision(1);
    out << point.x << " " << point.y;
    out << " ";
    point = point_t(rec.pos.x + rec.width / 2.0f, rec.pos.y + rec.height / 2.0f);
    out << point.x << " " << point.y;
    return out;
  }
}
