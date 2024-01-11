#include "base-types.hpp"

sukacheva::point_t::point_t(double x_, double y_):
  x(x_),
  y(y_)
{}

sukacheva::rectangle_t::rectangle_t(double width_, double height_, point_t pos_):
  width(width_),
  height(height_),
  pos(pos_)
{}
