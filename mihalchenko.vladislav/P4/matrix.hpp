#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>

namespace mihalchenko
{
  float* createMatrix(float* rowsPtrs, size_t rows, size_t cols);
  void freeMatrix(float* matrix);
}
#endif
