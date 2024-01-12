#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <iosfwd>

namespace anikanov {
  struct point_t {
    double x;
    double y;

    point_t &operator=(point_t another_point);

    point_t &operator+(point_t another_point);
  };

  struct rectangle_t {
    point_t pos;
    double width;
    double height;
  };
}

#endif
