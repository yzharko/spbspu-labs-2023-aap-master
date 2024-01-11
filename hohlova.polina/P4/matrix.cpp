#include "matrix.hpp"
#include <iosfwd>

size_t hohlova::countStrings(const int* matrix, size_t rows, size_t cols)
{
  size_t counter = 0;
  for (size_t i = 1; i < cols; i++)
  {
    for (size_t j = 1; j < rows; j++)
    {
      if (matrix[i + rows + j - 1] == matrix[i * rows + j - 1])
      {
        ++counter;
      }
    }
  }
  return rows - counter;
}
