#ifndef READ_MATRIX_FROM_FILE_HPP
#define READ_MATRIX_FROM_FILE_HPP
#include <fstream>
#include <string>

namespace batunov
{
  int** readMatrixFromFile(const std::string& filename, int& rows, int& cols);
}

#endif
