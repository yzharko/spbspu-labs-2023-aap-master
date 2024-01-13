#ifndef INPUTARRAY_HPP
#define INPUTARRAY_HPP
#include <fstream>

namespace sadofeva
{
  size_t input_ar(std::ifstream& file, int* values, size_t sz_M);
}

#endif
