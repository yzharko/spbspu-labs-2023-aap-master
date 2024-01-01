#include "base-types.hpp"

point_t::point_t(double X, double Y):
  x(X),
  y(Y)
{}

rectangle_t::rectangle_t(double w, double h, point_t p):
  width(w),
  height(h),
  pos(p)
{}
