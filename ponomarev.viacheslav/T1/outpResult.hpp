#ifndef OUTP_RESULT_HPP
#define OUTP_RESULT_HPP
#include "rectangle.hpp"
#include "base-types.hpp"
#include "shape.hpp"
#include <iostream>
#include <cstddef>
#include <iomanip>

namespace ponomarev
{
  void outpResult(const ponomarev::Shape * const * const figures, const size_t & countOfFigures);
}

#endif
