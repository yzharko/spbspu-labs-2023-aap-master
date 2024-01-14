#ifndef READ_MATRIX_HPP
#define READ_MATRIX_HPP
#include <fstream>

namespace shagieva
{
  int readMatrix(std::ifstream & input, int * values, const int numberOfValues);
};

#endif
