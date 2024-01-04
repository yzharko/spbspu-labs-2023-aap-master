#ifndef BASE_TYPE_HPP
#define BASE_TYPE_HPP

namespace khomichenko
{
  struct point_t
  {
    double x;
    double y;
  };

  struct rectangle_t
  {
    point_t leftBottom;
    point_t rightTop;
  };
}

#endif
