#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace smolyakov
{
  struct point_t
  {
    double x = 0;
    double y = 0;
  };

  struct rectangle_t
  {
    point_t pos;
    double width;
    double height;
  };
}

#endif
