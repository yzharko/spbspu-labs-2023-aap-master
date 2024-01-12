#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include "base-types.hpp"
#include <string>

namespace miheev
{
  void printRect(rectangle_t rect);
  void printCurrentState(double sumArea, rectangle_t* rectangle_t, size_t rectsAmount);
  void printPoint(double x, double y);
}

#endif