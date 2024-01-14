#include "sumArrays.hpp"

void jirkov::sumArrays(const int* matrix1, const int* matrix2, int* result, int rows, int cols)
{
  for (int i = 0; i < rows * cols; i++)
  {
    result[i] = matrix1[i] + matrix2[i];
  }
}
