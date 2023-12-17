#include "inputMatrix.hpp"
#include <istream>

size_t psarev::inputMatrix(std::istream& in, int* matrix, size_t cap)
{
  for (size_t i = 0; i < cap; i++) {
    if (!(in >> matrix[i])) {
      return i;
    }
  }
  return cap;
}
