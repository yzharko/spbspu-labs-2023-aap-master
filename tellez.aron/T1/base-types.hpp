#ifndef T1_BASE_TYPES_H
#define T1_BASE_TYPES_H
#include <cmath>

namespace tellez
{
  struct point_t
  {
    double x;
    double y;
  };
  struct rectangle_t
  {
    point_t pos;
    double width;
    double height;
  };
  struct scale_t
  {
    point_t pos;
    double ds;
  };
  const double PI = std::acos(-1.0);
}
#endif
