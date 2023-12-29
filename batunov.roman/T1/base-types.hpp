#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace batunov
{
  struct point_t
  {
    double x = 0;
    double y = 0;
  };
  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };
}

#endif
