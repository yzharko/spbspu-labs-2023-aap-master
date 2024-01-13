#ifndef RESOURCE_FUNCTIONS_HPP
#define RESOURCE_FUNCTIONS_HPP
#include <cstddef>
#include "shape.hpp"

namespace shagieva
{
  void increaseResource(Shape ** shapes, size_t & capacity, const size_t & shapeCount);
  void clearResource(Shape ** shapes, const size_t & shapeCount);
}

#endif
