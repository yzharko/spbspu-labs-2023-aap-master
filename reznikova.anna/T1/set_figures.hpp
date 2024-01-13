#ifndef SET_FIGURES_HPP
#define SET_FIGURES_HPP
#include <iostream>
#include "shape.hpp"

namespace reznikova
{
  Shape * setRectangle(std::istream & in, bool & ifNoErrors);
  Shape * setRing(std::istream & in, bool & ifNoErrors);
  Shape * setRegular(std::istream & in, bool & ifNoErrors);
}

#endif
