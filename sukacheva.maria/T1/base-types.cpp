#include "base-types.hpp"

sukacheva::point_t::point_t(double x, double y):
  x_(x),
  y_(y)
{}

sukacheva::rectangle_t::rectangle_t(double width, double height, point_t pos):
  width_(width),
  height_(height),
  pos_(pos)
{}
