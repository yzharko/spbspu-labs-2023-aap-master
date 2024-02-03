#include "inputArray.hpp"
#include <istream>

size_t doroshenko::inputArray(std::istream& input, int* Matrix, size_t sizeMatrix)
{
  for (size_t k = 0; k < sizeMatrix; k++)
  {
    input >> Matrix[k];
    if (!input)
    {
      return k;
    }
  }
  return sizeMatrix;
}
