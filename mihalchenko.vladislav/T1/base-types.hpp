#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

struct point_t
{
  double x_ = 0.0;
  double y_ = 0.0;
  point_t(double x, double y);
};

struct rectangle_t
{
  point_t pos_;
  double width_ = 0.0;
  double height_ = 0.0;
  rectangle_t(point_t pos, double width, double height);
};
#endif
