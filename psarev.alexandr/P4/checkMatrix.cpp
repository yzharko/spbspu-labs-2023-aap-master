#include "checkMatrix.hpp"
#include <fstream>

bool psarev::isTriMatrix(int* matrix, int rows, int cols)
{
  for (int i = 1; i < rows; i++) {
    for (int k = 0; k < i; k++) {
      if (matrix[i * cols + k] != 0) {
        return false;
      }
    }
  }
  return true;
}
