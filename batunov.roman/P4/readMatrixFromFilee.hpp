#ifndef READ_MATRIX_FROM_FILEE_HPP
#define READ_MATRIX_FROM_FILEE_HPP
#include <fstream>
#include <string>

namespace batunov
{
  int** readMatrixFromFilee(const std::string& filename, int& rows, int& cols);
}

#endif
