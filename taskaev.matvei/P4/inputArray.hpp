#ifndef INPUTARRAY_HPP
#define INPUTARRAY_HPP
#include <iosfwd>

namespace taskaev
{
  size_t inputArray(std::istream & in, int * m, size_t s, size_t toRead);
}
#endif
