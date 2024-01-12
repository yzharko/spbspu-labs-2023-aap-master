#ifndef DATA_FUNCTIONS_HPP
#define DATA_FUNCTIONS_HPP
#include "shape.hpp"
#include <string>
#include <iostream>
#include <cstddef>

namespace shagieva
{
  void parseFigure(std::string figureType, std::istream & input, Shape ** shapes, size_t & shapeCount);
  void printFramePoints(const Shape * const * const shapes, const size_t & shapeCount);
  void printTotalArea(const Shape * const * const shapes, const size_t & shapeCount);
}

#endif
