#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
#include <stdio.h>

namespace reznikova
{
  struct point_t
  {
  public:
    point_t(double X, double Y);
    double x;
    double y;
  };

  struct rectangle_t
  {
  public:
    rectangle_t(double w, double h, point_t p);
    double width;
    double height;
    point_t pos;
  };
}

#endif
