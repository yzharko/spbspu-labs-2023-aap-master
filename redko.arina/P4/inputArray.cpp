#include "inputArray.hpp"
#include <fstream>

size_t redko::inputArray(std::ifstream & in, int * matrix, size_t matrixSize)
{
  int elemCount = 0;
  for (size_t i = 0; i < matrixSize; ++i)
  {
    if (in >> matrix[i])
    {
      elemCount++;
    }
  }
  return elemCount;
}
