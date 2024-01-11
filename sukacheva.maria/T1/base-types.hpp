#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace sukacheva
{
  struct point_t
  {
    point_t(double x_, double y_);
    double x;
    double y;
  };

  struct rectangle_t
  {
    rectangle_t(double width_, double height_, point_t pos_);
    double width;
    double height;
    point_t pos;
  };
}
#endif
