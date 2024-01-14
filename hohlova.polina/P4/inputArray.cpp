#include "inputArray.hpp"
#include <istream>

size_t hohlova::inputArray(std::istream& input, int* matrix, size_t sizem)
{
  for (size_t i = 0; i < sizem; i++)
  {
    input >> matrix[i];
    if (!input)
    {
      return i;
    }
  }
  return sizem;
}
