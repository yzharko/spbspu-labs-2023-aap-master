#include "inputArray.hpp"
#include <algorithm>
#include <iostream>

size_t malanin::inputArray(std::istream & in, int * matrix, size_t s, size_t toRead)
{
  for (size_t i = 0; i < std::min(toread, s); ++i)
  {
    if (!(in >> matrix[i]))
    {
      return i;
    }
  }
  return std::min(toRead, s)
}
