#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <cstddef>
#include "base-types.hpp"

namespace miheev
{
  void printCurrentState(double sumArea, rectangle_t* rects, size_t rectsAmount);
  bool validateTriangle(point_t p1, point_t p2, point_t p3);
  bool validateParallelogram(point_t A, point_t B, point_t C);
}

#endif
