#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
#include <iostream>

namespace likhachev
{
  struct point_t {
  public:
    double x, y;
    
    point_t& operator+=(const point_t& rhs);
    point_t& operator-=(const point_t& rhs);
  };

  struct rectangle_t {
  public:
    double width, height;
    point_t pos;
  };

  
  point_t operator+(const point_t& firstRhs, const point_t& secondRhs);
  point_t operator-(const point_t& decrRhs, const point_t& subtrRhs);
  bool operator==(const point_t& firstRhs, const point_t& secondRhs);
}
#endif
