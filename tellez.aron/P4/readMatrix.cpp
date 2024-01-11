#include "readMatrix.hpp"
#include <algorithm>
#include <fstream>

size_t readMatrix(std::istream& in, size_t* matrix, size_t size, size_t toRead)
{
  for (size_t i = 0; i < std::min(toRead, size); ++i)
  {
    if (!(in >> matrix[i]))
    {
       return i;
    }
  }
  return std::min(toRead, size);
}
