#ifndef INP_FIGURE_HPP
#define INP_FIGURE_HPP
#include <string>
#include <iostream>
#include <cstddef>
#include "shape.hpp"

namespace ponomarev
{
  void inpFigure(std::string nameOfFigure, std::istream & input, Shape ** figures, size_t & countOfFigures);
}

#endif
