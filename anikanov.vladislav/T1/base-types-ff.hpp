#ifndef BASE_TYPES_FF_HPP
#define BASE_TYPES_FF_HPP

#include "base-types.hpp"

namespace anikanov {
  struct point_t;

  struct rectangle_t;
  point_t operator+(point_t&& lhs, point_t&&rhs);

  std::istream &operator>>(std::istream &, point_t &);

  std::ostream &operator<<(std::ostream &, const point_t &);

  std::ostream &operator<<(std::ostream &, const rectangle_t &);
}

#endif
