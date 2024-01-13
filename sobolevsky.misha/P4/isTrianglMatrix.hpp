#ifndef ISTRIANGLMATRIX_HPP
#define ISTRIANGLMATRIX_HPP
#include <fstream>

namespace sobolevsky
{
  void isTrianglMatrix(std::ofstream & out, const int * matrix, size_t rows, size_t cols);
}

#endif
