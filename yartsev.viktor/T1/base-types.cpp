#include "base-types.hpp"

yartsev::point_t::point_t():
  x_(0),
  y_(0)
{}

yartsev::point_t::point_t(double x, double y):
  x_(x),
  y_(y)
{}

yartsev::rectangle_t::rectangle_t():
  width_(0),
  height_(0),
  pos_()
{}

yartsev::rectangle_t::rectangle_t(double width, double height, point_t pos):
  width_(width),
  height_(height),
  pos_(pos)
{}
