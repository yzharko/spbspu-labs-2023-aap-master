#ifndef BASETYPES_HPP
#define BASETYPES_HPP

struct point_t
{
  point_t(double x, double y);
  double X;
  double Y;
};

struct rectangle_t
{
  rectangle_t(double width, double height, point_t pos);
  double width_;
  double height_;
  point_t pos_;
};

#endif

