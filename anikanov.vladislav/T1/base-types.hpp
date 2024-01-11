#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

#include <iosfwd>

namespace anikanov {
  struct point_t    {
    double x;
    double y;

    explicit point_t();

    explicit point_t(float x, float y);

    point_t(const point_t &);

    point_t &operator=(point_t another_point);

    point_t &operator+(point_t another_point);

    friend std::istream &operator>>(std::istream &, point_t &);
//
    friend std::ostream &operator<<(std::ostream &, const point_t &);
  };

  struct rectangle_t {
    double width;
    double height;
    point_t pos;

    explicit rectangle_t();

    explicit rectangle_t(point_t pos, float width, float height);

    friend std::ostream &operator<<(std::ostream &, const rectangle_t &);
  };
}

#endif
