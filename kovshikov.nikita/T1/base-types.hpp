#ifndef BASETYPES_HPP
#define BASETYPES_HPP

struct point_t
{
  double x = 0;
  double y = 0;
};
struct rectangle_t
{
  double width = 0;
  double height = 0;
  point_t pos;
  pos.x = height / 2;
  pos.y = width / 2;
};

#endif
