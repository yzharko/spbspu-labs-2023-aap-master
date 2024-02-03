#include "geometricalMethods.hpp"
#include "cmath"

double miheev::findDist(point_t A, point_t B)
{
  double dx = A.x - B.x;
  double dy = A.y - B.y;
  return std::sqrt(std::pow(dx, 2) + std::pow(dy, 2));
}

void miheev::movePoint(point_t& p, double dx, double dy)
{
  p.x += dx;
  p.y += dy;
}
