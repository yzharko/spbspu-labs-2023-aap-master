#ifndef BASE_TYPE_HPP
#define BASE_TYPE_HPP
#include <iostream>

struct point_t
{
  double x;
  double y;
};

struct rectangle_t
{
  double width;
  double height;
  point_t pos;
};

#endif
