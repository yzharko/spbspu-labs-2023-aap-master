#ifndef PARSE_FIGURE_HPP
#define PARSE_FIGURE_CPP
#include "shape.hpp"
#include <string>
#include <iostream>
#include <cstddef>

namespace shagieva
{
  void parseFigure(std::string figureType, std::istream & input, Shape ** shapes, size_t & shapeCount);
};

#endif
