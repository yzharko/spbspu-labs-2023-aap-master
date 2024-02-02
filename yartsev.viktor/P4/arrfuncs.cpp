#include <fstream>
#include <stdexcept>
#include <iostream>
#include "arrfuncs.hpp"

void yartsev::readArray(int * matrix, int cols, int rows, std::ifstream & in)
{
  for (int i = 0; i < rows * cols; i++) {
    in >> matrix[i];
    if (!in) {
      throw std::logic_error("Wrong input");
    }
  }
}