#ifndef INPUTMATRIX_HPP
#define INPUTMATRIX_HPP
#include <cstddef>
#include <fstream>

namespace nikiforov {
  size_t inputMatrix(std::ifstream& in, int* ArrMatrix, size_t cap);
}

#endif
