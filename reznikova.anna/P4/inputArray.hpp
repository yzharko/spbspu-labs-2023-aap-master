#ifndef INPUTARRAY_hpp
#define INPUTARRAY_hpp
#include <iosfwd>

namespace reznikova
{
  size_t inputArray(std::istream & in, int * m, size_t s, size_t toRead);
}

#endif
