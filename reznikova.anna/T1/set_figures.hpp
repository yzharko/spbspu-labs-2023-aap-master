#ifndef SET_FIGURES_HPP
#define SET_FIGURES_HPP
#include <iostream>
#include <string>
#include "shape.hpp"

namespace reznikova
{
  Shape * setRectangle(std::string& line, bool & ifNoErrors);
  Shape * setRing(std::string& line, bool & ifNoErrors);
  Shape * setRegular(std::string& line, bool & ifNoErrors);
}

#endif
