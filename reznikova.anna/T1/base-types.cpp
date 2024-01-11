#include "base-types.hpp"

reznikova::point_t::point_t(double X, double Y):
  x(X),
  y(Y)
{}

reznikova::rectangle_t::rectangle_t(double w, double h, point_t p):
  width(w),
  height(h),
  pos(p),
{}
