#include "matrix.hpp"
#include <iostream>

float* mihalchenko::createMatrix(float* rowsPtrs, size_t rows, size_t cols)
{
  try
  {
    rowsPtrs = new float[rows * cols];
    return rowsPtrs;
  }
  catch(const std::exception& e)
  {
    freeMatrix(rowsPtrs);
    std::cerr << e.what() << '\n';
    return nullptr;
  }
}

void mihalchenko::freeMatrix(float* matrix)
{
  if (!matrix)
  {
    std::cerr << "The matrix being deleted was not detected\n";
    delete[] matrix;
  }
  else
  {
    delete[] matrix;
  }
}
