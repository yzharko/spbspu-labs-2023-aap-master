#include "InputArray.hpp"
#include <fstream>
#include <algorithm>

size_t sukacheva::inputMatrix(std::istream& in, int* matrix, size_t s, size_t toRead)
{
  for (size_t i = 0; i < std::min(toRead, s); ++i)
  {
    if (!(in >> matrix[i]))
    {
      return i;
    }
  }
  return std::min(toRead, s);
}
