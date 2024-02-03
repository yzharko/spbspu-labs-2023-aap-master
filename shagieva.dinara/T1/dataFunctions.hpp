#ifndef DATA_FUNCTIONS_HPP
#define DATA_FUNCTIONS_HPP
#include <string>
#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace shagieva
{
  void parseFigure(std::string figureType, std::istream & input, Shape ** shapes, size_t & shapeCount);
  void printTotalArea(const Shape * const * const shapes, const size_t & shapeCount);
  void printFramePoints(const Shape * const * const shapes, const size_t & shapeCount);
}

#endif
