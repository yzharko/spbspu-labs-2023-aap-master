#include "base-types.hpp"
#include <cmath>

double miheev::point_t::distTo(miheev::point_t p)
{
  double dx = x - p.x;
  double dy = y - p.y;

  return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
}