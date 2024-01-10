#include "base-types.hpp"
#include <iostream>

point_t::point_t(double x, double y) : x_(x), y_(y)
{
  std::cout << x_ << "; " << y_ << std::endl;
}

rectangle_t::rectangle_t(point_t pos, double width, double height) : width_(width), height_(height), pos_(pos)
{
}
