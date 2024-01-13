#ifndef READMATRIX_HPP
#define READMATRIX_HPP
#include <iosfwd>

namespace shapar
{
  size_t readMatrix(std::istream & in, int * matrix, size_t s, size_t toRead);
}

#endif
