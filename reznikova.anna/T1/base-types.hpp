#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
#include <stdio.h>

struct point_t
{
  point_t(double X, double Y);
  double x;
  double y;
};

struct rectangle_t
{
  rectangle_t(double w, double h, point_t p);
  double width;
  double height;
  point_t pos;
};

#endif
