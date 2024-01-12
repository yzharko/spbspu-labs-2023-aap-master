#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "base-types.hpp"
#include <string>

namespace miheev
{
  void printCurrentState(double sumArea, rectangle_t* rects, size_t rectsAmount);
  bool validateTriangle(point_t p1, point_t p2, point_t p3);
}

#endif
