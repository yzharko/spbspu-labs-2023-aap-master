#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t
{
  double x = 0;
  double y = 0;
};

struct rectangle_t
{
  double width = 0;
  double heigt = 0;
  point_t pos = { 0,0 };
};
#endif
