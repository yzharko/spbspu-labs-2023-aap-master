#include "inputArray.hpp"
#include <istream>

size_t ponomarev::inputArray(std::istream & in, int * matrix, size_t lenArray)
{
  for (size_t i = 0; i < lenArray; i++)
  {
    if (!(in >> matrix[i]))
    {
      return i;
    }
  }
  return lenArray;
}

