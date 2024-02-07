#ifndef SHAPE_PARSING_HPP
#define SHAPE_PARSING_HPP
#include <cstddef>
#include <string>
#include <iostream>
#include "shape.hpp"

namespace smolyakov
{
  bool parseShape(std::istream& stream, std::string type, Shape** shapes, size_t shapeCount);
}

#endif
