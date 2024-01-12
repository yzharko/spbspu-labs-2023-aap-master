#ifndef RESOURCE_FUNCTIONS_HPP
#define RESOURCE_FUNCTIONS_HPP
#include "shape.hpp"
#include <cstddef>

namespace shagieva
{
  void increaseData(Shape ** shapes, size_t & capacity, const size_t & shapeCount);
  void deleteData(Shape ** shapes, const size_t & shapeCount);
}

#endif
