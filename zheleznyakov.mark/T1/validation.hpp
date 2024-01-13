#ifndef VALIDATION_HPP
#define VALIDATION_HPP
#include <cmath>
#include "base-types.hpp"

namespace zheleznyakov
{
  bool checkIsRighrTriangle(point_t p1, point_t p2, point_t p3);
  bool checkIsRectangleCoords(double x1, double y1, double x2, double y2);
}
#endif
