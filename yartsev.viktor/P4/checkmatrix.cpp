#include <fstream>
#include "checkmatrix.hpp"

bool yartsev::isLowerTriangularMatrix(int * matrix, int cols, int rows)
{
  if (rows != cols) {
    return false;
  }
  bool isZero = true;
  for (int i = 0; i < rows && isZero; i++) {
    for (int j = 0; j < cols && isZero; j++) {
      if (i < j) {
        isZero = (isZero && matrix[i * rows + j] == 0);
      }
    }
  }
  return isZero;
}