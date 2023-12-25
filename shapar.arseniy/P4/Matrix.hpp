#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <fstream>

namespace shapar
{
  bool matTriangle(int* matrix, size_t rows, size_t cols);
  size_t matCols(int* matrix, size_t rows, size_t cols);
  size_t matDiag(int* matrix, size_t rows, size_t cols);
}

#endif
