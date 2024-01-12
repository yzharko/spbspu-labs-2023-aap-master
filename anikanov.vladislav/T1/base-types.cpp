#include "base-types.hpp"
#include "base-types-ff.hpp"
#include <iostream>
#include <iomanip>

using namespace anikanov;


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

namespace anikanov {
  std::ostream &operator<<(std::ostream &out, const rectangle_t &rec)
  {
    point_t point{0, 0};
    point.x = rec.pos.x - rec.width / 2.0;
    point.y = rec.pos.y - rec.height / 2.0;
    out << std::fixed << std::setprecision(1);
    out << point.x << " " << point.y;
    out << " ";
    point.x = rec.pos.x + rec.width / 2.0,
    point.y = rec.pos.y + rec.height / 2.0;
    out << point.x << " " << point.y;
    return out;
  }
}
