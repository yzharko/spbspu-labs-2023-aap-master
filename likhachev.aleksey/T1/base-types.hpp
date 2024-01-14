#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
#include <iostream>

namespace likhachev
{
  struct point_t {
  public:
    double x, y;
    void operator()(double newNumber);
    point_t operator+(const point_t& rhs);
    bool operator==(const point_t& rhs);
    point_t operator-(const point_t& rhs);
    point_t& operator+=(const point_t& rhs);
    point_t& operator-=(const point_t& rhs);
  };

  struct rectangle_t {
  public:
    double width, height;
    point_t pos;
  };
}
#endif
