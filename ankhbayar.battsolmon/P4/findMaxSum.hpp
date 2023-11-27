#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <cstddef>

namespace ankhbayar
{
  size_t MaxSideDiagonal(int* matrix, size_t cols);
  bool upperTriangularMatrix(int* matrix, size_t cols, size_t rows);
}
#endif
