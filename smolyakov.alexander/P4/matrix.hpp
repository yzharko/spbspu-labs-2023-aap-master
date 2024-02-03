#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <iosfwd>

namespace LabP4
{
  void InputMatrixAsArray(std::ifstream &, int *, size_t, size_t);
  int MaxSumParallelToSDG(int *, size_t, size_t);
}

#endif
