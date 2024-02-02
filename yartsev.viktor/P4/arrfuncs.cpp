#include <fstream>
#include "arrfuncs.hpp"

int yartsev::readArray(int * matrix, int cols, int rows, std::ifstream & in)
{
  for (int i = 0; i < rows * cols; i++) {
    in >> matrix[i];
    if (!in) {
      return 2;
    }
  }
  return 0;
}