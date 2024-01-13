#ifndef SET_FIGURES_HPP
#define SET_FIGURES_HPP
#include <iostream>
#include "shape.hpp"

namespace reznikova
{
  Shape * setRectangle(bool & ifNoErrors);
  Shape * setRing(bool & ifNoErrors);
  Shape * setRegular(bool & ifNoErrors);
}

#endif
