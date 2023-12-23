#ifndef BASE_TYPE_HPP
#define BASE_TYPE_HPP

namespace khomichenko
{
  struct point_t
  {
    size_t x;
    size_t y;
  };

  struct rectangle_t
  {
    size_t width;
    size_t height;
    point_t pos;
  };
}

#endif
