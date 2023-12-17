#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t {
private:
  double x, y;
};

struct rectangle_t{
  double width, height;
  point_t pos;
};

#endif
