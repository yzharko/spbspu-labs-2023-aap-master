#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace miheev
{
  struct point_t
  {
    double x;
    double y;
    distTo(point_t);
  };

  struct rectangle_t
  {
  private:
    double width;
    double height;
    point_t pos;
  };
}

#endif
