#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP
struct point_t
{
  double x_;
  double y_;
};
struct rectangle_t
{
  rectangle_t(double width, double height, point_t pos);
  double width_;
  double height_;
  point_t pos_;
};
#endif
