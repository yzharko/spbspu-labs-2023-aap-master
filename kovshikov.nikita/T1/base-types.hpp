#ifndef BASETYPES_HPP
#define BASETYPES_HPP

namespace kovshikov
{
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
  };
}

#endif
