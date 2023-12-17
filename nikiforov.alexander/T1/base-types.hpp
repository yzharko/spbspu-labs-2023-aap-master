#ifndef BASE_TYPE_HPP
#define BASE_TYPE_HPP
#include <iostream>

struct point_t
{
  double x = 0;
  double y = 0;
};

struct rectangle_t
{
  double width = 0;
  double height = 0;
  point_t pos = {0,0};
};

#endif