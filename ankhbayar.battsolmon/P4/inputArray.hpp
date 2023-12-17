#ifndef INPUTARRAY_HPP
#define INPUTARRAY_HPP
#include <iosfwd>

namespace tsomo
{
  size_t inputMatrix(std::istream& in, int* matrix, size_t s, size_t toRead);
}

#endif
