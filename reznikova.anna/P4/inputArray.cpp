#include "inputArray.hpp"
#include <algorithm>
#include <fstream>

size_t reznikova::inputArray(std::istream & in, int * m, size_t s, size_t toRead)
{
  for (size_t i = 0; i < std::min(toRead, s); ++i)
  {
    if (!(in >> m[i]))
    {
      return i;
    }
  }
  return std::min(toRead, s);
}
