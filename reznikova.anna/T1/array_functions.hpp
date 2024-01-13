#ifndef ARRAY_FUNCTIONS_HPP
#define ARRAY_FUNCTIONS_HPP
#include <iostream>
#include "shape.hpp"

namespace reznikova
{
  void freeArray(Shape ** figures, const int stored);
  void outputSum(Shape ** figures, const int stored);
  void outputFrame(rectangle_t frame_rect);
}

#endif
